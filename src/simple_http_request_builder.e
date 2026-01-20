note
	description: "Fluent request builder for SIMPLE_HTTP"
	author: "Larry Rix"
	date: "$Date$"
	revision: "$Revision$"

class
	SIMPLE_HTTP_REQUEST_BUILDER

create
	make

feature {NONE} -- Initialization

	make (a_client: SIMPLE_HTTP)
			-- Create request builder with parent client.
		require
			client_not_void: a_client /= Void
		do
			client := a_client
			create request_url.make_empty
			request_method := "GET"
			create request_headers.make (5)
			create request_queries.make (5)
			request_timeout := -1 -- Use client default
			request_connect_timeout := -1 -- Use client default
			request_max_retries := -1 -- Use client default
			request_follow_redirects := True
		ensure
			client_set: client = a_client
		end

feature -- Configuration

	url (a_url: STRING): like Current
			-- Set the request URL.
		require
			url_not_empty: not a_url.is_empty
		do
			request_url := a_url
			Result := Current
		ensure
			url_set: request_url.same_string (a_url)
		end

	method (a_method: STRING): like Current
			-- Set the HTTP method.
		require
			method_not_empty: not a_method.is_empty
		do
			request_method := a_method.as_upper
			Result := Current
		ensure
			method_set: request_method.same_string (a_method.as_upper)
		end

	get_method: like Current
			-- Set method to GET.
		do
			request_method := "GET"
			Result := Current
		end

	post_method: like Current
			-- Set method to POST.
		do
			request_method := "POST"
			Result := Current
		end

	put_method: like Current
			-- Set method to PUT.
		do
			request_method := "PUT"
			Result := Current
		end

	delete_method: like Current
			-- Set method to DELETE.
		do
			request_method := "DELETE"
			Result := Current
		end

	patch_method: like Current
			-- Set method to PATCH.
		do
			request_method := "PATCH"
			Result := Current
		end

	head_method: like Current
			-- Set method to HEAD.
		do
			request_method := "HEAD"
			Result := Current
		end

feature -- Headers

	header (a_name, a_value: STRING): like Current
			-- Add a custom header.
		require
			name_not_empty: not a_name.is_empty
			value_not_empty: not a_value.is_empty
		do
			request_headers.force (a_value, a_name)
			Result := Current
		ensure
			header_set: request_headers.has (a_name)
		end

	accept (a_content_type: STRING): like Current
			-- Set Accept header.
		require
			content_type_not_empty: not a_content_type.is_empty
		do
			Result := header ("Accept", a_content_type)
		end

	accept_json: like Current
			-- Set Accept header to application/json.
		do
			Result := header ("Accept", "application/json")
		end

	content_type (a_type: STRING): like Current
			-- Set Content-Type header.
		require
			type_not_empty: not a_type.is_empty
		do
			Result := header ("Content-Type", a_type)
		end

	content_type_json: like Current
			-- Set Content-Type header to application/json.
		do
			Result := header ("Content-Type", "application/json")
		end

	content_type_form: like Current
			-- Set Content-Type header to application/x-www-form-urlencoded.
		do
			Result := header ("Content-Type", "application/x-www-form-urlencoded")
		end

feature -- Authentication

	bearer_token (a_token: STRING): like Current
			-- Set Authorization header with Bearer token.
		require
			token_not_empty: not a_token.is_empty
		do
			Result := header ("Authorization", "Bearer " + a_token)
		end

	basic_auth (a_username, a_password: STRING): like Current
			-- Set Authorization header with Basic authentication.
		require
			username_not_empty: not a_username.is_empty
		local
			l_credentials: STRING
			l_base64: SIMPLE_BASE64
		do
			l_credentials := a_username + ":" + a_password
			create l_base64.make
			Result := header ("Authorization", "Basic " + l_base64.encode (l_credentials))
		end

	api_key (a_header_name, a_key: STRING): like Current
			-- Set API key in specified header.
		require
			header_name_not_empty: not a_header_name.is_empty
			key_not_empty: not a_key.is_empty
		do
			Result := header (a_header_name, a_key)
		end

	auth_header (a_value: STRING): like Current
			-- Set Authorization header directly.
		require
			value_not_empty: not a_value.is_empty
		do
			Result := header ("Authorization", a_value)
		end

