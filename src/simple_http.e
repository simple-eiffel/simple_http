note
	description: "Simple HTTP client for making web requests"
	author: "Larry Rix"
	date: "$Date$"
	revision: "$Revision$"

class
	SIMPLE_HTTP

create
	make

feature {NONE} -- Initialization

	make
			-- Create HTTP client.
		do
			create client
			create custom_headers.make (5)
			create query_params.make (5)
			create interceptors.make (3)
			timeout := Default_timeout_seconds
			connect_timeout := Default_connect_timeout_seconds
			max_redirects := Default_max_redirects
			follow_redirects := True
			create retry_policy.make_none
			cookies_enabled := False
		end

feature -- Access

	timeout: INTEGER
			-- Request timeout in seconds

	connect_timeout: INTEGER
			-- Connection timeout in seconds

	max_redirects: INTEGER
			-- Maximum number of redirects to follow (default 10)

	follow_redirects: BOOLEAN
			-- Should redirects be followed? (default True)

	retry_policy: SIMPLE_HTTP_RETRY_POLICY
			-- Current retry policy

	last_response: detachable SIMPLE_HTTP_RESPONSE
			-- Last response received

	retry_count: INTEGER
			-- Number of retries performed on last request

feature -- Settings

	set_timeout (a_seconds: INTEGER)
			-- Set request timeout.
		require
			non_negative: a_seconds >= 0
		do
			timeout := a_seconds
		ensure
			set: timeout = a_seconds
		end

	set_connect_timeout (a_seconds: INTEGER)
			-- Set connection timeout.
		require
			non_negative: a_seconds >= 0
		do
			connect_timeout := a_seconds
		ensure
			set: connect_timeout = a_seconds
		end

feature -- Redirect Settings

	set_max_redirects (a_count: INTEGER)
			-- Set maximum number of redirects to follow.
			-- Set to 0 to disable redirect following.
		require
			non_negative: a_count >= 0
		do
			max_redirects := a_count
			follow_redirects := a_count > 0
		ensure
			set: max_redirects = a_count
			disabled_if_zero: a_count = 0 implies not follow_redirects
		end

	set_follow_redirects (a_value: BOOLEAN)
			-- Enable or disable redirect following.
		do
			follow_redirects := a_value
		ensure
			set: follow_redirects = a_value
		end

feature -- Retry Settings

	set_retry_policy (a_policy: SIMPLE_HTTP_RETRY_POLICY)
			-- Set the retry policy.
		require
			policy_not_void: a_policy /= Void
		do
			retry_policy := a_policy
		ensure
			set: retry_policy = a_policy
		end

	enable_retry
			-- Enable default retry policy (3 retries, exponential backoff).
		do
			create retry_policy.make_default
		end

	enable_retry_custom (a_max_retries: INTEGER)
			-- Enable retry with custom max attempts.
		require
			positive: a_max_retries > 0
		do
			create retry_policy.make_custom (a_max_retries, Default_initial_delay_ms, Default_max_delay_ms, True)
		end

	disable_retry
			-- Disable retry (no automatic retries).
		do
			create retry_policy.make_none
		ensure
			disabled: retry_policy.max_retries = 0
		end

feature -- Header management

	add_header (a_name, a_value: STRING)
			-- Add custom header to all subsequent requests.
		require
			name_not_empty: not a_name.is_empty
			value_not_empty: not a_value.is_empty
		do
			custom_headers.force (a_value, a_name)
		ensure
			header_set: custom_headers.has (a_name)
		end

	set_headers (a_headers: HASH_TABLE [STRING, STRING])
			-- Set multiple headers at once.
		require
			headers_not_void: a_headers /= Void
		local
			l_keys: ARRAY [STRING]
			l_i: INTEGER
		do
			l_keys := a_headers.current_keys
			from l_i := l_keys.lower until l_i > l_keys.upper loop
				if attached a_headers.item (l_keys.item (l_i)) as v then
					custom_headers.force (v, l_keys.item (l_i))
				end
				l_i := l_i + 1
			end
		end

	remove_header (a_name: STRING)
			-- Remove a custom header.
		require
			name_not_empty: not a_name.is_empty
		do
			custom_headers.remove (a_name)
		ensure
			removed: not custom_headers.has (a_name)
		end

	clear_headers
			-- Remove all custom headers.
		do
			custom_headers.wipe_out
		ensure
			empty: custom_headers.is_empty
		end

