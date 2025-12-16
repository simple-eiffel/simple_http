note
	description: "[
		Zero-configuration HTTP client facade for beginners.

		One-liner HTTP requests - no headers, timeouts, or config required.
		For full control, use SIMPLE_HTTP directly.

		Quick Start Examples:
			create http.make

			-- GET request
			html := http.get ("https://example.com")

			-- GET JSON
			if attached http.get_json ("https://api.example.com/users") as users then
				print (users.representation)
			end

			-- POST form data
			response := http.post ("https://api.example.com/login", "user=alice&pass=secret")

			-- POST JSON
			response := http.post_json ("https://api.example.com/users", json_data)

			-- Download file
			http.download ("https://example.com/file.zip", "C:\downloads\file.zip")
	]"
	author: "Larry Rix"
	date: "$Date$"
	revision: "$Revision$"

class
	SIMPLE_HTTP_QUICK

create
	make

feature {NONE} -- Initialization

	make
			-- Create quick HTTP client.
		do
			create client.make
			create logger.make ("http_quick")
		ensure
			client_exists: client /= Void
		end

feature -- Status

	has_error: BOOLEAN
			-- Did last request fail?
		do
			Result := last_status_code < 200 or last_status_code >= 400
		end

	last_status_code: INTEGER
			-- HTTP status code from last request (200, 404, 500, etc.).

	last_error: STRING
			-- Error message from last failed request.
		do
			if last_status_code >= 400 then
				Result := "HTTP " + last_status_code.out
				if attached client.last_response as resp and then attached resp.body as body then
					Result := Result + ": " + body
				end
			else
				Result := ""
			end
		ensure
			result_exists: Result /= Void
		end

feature -- GET Requests

	get (a_url: STRING): STRING
			-- GET URL and return response body as text.
			-- Returns empty string on error.
		require
			url_not_empty: not a_url.is_empty
		do
			logger.debug_log ("GET " + a_url)
			client.get (a_url)
			update_status
			if attached client.last_response as resp and then attached resp.body as body then
				Result := body
				logger.debug_log ("Response: " + last_status_code.out + " (" + body.count.out + " bytes)")
			else
				Result := ""
				logger.warn ("No response body")
			end
		ensure
			result_exists: Result /= Void
		end

	get_json (a_url: STRING): detachable SIMPLE_JSON_OBJECT
			-- GET URL and parse response as JSON object.
			-- Returns Void if request fails or response is not valid JSON.
		require
			url_not_empty: not a_url.is_empty
		local
			l_body: STRING
			l_json: SIMPLE_JSON
		do
			logger.debug_log ("GET JSON " + a_url)
			l_body := get (a_url)
			if not l_body.is_empty then
				create l_json
				if attached l_json.parse (l_body.to_string_32) as parsed and then attached parsed.as_object as obj then
					Result := obj
					logger.debug_log ("Parsed JSON object")
				else
					logger.warn ("Invalid JSON response")
				end
			end
		end

	get_json_array (a_url: STRING): detachable SIMPLE_JSON_ARRAY
			-- GET URL and parse response as JSON array.
		require
			url_not_empty: not a_url.is_empty
		local
			l_body: STRING
			l_json: SIMPLE_JSON
		do
			logger.debug_log ("GET JSON array " + a_url)
			l_body := get (a_url)
			if not l_body.is_empty then
				create l_json
				if attached l_json.parse (l_body.to_string_32) as parsed and then attached parsed.as_array as arr then
					Result := arr
					logger.debug_log ("Parsed JSON array with " + arr.count.out + " elements")
				else
					logger.warn ("Invalid JSON array response")
				end
			end
		end

feature -- POST Requests

	post (a_url: STRING; a_body: STRING): STRING
			-- POST body to URL and return response.
		require
			url_not_empty: not a_url.is_empty
		do
			logger.debug_log ("POST " + a_url + " (" + a_body.count.out + " bytes)")
			client.add_header ("Content-Type", "application/x-www-form-urlencoded")
			client.post (a_url, a_body)
			update_status
			if attached client.last_response as resp and then attached resp.body as body then
				Result := body
				logger.debug_log ("Response: " + last_status_code.out)
			else
				Result := ""
			end
		ensure
			result_exists: Result /= Void
		end

	post_json (a_url: STRING; a_json: SIMPLE_JSON_VALUE): STRING
			-- POST JSON to URL and return response.
		require
			url_not_empty: not a_url.is_empty
			json_not_void: a_json /= Void
		do
			logger.debug_log ("POST JSON " + a_url)
			client.add_header ("Content-Type", "application/json")
			client.post (a_url, a_json.to_json_string.to_string_8)
			update_status
			if attached client.last_response as resp and then attached resp.body as body then
				Result := body
				logger.debug_log ("Response: " + last_status_code.out)
			else
				Result := ""
			end
		ensure
			result_exists: Result /= Void
		end

	post_form (a_url: STRING; a_fields: ARRAY [TUPLE [name: STRING; value: STRING]]): STRING
			-- POST form fields to URL.
			-- Example: http.post_form ("https://...", <<["user", "alice"], ["pass", "secret"]>>)
		require
			url_not_empty: not a_url.is_empty
			has_fields: a_fields.count > 0
		local
			l_body: STRING
			l_first: BOOLEAN
		do
			create l_body.make_empty
			l_first := True
			across a_fields as field loop
				if not l_first then
					l_body.append ("&")
				end
				l_body.append (url_encode (field.name) + "=" + url_encode (field.value))
				l_first := False
			end
			Result := post (a_url, l_body)
		ensure
			result_exists: Result /= Void
		end

