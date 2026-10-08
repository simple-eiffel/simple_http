note
	description: "[
		The URL rules SIMPLE_HTTP applies before a request leaves the
		process: how a URL looks on the request line, where a redirect's
		Location points, and whether two URLs share an origin.

		Pure functions over 8-bit text - no state, no I/O - so every rule
		is testable without a network.

		Why this exists (1.1.0): the transport (SIMPLE_WINHTTP) carries a
		URL verbatim and accepts printable ASCII only. A caller's URL may
		hold blanks, UTF-8 bytes or characters such as " < > | that are
		legal in a caller's hand but not on a request line. `wire_url'
		percent-encodes exactly those bytes and nothing else, so a URL
		that is already well-formed reaches the server byte-for-byte.
	]"
	author: "Larry Rix"

class
	SIMPLE_HTTP_WIRE

feature -- Status report

	is_web_url (a_url: READABLE_STRING_8): BOOLEAN
			-- Does `a_url' begin with http:// or https:// (any letter case)
			-- followed by at least one character?
		do
			Result := scheme_length (a_url) > 0 and then a_url.count > scheme_length (a_url)
		end

	is_on_wire (a_url: READABLE_STRING_8): BOOLEAN
			-- Can `a_url' travel verbatim: an http(s) URL of printable
			-- ASCII with no blank and no fragment?
		do
			Result := is_web_url (a_url) and then not a_url.has ('#')
			across
				a_url as ic
			loop
				Result := Result and ic.code >= 33 and ic.code <= 126
			end
		end

	same_origin (a_url, a_other: READABLE_STRING_8): BOOLEAN
			-- Do `a_url' and `a_other' name the same scheme, host and port?
		require
			web_url: is_web_url (a_url)
			other_web_url: is_web_url (a_other)
		do
			Result := origin (a_url).same_string (origin (a_other))
		end