feature -- Authentication

	set_bearer_token (a_token: STRING)
			-- Set Authorization header with Bearer token.
		require
			token_not_empty: not a_token.is_empty
		do
			add_header ("Authorization", "Bearer " + a_token)
		end

	set_basic_auth (a_username, a_password: STRING)
			-- Set Authorization header with Basic authentication.
		require
			username_not_empty: not a_username.is_empty
		local
			l_credentials: STRING
			l_base64: SIMPLE_BASE64
		do
			l_credentials := a_username + ":" + a_password
			create l_base64.make
			add_header ("Authorization", "Basic " + l_base64.encode (l_credentials))
		end

	set_auth_header (a_value: STRING)
			-- Set Authorization header directly.
		require
			value_not_empty: not a_value.is_empty
		do
			add_header ("Authorization", a_value)
		end

	set_api_key (a_header_name, a_key: STRING)
			-- Set API key in specified header.
		require
			header_name_not_empty: not a_header_name.is_empty
			key_not_empty: not a_key.is_empty
		do
			add_header (a_header_name, a_key)
		end

feature -- Query parameters

	add_query (a_name, a_value: STRING)
			-- Add query parameter to all subsequent requests.
		require
			name_not_empty: not a_name.is_empty
		do
			query_params.force (a_value, a_name)
		ensure
			param_set: query_params.has (a_name)
		end

	set_queries (a_params: HASH_TABLE [STRING, STRING])
			-- Set multiple query parameters at once.
		require
			params_not_void: a_params /= Void
		local
			l_keys: ARRAY [STRING]
			l_i: INTEGER
		do
			l_keys := a_params.current_keys
			from l_i := l_keys.lower until l_i > l_keys.upper loop
				if attached a_params.item (l_keys.item (l_i)) as v then
					query_params.force (v, l_keys.item (l_i))
				end
				l_i := l_i + 1
			end
		end

	remove_query (a_name: STRING)
			-- Remove a query parameter.
		require
			name_not_empty: not a_name.is_empty
		do
			query_params.remove (a_name)
		ensure
			removed: not query_params.has (a_name)
		end

	clear_queries
			-- Remove all query parameters.
		do
			query_params.wipe_out
		ensure
			empty: query_params.is_empty
		end

feature -- Content type helpers

	set_accept_json
			-- Set Accept header to application/json.
		do
			add_header ("Accept", "application/json")
		end

	set_content_type_json
			-- Set Content-Type header to application/json.
		do
			add_header ("Content-Type", "application/json")
		end

	set_content_type_form
			-- Set Content-Type header to application/x-www-form-urlencoded.
		do
			add_header ("Content-Type", "application/x-www-form-urlencoded")
		end

