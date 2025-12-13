note
	description: "Simple HTTP response wrapper with JSON parsing"
	author: "Larry Rix"
	date: "$Date$"
	revision: "$Revision$"

class
	SIMPLE_HTTP_RESPONSE

create
	make_from_response

feature {NONE} -- Initialization

	make_from_response (a_response: HTTP_CLIENT_RESPONSE)
			-- Create from raw HTTP response.
		do
			status := a_response.status
			body := a_response.body
			raw_header := a_response.raw_header
			error_occurred := a_response.error_occurred
			error_message := a_response.error_message
			create headers.make (10)
			parse_headers
		end

feature -- Access

	status: INTEGER
			-- HTTP status code

	body: detachable READABLE_STRING_8
			-- Response body

	raw_header: READABLE_STRING_8
			-- Raw HTTP headers

	error_message: detachable READABLE_STRING_8
			-- Error message if any

	headers: HASH_TABLE [STRING, STRING]
			-- Parsed headers

feature -- Header access

	header (a_name: STRING): detachable STRING
			-- Get header value by name (case-insensitive).
		local
			l_lower: STRING
		do
			l_lower := a_name.as_lower
			if headers.has (l_lower) then
				Result := headers.item (l_lower)
			end
		end

	content_type: detachable STRING
			-- Content-Type header value.
		do
			Result := header ("content-type")
		end

	content_length: INTEGER
			-- Content-Length header value (0 if not present).
		do
			if attached header ("content-length") as l_len then
				if l_len.is_integer then
					Result := l_len.to_integer
				end
			end
		end

feature -- Status report

	is_success: BOOLEAN
			-- Is status code in 2xx range?
		do
			Result := status >= 200 and status < 300
		end

	is_redirect: BOOLEAN
			-- Is status code in 3xx range?
		do
			Result := status >= 300 and status < 400
		end

	is_client_error: BOOLEAN
			-- Is status code in 4xx range?
		do
			Result := status >= 400 and status < 500
		end

	is_server_error: BOOLEAN
			-- Is status code in 5xx range?
		do
			Result := status >= 500 and status < 600
		end

	has_error: BOOLEAN
			-- Did an error occur?
		do
			Result := error_occurred
		end

	error_occurred: BOOLEAN
			-- Was there a transport error?

	is_json_content: BOOLEAN
			-- Does Content-Type indicate JSON?
		do
			if attached content_type as ct then
				Result := ct.has_substring ("application/json") or ct.has_substring ("+json")
			end
		end

feature -- Output

	body_string: STRING
			-- Body as STRING (empty if no body).
		do
			if attached body as b then
				Result := b.to_string_8
			else
				create Result.make_empty
			end
		end

feature -- JSON access

	json: detachable SIMPLE_JSON_VALUE
			-- Parse body as JSON (cached).
			-- Returns Void if body is empty or not valid JSON.
		local
			l_parser: SIMPLE_JSON
		do
			if not json_parsed then
				if attached body as b and then not b.is_empty then
					create l_parser
					cached_json := l_parser.decode_payload (b.to_string_32)
				end
				json_parsed := True
			end
			Result := cached_json
		end

	json_object: detachable SIMPLE_JSON_OBJECT
			-- Parse body as JSON object.
			-- Returns Void if not a valid JSON object.
		do
			if attached json as j and then j.is_object then
				Result := j.as_object
			end
		end

	json_array: detachable SIMPLE_JSON_ARRAY
			-- Parse body as JSON array.
			-- Returns Void if not a valid JSON array.
		do
			if attached json as j and then j.is_array then
				Result := j.as_array
			end
		end

	json_string (a_key: STRING): detachable STRING
			-- Get string value from JSON object by key.
		require
			key_not_empty: not a_key.is_empty
		do
			if attached json_object as obj then
				if attached obj.item (a_key.to_string_32) as v and then v.is_string then
					Result := v.as_string_32.to_string_8
				end
			end
		end

	json_integer (a_key: STRING): INTEGER
			-- Get integer value from JSON object by key (0 if not found).
		require
			key_not_empty: not a_key.is_empty
		do
			if attached json_object as obj then
				if attached obj.item (a_key.to_string_32) as v and then v.is_number then
					Result := v.as_integer.to_integer_32
				end
			end
		end

	json_boolean (a_key: STRING): BOOLEAN
			-- Get boolean value from JSON object by key (False if not found).
		require
			key_not_empty: not a_key.is_empty
		do
			if attached json_object as obj then
				if attached obj.item (a_key.to_string_32) as v and then v.is_boolean then
					Result := v.as_boolean
				end
			end
		end

	json_has_key (a_key: STRING): BOOLEAN
			-- Does JSON object have the given key?
		require
			key_not_empty: not a_key.is_empty
		do
			if attached json_object as obj then
				Result := obj.has_key (a_key.to_string_32)
			end
		end

feature {NONE} -- Implementation

	json_parsed: BOOLEAN
			-- Has JSON been parsed?

	cached_json: detachable SIMPLE_JSON_VALUE
			-- Cached parsed JSON

	parse_headers
			-- Parse raw_header into headers table.
		local
			l_pos, l_start, l_end, l_colon: INTEGER
			l_line, l_key, l_val: STRING
			n: INTEGER
		do
			n := raw_header.count
			from
				l_pos := 1
			until
				l_pos > n
			loop
				-- Find end of line
				l_start := l_pos
				l_end := raw_header.index_of ('%N', l_pos)
				if l_end = 0 then
					l_end := n + 1
				end

				-- Extract line (trim trailing CR if present)
				if l_end > l_start then
					if l_end > 1 and then raw_header.item (l_end - 1) = '%R' then
						l_line := raw_header.substring (l_start, l_end - 2)
					else
						l_line := raw_header.substring (l_start, l_end - 1)
					end

					-- Parse header line
					l_colon := l_line.index_of (':', 1)
					if l_colon > 1 then
						l_key := l_line.substring (1, l_colon - 1)
						l_key.to_lower
						l_key.right_adjust
						l_key.left_adjust
						if l_colon < l_line.count then
							l_val := l_line.substring (l_colon + 1, l_line.count)
							l_val.right_adjust
							l_val.left_adjust
						else
							create l_val.make_empty
						end
						headers.force (l_val, l_key)
					end
				end

				l_pos := l_end + 1
			end
		end

note
	copyright: "Copyright (c) 2024-2025, Larry Rix"
	license: "MIT License"

end