feature -- Conversion

	wire_url (a_url: READABLE_STRING_8): STRING_8
			-- `a_url' as it travels on the request line: scheme in lower
			-- case, fragment dropped, an empty path made "/", and every
			-- byte of the path and query that a request line cannot carry
			-- verbatim percent-encoded - controls, blank, DEL, bytes
			-- 128..255 (the UTF-8 of non-ASCII text), the characters
			-- " < > \ ^ ` { | }, and any '%' that does not begin a %XX
			-- escape. Everything else, existing escapes included, is kept
			-- byte-for-byte, so the function is idempotent.
		require
			web_url: is_web_url (a_url)
		local
			l_url: STRING_8
			l_scheme_end, l_authority_end, i, n: INTEGER
			c: CHARACTER_8
		do
			create l_url.make_from_string (a_url)
			n := l_url.count
			l_scheme_end := scheme_length (l_url)
			create Result.make (n + 16)
			Result.append (l_url.substring (1, l_scheme_end).as_lower)
			from
				i := l_scheme_end + 1
			until
				i > n or else is_authority_end (l_url [i])
			loop
				i := i + 1
			end
			l_authority_end := i - 1
			Result.append (l_url.substring (l_scheme_end + 1, l_authority_end))
			if i > n or else l_url [i] /= '/' then
				Result.append_character ('/')
			end
			from
			until
				i > n or else l_url [i] = '#'
			loop
				c := l_url [i]
				if c = '%%' then
					if i + 2 <= n and then l_url [i + 1].is_hexa_digit and then l_url [i + 2].is_hexa_digit then
						Result.append_character (c)
					else
						Result.append ("%%25")
					end
				elseif needs_escape (c) then
					append_escape (Result, c)
				else
					Result.append_character (c)
				end
				i := i + 1
			end
		ensure
			still_web: is_web_url (Result)
			no_fragment: not Result.has ('#')
			origin_kept: Result.as_lower.starts_with (origin (a_url))
		end

	resolved_location (a_base, a_location: READABLE_STRING_8): STRING_8
			-- Where a redirect from `a_base' carrying Location `a_location'
			-- points, as a wire URL: absolute (http/https), scheme-relative
			-- ("//host/..."), absolute-path ("/..."), query-only ("?...")
			-- or path-relative ("next" - resolved against `a_base''s
			-- directory).
		require
			base_web_url: is_web_url (a_base)
			location_given: not a_location.is_empty
		local
			l_base, l_location, l_prefix: STRING_8
			l_cut: INTEGER
		do
			create l_location.make_from_string (a_location)
			l_location.left_adjust
			l_location.right_adjust
			l_base := wire_url (a_base)
			if is_web_url (l_location) then
				Result := wire_url (l_location)
			elseif l_location.starts_with ("//") then
				l_prefix := l_base.substring (1, scheme_length (l_base) - 2)
				Result := wire_url (l_prefix + l_location)
			elseif l_location.starts_with ("/") then
				Result := wire_url (origin (l_base) + l_location)
			elseif l_location.starts_with ("?") then
				l_cut := l_base.index_of ('?', 1)
				if l_cut > 0 then
					l_prefix := l_base.substring (1, l_cut - 1)
				else
					l_prefix := l_base
				end
				Result := wire_url (l_prefix + l_location)
			else
				l_cut := l_base.index_of ('?', 1)
				if l_cut > 0 then
					l_prefix := l_base.substring (1, l_cut - 1)
				else
					l_prefix := l_base
				end
					-- The directory: everything up to the last '/' of the
					-- path (the path of a wire URL always starts with '/').
				l_prefix := l_prefix.substring (1, l_prefix.last_index_of ('/', l_prefix.count))
				Result := wire_url (l_prefix + l_location)
			end
		ensure
			web_url: is_web_url (Result)
			no_fragment: not Result.has ('#')
		end

	origin (a_url: READABLE_STRING_8): STRING_8
			-- "scheme://authority" of `a_url', in lower case.
		require
			web_url: is_web_url (a_url)
		local
			l_url: STRING_8
			i: INTEGER
		do
			create l_url.make_from_string (a_url)
			from
				i := scheme_length (l_url) + 1
			until
				i > l_url.count or else is_authority_end (l_url [i])
			loop
				i := i + 1
			end
			Result := l_url.substring (1, i - 1).as_lower
		ensure
			web_url: is_web_url (Result)
			lower_case: Result.same_string (Result.as_lower)
		end

feature {NONE} -- Implementation

	scheme_length (a_url: READABLE_STRING_8): INTEGER
			-- 7 when `a_url' starts with "http://", 8 for "https://" (any
			-- letter case), 0 otherwise.
		local
			l_url: STRING_8
		do
			create l_url.make_from_string (a_url)
			if l_url.count >= 7 and then l_url.substring (1, 7).is_case_insensitive_equal ("http://") then
				Result := 7
			elseif l_url.count >= 8 and then l_url.substring (1, 8).is_case_insensitive_equal ("https://") then
				Result := 8
			end
		ensure
			known: Result = 0 or Result = 7 or Result = 8
		end

	is_authority_end (c: CHARACTER_8): BOOLEAN
			-- Does `c' end the authority part of a URL?
		do
			Result := c = '/' or c = '?' or c = '#'
		end

	needs_escape (c: CHARACTER_8): BOOLEAN
			-- Must `c' be percent-encoded to travel on a request line?
		do
			Result := c.code <= 32 or c.code >= 127 or Unsafe_characters.has (c)
		end

	append_escape (a_target: STRING_8; c: CHARACTER_8)
			-- Append "%XX" (upper-case hex) for `c' to `a_target'.
		do
			a_target.append_character ('%%')
			a_target.append_character (Hex_digits [c.code // 16 + 1])
			a_target.append_character (Hex_digits [c.code \\ 16 + 1])
		ensure
			three_more: a_target.count = old a_target.count + 3
		end

	Unsafe_characters: STRING_8 = "%"<>\^`{|}"
			-- Printable ASCII that a request line must not carry verbatim.

	Hex_digits: STRING_8 = "0123456789ABCDEF"
			-- Upper-case hexadecimal digits.

end