feature -- Basic operations

	get (a_url: STRING): SIMPLE_HTTP_RESPONSE
			-- Perform GET request with retry support.
		require
			url_not_empty: not a_url.is_empty
		do
			Result := execute_with_retry (a_url, "GET", Void, True)
		end

	post (a_url: STRING; a_data: detachable STRING): SIMPLE_HTTP_RESPONSE
			-- Perform POST request with optional data.
			-- Note: POST is not retried by default (non-idempotent).
		require
			url_not_empty: not a_url.is_empty
		do
			Result := execute_with_retry (a_url, "POST", a_data, False)
		end

	post_json (a_url: STRING; a_json: SIMPLE_JSON_OBJECT): SIMPLE_HTTP_RESPONSE
			-- Perform POST request with JSON body.
		require
			url_not_empty: not a_url.is_empty
			json_not_void: a_json /= Void
		do
			set_content_type_json
			Result := post (a_url, a_json.json_value.representation)
		end

	put (a_url: STRING; a_data: detachable STRING): SIMPLE_HTTP_RESPONSE
			-- Perform PUT request with optional data and retry support.
		require
			url_not_empty: not a_url.is_empty
		do
			Result := execute_with_retry (a_url, "PUT", a_data, True)
		end

	put_json (a_url: STRING; a_json: SIMPLE_JSON_OBJECT): SIMPLE_HTTP_RESPONSE
			-- Perform PUT request with JSON body.
		require
			url_not_empty: not a_url.is_empty
			json_not_void: a_json /= Void
		do
			set_content_type_json
			Result := put (a_url, a_json.json_value.representation)
		end

	delete (a_url: STRING): SIMPLE_HTTP_RESPONSE
			-- Perform DELETE request with retry support.
		require
			url_not_empty: not a_url.is_empty
		do
			Result := execute_with_retry (a_url, "DELETE", Void, True)
		end

	head (a_url: STRING): SIMPLE_HTTP_RESPONSE
			-- Perform HEAD request with retry support.
		require
			url_not_empty: not a_url.is_empty
		do
			Result := execute_with_retry (a_url, "HEAD", Void, True)
		end

	patch (a_url: STRING; a_data: detachable STRING): SIMPLE_HTTP_RESPONSE
			-- Perform PATCH request with optional data and retry support.
		require
			url_not_empty: not a_url.is_empty
		do
			Result := execute_with_retry (a_url, "PATCH", a_data, True)
		end

	patch_json (a_url: STRING; a_json: SIMPLE_JSON_OBJECT): SIMPLE_HTTP_RESPONSE
			-- Perform PATCH request with JSON body.
		require
			url_not_empty: not a_url.is_empty
			json_not_void: a_json /= Void
		do
			set_content_type_json
			Result := patch (a_url, a_json.json_value.representation)
		end

feature -- Status report

	is_success: BOOLEAN
			-- Was last request successful (2xx status)?
		do
			if attached last_response as r then
				Result := r.is_success
			end
		end

	has_error: BOOLEAN
			-- Did last request encounter an error?
		do
			if attached last_response as r then
				Result := r.has_error
			end
		end

feature -- Request Builder

	request: SIMPLE_HTTP_REQUEST_BUILDER
			-- Create a new fluent request builder.
		do
			create Result.make (Current)
		end

feature -- Interceptors

	add_interceptor (a_interceptor: SIMPLE_HTTP_INTERCEPTOR)
			-- Add an interceptor to the chain.
		require
			interceptor_not_void: a_interceptor /= Void
		do
			interceptors.extend (a_interceptor)
		ensure
			added: interceptors.has (a_interceptor)
		end

	remove_interceptor (a_interceptor: SIMPLE_HTTP_INTERCEPTOR)
			-- Remove an interceptor from the chain.
		require
			interceptor_not_void: a_interceptor /= Void
		do
			interceptors.prune (a_interceptor)
		ensure
			removed: not interceptors.has (a_interceptor)
		end

	clear_interceptors
			-- Remove all interceptors.
		do
			interceptors.wipe_out
		ensure
			empty: interceptors.is_empty
		end

feature -- Cookie Management

	cookies_enabled: BOOLEAN
			-- Is automatic cookie management enabled?

	enable_cookies
			-- Enable automatic cookie handling.
		do
			cookies_enabled := True
			if not attached cookie_jar then
				create cookie_jar.make
			end
		ensure
			enabled: cookies_enabled
		end

	disable_cookies
			-- Disable automatic cookie handling.
		do
			cookies_enabled := False
		ensure
			disabled: not cookies_enabled
		end

	clear_cookies
			-- Clear all stored cookies.
		do
			if attached cookie_jar as cj then
				cj.clear
			end
		end

	set_cookie (a_name, a_value: STRING)
			-- Manually set a cookie.
		require
			name_not_empty: not a_name.is_empty
			cookies_enabled: cookies_enabled
		do
			if attached cookie_jar as cj then
				cj.set_cookie (a_name, a_value)
			end
		end

	get_cookie (a_name: STRING): detachable STRING
			-- Get a cookie value by name.
		require
			name_not_empty: not a_name.is_empty
		do
			if attached cookie_jar as cj then
				Result := cj.cookie_value (a_name)
			end
		end