feature -- Query Parameters

	query (a_name, a_value: STRING): like Current
			-- Add a query parameter.
		require
			name_not_empty: not a_name.is_empty
		do
			request_queries.force (a_value, a_name)
			Result := Current
		ensure
			query_set: request_queries.has (a_name)
		end

	queries (a_params: HASH_TABLE [STRING, STRING]): like Current
			-- Set multiple query parameters.
		require
			params_not_void: a_params /= Void
		local
			l_keys: ARRAY [STRING]
			i: INTEGER
		do
			l_keys := a_params.current_keys
			from i := l_keys.lower until i > l_keys.upper loop
				if attached a_params.item (l_keys.item (i)) as v then
					request_queries.force (v, l_keys.item (i))
				end
				i := i + 1
			end
			Result := Current
		end

feature -- Body

	body (a_body: STRING): like Current
			-- Set the request body.
		require
			body_not_void: not a_body.is_empty
		do
			request_body := a_body
			Result := Current
		ensure
			body_set: request_body ~ a_body
		end

	json_body (a_json: SIMPLE_JSON_OBJECT): like Current
			-- Set the request body as JSON.
		require
			json_not_void: a_json /= Void
		do
			request_body := a_json.json_value.representation
			request_headers.force ("application/json", "Content-Type")
			Result := Current
		end

	form_body (a_fields: HASH_TABLE [STRING, STRING]): like Current
			-- Set the request body as form-encoded data.
		require
			fields_not_void: a_fields /= Void
		local
			l_builder: STRING
			l_first: BOOLEAN
			l_keys: ARRAY [STRING]
			i: INTEGER
		do
			create l_builder.make (100)
			l_first := True
			l_keys := a_fields.current_keys
			from i := l_keys.lower until i > l_keys.upper loop
				if not l_first then
					l_builder.append_character ('&')
				end
				l_builder.append (url_encode (l_keys.item (i)))
				l_builder.append_character ('=')
				if attached a_fields.item (l_keys.item (i)) as v then
					l_builder.append (url_encode (v))
				end
				l_first := False
				i := i + 1
			end
			request_body := l_builder
			request_headers.force ("application/x-www-form-urlencoded", "Content-Type")
			Result := Current
		end

feature -- Timeouts

	timeout (a_seconds: INTEGER): like Current
			-- Set request timeout in seconds.
		require
			non_negative: a_seconds >= 0
		do
			request_timeout := a_seconds
			Result := Current
		ensure
			timeout_set: request_timeout = a_seconds
		end

	connect_timeout (a_seconds: INTEGER): like Current
			-- Set connection timeout in seconds.
		require
			non_negative: a_seconds >= 0
		do
			request_connect_timeout := a_seconds
			Result := Current
		ensure
			connect_timeout_set: request_connect_timeout = a_seconds
		end

feature -- Retry

	retry_count (a_max: INTEGER): like Current
			-- Set maximum number of retries for this request.
		require
			non_negative: a_max >= 0
		do
			request_max_retries := a_max
			Result := Current
		ensure
			retries_set: request_max_retries = a_max
		end

	no_retry: like Current
			-- Disable retry for this request.
		do
			request_max_retries := 0
			Result := Current
		ensure
			no_retries: request_max_retries = 0
		end

feature -- Redirects

	follow_redirects (a_follow: BOOLEAN): like Current
			-- Set whether to follow redirects.
		do
			request_follow_redirects := a_follow
			Result := Current
		ensure
			follow_set: request_follow_redirects = a_follow
		end

	no_redirects: like Current
			-- Don't follow redirects for this request.
		do
			request_follow_redirects := False
			Result := Current
		ensure
			no_follow: not request_follow_redirects
		end

