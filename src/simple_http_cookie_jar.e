note
	description: "Cookie storage and management for HTTP sessions"
	author: "Larry Rix"
	date: "$Date$"
	revision: "$Revision$"

class
	SIMPLE_HTTP_COOKIE_JAR

create
	make

feature {NONE} -- Initialization

	make
			-- Create empty cookie jar.
		do
			create cookies.make (10)
		end

feature -- Access

	count: INTEGER
			-- Number of cookies stored.
		do
			Result := cookies.count
		end

	is_empty: BOOLEAN
			-- Is the jar empty?
		do
			Result := cookies.is_empty
		end

	has_cookie (a_name: STRING): BOOLEAN
			-- Does a cookie with this name exist?
		require
			name_not_empty: not a_name.is_empty
		do
			Result := cookies.has (a_name)
		end

	cookie_value (a_name: STRING): detachable STRING
			-- Get cookie value by name.
		require
			name_not_empty: not a_name.is_empty
		do
			Result := cookies.item (a_name)
		end

	all_cookies: HASH_TABLE [STRING, STRING]
			-- Get all cookies (copy).
		local
			l_keys: ARRAY [STRING]
			i: INTEGER
		do
			create Result.make (cookies.count)
			l_keys := cookies.current_keys
			from i := l_keys.lower until i > l_keys.upper loop
				if attached cookies.item (l_keys.item (i)) as v then
					Result.force (v, l_keys.item (i))
				end
				i := i + 1
			end
		end

	cookie_header: STRING
			-- Build Cookie header value from stored cookies.
		local
			l_first: BOOLEAN
			l_keys: ARRAY [STRING]
			i: INTEGER
		do
			create Result.make (100)
			l_first := True
			l_keys := cookies.current_keys
			from i := l_keys.lower until i > l_keys.upper loop
				if not l_first then
					Result.append ("; ")
				end
				Result.append (l_keys.item (i))
				Result.append ("=")
				if attached cookies.item (l_keys.item (i)) as v then
					Result.append (v)
				end
				l_first := False
				i := i + 1
			end
		end

feature -- Element Change

	set_cookie (a_name, a_value: STRING)
			-- Set a cookie.
		require
			name_not_empty: not a_name.is_empty
		do
			cookies.force (a_value, a_name)
		ensure
			cookie_set: cookies.has (a_name)
		end

	remove_cookie (a_name: STRING)
			-- Remove a cookie.
		require
			name_not_empty: not a_name.is_empty
		do
			cookies.remove (a_name)
		ensure
			removed: not cookies.has (a_name)
		end

	clear
			-- Remove all cookies.
		do
			cookies.wipe_out
		ensure
			empty: cookies.is_empty
		end

	parse_set_cookie_header (a_header: STRING)
			-- Parse Set-Cookie header and store cookie.
			-- Format: name=value; other-attributes...
		local
			l_name: STRING
			l_value: STRING
			l_semicolon_pos: INTEGER
			l_equals_pos: INTEGER
			l_cookie_part: STRING
		do
			-- Get just the name=value part (before any semicolons)
			l_semicolon_pos := a_header.index_of (';', 1)
			if l_semicolon_pos > 0 then
				l_cookie_part := a_header.substring (1, l_semicolon_pos - 1)
			else
				l_cookie_part := a_header
			end

			-- Split on equals
			l_equals_pos := l_cookie_part.index_of ('=', 1)
			if l_equals_pos > 0 then
				l_name := l_cookie_part.substring (1, l_equals_pos - 1)
				l_name.left_adjust
				l_name.right_adjust
				if l_equals_pos < l_cookie_part.count then
					l_value := l_cookie_part.substring (l_equals_pos + 1, l_cookie_part.count)
					l_value.left_adjust
					l_value.right_adjust
				else
					l_value := ""
				end
				if not l_name.is_empty then
					set_cookie (l_name, l_value)
				end
			end
		end

	extract_cookies_from_response (a_response: SIMPLE_HTTP_RESPONSE)
			-- Extract and store cookies from response Set-Cookie headers.
		local
			l_header_value: detachable STRING
		do
			-- Check for Set-Cookie header
			l_header_value := a_response.header ("Set-Cookie")
			if attached l_header_value as h then
				parse_set_cookie_header (h)
			end
		end

feature {NONE} -- Implementation

	cookies: HASH_TABLE [STRING, STRING]
			-- Stored cookies (name -> value)

invariant
	cookies_not_void: cookies /= Void

note
	copyright: "Copyright (c) 2024-2025, Larry Rix"
	license: "MIT License"

end