feature -- PUT/DELETE

	put (a_url: STRING; a_body: STRING): STRING
			-- PUT body to URL and return response.
		require
			url_not_empty: not a_url.is_empty
		do
			logger.debug_log ("PUT " + a_url)
			client.put (a_url, a_body)
			update_status
			if attached client.last_response as resp and then attached resp.body as body then
				Result := body
			else
				Result := ""
			end
		ensure
			result_exists: Result /= Void
		end

	delete (a_url: STRING): STRING
			-- DELETE resource at URL and return response.
		require
			url_not_empty: not a_url.is_empty
		do
			logger.debug_log ("DELETE " + a_url)
			client.delete (a_url)
			update_status
			if attached client.last_response as resp and then attached resp.body as body then
				Result := body
			else
				Result := ""
			end
		ensure
			result_exists: Result /= Void
		end

feature -- File Operations

	download (a_url: STRING; a_path: STRING): BOOLEAN
			-- Download file from URL to local path.
			-- Returns True on success.
		require
			url_not_empty: not a_url.is_empty
			path_not_empty: not a_path.is_empty
		local
			l_file: RAW_FILE
			l_content: STRING
		do
			logger.info ("Downloading " + a_url + " to " + a_path)
			l_content := get (a_url)
			if not has_error and not l_content.is_empty then
				create l_file.make_create_read_write (a_path)
				l_file.put_string (l_content)
				l_file.close
				Result := True
				logger.info ("Downloaded " + l_content.count.out + " bytes")
			else
				logger.error ("Download failed: " + last_error)
			end
		end

feature -- Configuration

	set_timeout (a_seconds: INTEGER)
			-- Set request timeout in seconds.
		require
			positive: a_seconds > 0
		do
			client.set_timeout (a_seconds)
		end

	add_header (a_name, a_value: STRING)
			-- Add custom header for subsequent requests.
		require
			name_not_empty: not a_name.is_empty
		do
			client.add_header (a_name, a_value)
		end

	set_bearer_token (a_token: STRING)
			-- Set Bearer authentication token.
		require
			token_not_empty: not a_token.is_empty
		do
			client.add_header ("Authorization", "Bearer " + a_token)
		end

	set_basic_auth (a_username, a_password: STRING)
			-- Set Basic authentication credentials.
		require
			username_not_empty: not a_username.is_empty
		local
			l_credentials: STRING
			l_base64: SIMPLE_BASE64
		do
			l_credentials := a_username + ":" + a_password
			create l_base64.make
			client.add_header ("Authorization", "Basic " + l_base64.encode (l_credentials))
		end

feature -- Advanced Access

	client: SIMPLE_HTTP
			-- Access underlying HTTP client for advanced operations.

feature {NONE} -- Implementation

	logger: SIMPLE_LOGGER
			-- Logger for debugging.

	update_status
			-- Update status from last response.
		do
			if attached client.last_response as resp then
				last_status_code := resp.status_code
			else
				last_status_code := 0
			end
		end

	url_encode (a_string: STRING): STRING
			-- URL-encode string for form data.
		local
			i: INTEGER
			c: CHARACTER
		do
			create Result.make (a_string.count)
			from i := 1 until i > a_string.count loop
				c := a_string.item (i)
				if c.is_alpha or c.is_digit or c = '-' or c = '_' or c = '.' or c = '~' then
					Result.append_character (c)
				elseif c = ' ' then
					Result.append_character ('+')
				else
					Result.append ("%%")
					Result.append (c.code.to_hex_string.substring (7, 8))
				end
				i := i + 1
			end
		ensure
			result_exists: Result /= Void
		end

invariant
	client_exists: client /= Void
	logger_exists: logger /= Void

end