feature {NONE} -- Implementation

	client: NET_HTTP_CLIENT
			-- Underlying HTTP client

	custom_headers: HASH_TABLE [STRING, STRING]
			-- Custom headers to send with requests

	query_params: HASH_TABLE [STRING, STRING]
			-- Query parameters to append to URLs

	interceptors: ARRAYED_LIST [SIMPLE_HTTP_INTERCEPTOR]
			-- Registered interceptors

	cookie_jar: detachable SIMPLE_HTTP_COOKIE_JAR
			-- Cookie storage (created on demand)

	configure_session (a_session: NET_HTTP_CLIENT_SESSION)
			-- Configure session with current settings.
		local
			l_keys: ARRAY [STRING]
			l_i: INTEGER
		do
			a_session.set_timeout (timeout)
			a_session.set_connect_timeout (connect_timeout)
			-- Apply custom headers
			l_keys := custom_headers.current_keys
			from l_i := l_keys.lower until l_i > l_keys.upper loop
				if attached custom_headers.item (l_keys.item (l_i)) as v then
					a_session.add_header (l_keys.item (l_i), v)
				end
				l_i := l_i + 1
			end
		end

	build_url (a_url: STRING): STRING
			-- Build full URL with query parameters.
		local
			l_first: BOOLEAN
			l_keys: ARRAY [STRING]
			l_i: INTEGER
		do
			if query_params.is_empty then
				Result := a_url
			else
				create Result.make_from_string (a_url)
				if a_url.has ('?') then
					l_first := False
				else
					Result.append_character ('?')
					l_first := True
				end
				l_keys := query_params.current_keys
				from l_i := l_keys.lower until l_i > l_keys.upper loop
					if not l_first then
						Result.append_character ('&')
					end
					Result.append (url_encode (l_keys.item (l_i)))
					Result.append_character ('=')
					if attached query_params.item (l_keys.item (l_i)) as v then
						Result.append (url_encode (v))
					end
					l_first := False
					l_i := l_i + 1
				end
			end
		end

	url_encode (a_string: STRING): STRING
			-- URL-encode a string using SIMPLE_ZSTRING_ESCAPER.
		local
			l_escaper: SIMPLE_ZSTRING_ESCAPER
		do
			create l_escaper
			Result := l_escaper.url_encode (a_string)
		end

	execute_with_retry (a_url, a_method: STRING; a_data: detachable STRING; a_is_idempotent: BOOLEAN): SIMPLE_HTTP_RESPONSE
			-- Execute HTTP request with retry support.
			-- `a_is_idempotent`: If True, request will be retried on transient errors.
		local
			l_attempt: INTEGER
			l_should_retry: BOOLEAN
			l_delay_ms: INTEGER
			l_env: EXECUTION_ENVIRONMENT
		do
			retry_count := 0
			l_attempt := 1

			-- Execute first attempt
			Result := execute_single_request (a_url, a_method, a_data)
			last_response := Result

			-- Retry loop (only if idempotent and retry policy allows)
			from
				l_should_retry := a_is_idempotent and l_attempt <= retry_policy.max_retries and should_retry_response (Result)
			until
				not l_should_retry
			loop
				retry_count := retry_count + 1
				l_delay_ms := retry_policy.delay_for_attempt (l_attempt)

				-- Check for Retry-After header on 429/503
				if Result.status = 429 or Result.status = 503 then
					if attached Result.header ("retry-after") as ra then
						if ra.is_integer then
							l_delay_ms := ra.to_integer * 1000 -- Convert seconds to ms
						end
					end
				end

				-- Sleep before retry
				create l_env
				l_env.sleep (l_delay_ms * 1_000_000) -- Sleep takes nanoseconds

				-- Execute retry attempt
				l_attempt := l_attempt + 1
				Result := execute_single_request (a_url, a_method, a_data)
				last_response := Result

				-- Check if we should continue retrying
				l_should_retry := l_attempt <= retry_policy.max_retries and should_retry_response (Result)
			end
		end

	execute_single_request (a_url, a_method: STRING; a_data: detachable STRING): SIMPLE_HTTP_RESPONSE
			-- Execute a single HTTP request without retry.
		local
			l_session: NET_HTTP_CLIENT_SESSION
			l_raw: HTTP_CLIENT_RESPONSE
			l_full_url: STRING
		do
			l_full_url := build_url (a_url)
			l_session := client.new_session (l_full_url)
			configure_session (l_session)

			-- Add cookie header if enabled
			if cookies_enabled and attached cookie_jar as cj and then not cj.is_empty then
				l_session.add_header ("Cookie", cj.cookie_header)
			end

			-- Invoke before_request interceptors
			invoke_before_interceptors (l_full_url, a_method, a_data)

			-- Configure redirect behavior if session supports it
			configure_redirects (l_session)

			-- Execute based on method
			if a_method.is_case_insensitive_equal ("GET") then
				l_raw := l_session.get ("", Void)
			elseif a_method.is_case_insensitive_equal ("POST") then
				l_raw := l_session.post ("", Void, a_data)
			elseif a_method.is_case_insensitive_equal ("PUT") then
				l_raw := l_session.put ("", Void, a_data)
			elseif a_method.is_case_insensitive_equal ("DELETE") then
				l_raw := l_session.delete ("", Void)
			elseif a_method.is_case_insensitive_equal ("HEAD") then
				l_raw := l_session.head ("", Void)
			elseif a_method.is_case_insensitive_equal ("PATCH") then
				l_raw := l_session.patch ("", Void, a_data)
			else
				-- Default to GET
				l_raw := l_session.get ("", Void)
			end

			create Result.make_from_response (l_raw)

			-- Extract cookies from response if enabled
			if cookies_enabled and attached cookie_jar as cj then
				cj.extract_cookies_from_response (Result)
			end

			-- Invoke after_response interceptors
			invoke_after_interceptors (l_full_url, a_method, Result)
		end

	should_retry_response (a_response: SIMPLE_HTTP_RESPONSE): BOOLEAN
			-- Should we retry based on response?
		do
			if a_response.error_occurred then
				-- Network/connection error - retry if policy allows
				Result := retry_policy.should_retry_error
			else
				-- HTTP response - check status code
				Result := retry_policy.should_retry_status (a_response.status)
			end
		end

	configure_redirects (a_session: NET_HTTP_CLIENT_SESSION)
			-- Configure redirect settings on session.
			-- Note: This depends on ISE library capabilities.
		do
			-- ISE NET_HTTP_CLIENT_SESSION may have set_max_redirects
			-- For now, rely on defaults (follow redirects up to 10)
			-- Advanced redirect control requires checking ISE library features
			if not follow_redirects then
				-- Can't easily disable in ISE library, but this documents intent
				-- Future: a_session.set_max_redirects (0) if available
			end
		end

	invoke_before_interceptors (a_url, a_method: STRING; a_data: detachable STRING)
			-- Invoke all before_request interceptors.
		local
			l_i: INTEGER
		do
			from l_i := 1 until l_i > interceptors.count loop
				interceptors.i_th (l_i).before_request (a_url, a_method, custom_headers, a_data)
				l_i := l_i + 1
			end
		end

	invoke_after_interceptors (a_url, a_method: STRING; a_response: SIMPLE_HTTP_RESPONSE)
			-- Invoke all after_response interceptors.
		local
			l_i: INTEGER
		do
			from l_i := 1 until l_i > interceptors.count loop
				interceptors.i_th (l_i).after_response (a_url, a_method, a_response)
				l_i := l_i + 1
			end
		end

	invoke_error_interceptors (a_url, a_method: STRING; a_error: STRING)
			-- Invoke all on_error interceptors.
		local
			l_i: INTEGER
		do
			from l_i := 1 until l_i > interceptors.count loop
				interceptors.i_th (l_i).on_error (a_url, a_method, a_error)
				l_i := l_i + 1
			end
		end

feature {NONE} -- Constants

	Default_timeout_seconds: INTEGER = 30
			-- Default request timeout in seconds

	Default_connect_timeout_seconds: INTEGER = 10
			-- Default connection timeout in seconds

	Default_max_redirects: INTEGER = 10
			-- Default maximum number of redirects to follow

	Default_initial_delay_ms: INTEGER = 100
			-- Default initial retry delay in milliseconds

	Default_max_delay_ms: INTEGER = 30000
			-- Default maximum retry delay in milliseconds

note
	copyright: "Copyright (c) 2024-2025, Larry Rix"
	license: "MIT License"

end