feature -- Status

	has_url: BOOLEAN
			-- Has a URL been set?
		do
			Result := not request_url.is_empty
		end

feature -- Execution

	execute: SIMPLE_HTTP_RESPONSE
			-- Execute the request and return response.
		require
			url_set: has_url
		local
			l_saved_timeout: INTEGER
			l_saved_connect_timeout: INTEGER
			l_saved_follow_redirects: BOOLEAN
			l_keys: ARRAY [STRING]
			i: INTEGER
		do
			-- Save current client settings
			l_saved_timeout := client.timeout
			l_saved_connect_timeout := client.connect_timeout
			l_saved_follow_redirects := client.follow_redirects

			-- Apply request-specific settings
			if request_timeout >= 0 then
				client.set_timeout (request_timeout)
			end
			if request_connect_timeout >= 0 then
				client.set_connect_timeout (request_connect_timeout)
			end
			client.set_follow_redirects (request_follow_redirects)

			-- Save and set request-specific headers
			l_keys := request_headers.current_keys
			from i := l_keys.lower until i > l_keys.upper loop
				if attached request_headers.item (l_keys.item (i)) as v then
					client.add_header (l_keys.item (i), v)
				end
				i := i + 1
			end

			-- Save and set request-specific query params
			l_keys := request_queries.current_keys
			from i := l_keys.lower until i > l_keys.upper loop
				if attached request_queries.item (l_keys.item (i)) as v then
					client.add_query (l_keys.item (i), v)
				end
				i := i + 1
			end

			-- Execute based on method
			if request_method.is_case_insensitive_equal ("GET") then
				Result := client.get (request_url)
			elseif request_method.is_case_insensitive_equal ("POST") then
				Result := client.post (request_url, request_body)
			elseif request_method.is_case_insensitive_equal ("PUT") then
				Result := client.put (request_url, request_body)
			elseif request_method.is_case_insensitive_equal ("DELETE") then
				Result := client.delete (request_url)
			elseif request_method.is_case_insensitive_equal ("HEAD") then
				Result := client.head (request_url)
			elseif request_method.is_case_insensitive_equal ("PATCH") then
				Result := client.patch (request_url, request_body)
			else
				-- Default to GET
				Result := client.get (request_url)
			end

			-- Restore client settings
			client.set_timeout (l_saved_timeout)
			client.set_connect_timeout (l_saved_connect_timeout)
			client.set_follow_redirects (l_saved_follow_redirects)

			-- Clear request-specific headers and queries from client
			client.clear_headers
			client.clear_queries
		end

feature {NONE} -- Implementation

	client: SIMPLE_HTTP
			-- Parent HTTP client

	request_url: STRING
			-- Request URL

	request_method: STRING
			-- HTTP method

	request_headers: HASH_TABLE [STRING, STRING]
			-- Request-specific headers

	request_queries: HASH_TABLE [STRING, STRING]
			-- Request-specific query parameters

	request_body: detachable STRING
			-- Request body

	request_timeout: INTEGER
			-- Request-specific timeout (-1 = use client default)

	request_connect_timeout: INTEGER
			-- Request-specific connect timeout (-1 = use client default)

	request_max_retries: INTEGER
			-- Request-specific max retries (-1 = use client default)

	request_follow_redirects: BOOLEAN
			-- Follow redirects for this request?

	url_encode (a_string: STRING): STRING
			-- URL-encode a string using SIMPLE_ZSTRING_ESCAPER.
		local
			l_escaper: SIMPLE_ZSTRING_ESCAPER
		do
			create l_escaper
			Result := l_escaper.url_encode (a_string)
		end

invariant
	client_not_void: client /= Void
	method_not_empty: not request_method.is_empty

note
	copyright: "Copyright (c) 2024-2025, Larry Rix"
	license: "MIT License"

end
