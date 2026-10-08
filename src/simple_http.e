note
	description: "[
		Simple HTTP client for making web requests.

		TRANSPORT (1.1.0): every exchange rides SIMPLE_WINHTTP (WinHTTP,
		part of every supported Windows). Until 1.0.x the transport was
		ISE's curl_http_client, which runs the curl PROGRAM and splices
		the request body unescaped into ` --data "<body>"' on a command
		line: every '"' in a JSON body was lost, a blank could cut the
		argument, '%' '^' '&' '|' '<' were at the mercy of the shell, and
		a large body hit the command-line length limit. Bodies now travel
		as bytes, byte-for-byte; headers travel as header lines; the URL
		travels on the request line (see SIMPLE_HTTP_WIRE.wire_url).

		Behavior kept from the curl transport:
		* a request with a body and no Content-Type header is sent as
		  application/x-www-form-urlencoded (curl's --data default);
		* an Accept header of */* unless the caller sets one;
		* redirects (301/302/303/307/308) are followed, up to
		  `max_redirects', when `follow_redirects'.

		Redirect rules: 303 - and 301/302 after a POST - continue as a
		GET without the body; 307/308 repeat the method and body. When a
		redirect leaves the origin (scheme, host, port), the Authorization
		and Cookie headers are not sent onward.

		A network condition is a RESULT, never an exception: the response
		has `error_occurred' and an `error_message'.
	]"
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
			create transport.make
			create wire
			create custom_headers.make (5)
			create query_params.make (5)
			create interceptors.make (3)
			timeout := Default_timeout_seconds
			connect_timeout := Default_connect_timeout_seconds
			max_redirects := Default_max_redirects
			follow_redirects := True
			create retry_policy.make_none
			cookies_enabled := False
			body_maximum := Default_body_maximum
		ensure
			default_timeout: timeout = Default_timeout_seconds
			default_connect_timeout: connect_timeout = Default_connect_timeout_seconds
			following: follow_redirects and max_redirects = Default_max_redirects
			default_body_maximum: body_maximum = Default_body_maximum
			no_headers: custom_headers.is_empty
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

	body_maximum: INTEGER
			-- Largest response body accepted, in bytes (default 256 MiB).
			-- A larger body fails the request cleanly (`has_error')
			-- instead of growing without bound.

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

	set_body_maximum (a_bytes: INTEGER)
			-- Accept response bodies up to `a_bytes'.
		require
			positive: a_bytes > 0
			within_ceiling: a_bytes <= Body_maximum_ceiling
		do
			body_maximum := a_bytes
		ensure
			set: body_maximum = a_bytes
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

	transport: SIMPLE_WINHTTP
			-- The wire: one synchronous WinHTTP exchange per call

	wire: SIMPLE_HTTP_WIRE
			-- URL rules for the request line and for redirects

	custom_headers: HASH_TABLE [STRING, STRING]
			-- Custom headers to send with requests

	query_params: HASH_TABLE [STRING, STRING]
			-- Query parameters to append to URLs

	interceptors: ARRAYED_LIST [SIMPLE_HTTP_INTERCEPTOR]
			-- Registered interceptors

	cookie_jar: detachable SIMPLE_HTTP_COOKIE_JAR
			-- Cookie storage (created on demand)

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
			-- One request without retry: the exchange with the server and,
			-- when `follow_redirects', the redirect hops after it (at most
			-- `max_redirects'). Never raises for a network condition.
		local
			l_full_url, l_url, l_method, l_next: STRING
			l_body: detachable STRING
			l_hops: INTEGER
			l_done, l_with_credentials: BOOLEAN
		do
			l_full_url := build_url (a_url)

				-- Interceptors run first, so a header one adds travels
				-- with this very request.
			invoke_before_interceptors (l_full_url, a_method, a_data)

			l_method := wire_method (a_method)
			l_body := a_data
			l_with_credentials := True
			if wire.is_web_url (l_full_url) then
				l_url := wire.wire_url (l_full_url)
			else
				l_url := l_full_url
			end
			from
				Result := exchange (l_method, l_url, l_body, l_with_credentials)
			invariant
				hops_bounded: l_hops <= max_redirects
			until
				l_done
			loop
				if cookies_enabled and attached cookie_jar as cj and then not Result.error_occurred then
					cj.extract_cookies_from_response (Result)
				end
				if
					follow_redirects and then l_hops < max_redirects and then
					is_followed_redirect (Result.status) and then
					wire.is_web_url (l_url) and then
					attached Result.header ("location") as l_location and then
					not l_location.is_empty
				then
					if Result.status = 303 or else ((Result.status = 301 or Result.status = 302) and l_method.same_string ("POST")) then
						if not l_method.same_string ("HEAD") then
							l_method := "GET"
						end
						l_body := Void
					end
					l_next := wire.resolved_location (l_url, l_location)
					if not wire.same_origin (l_url, l_next) then
							-- Credentials never follow a redirect to another origin.
						l_with_credentials := False
					end
					l_url := l_next
					l_hops := l_hops + 1
					Result := exchange (l_method, l_url, l_body, l_with_credentials)
				else
					l_done := True
				end
			variant
				2 * (max_redirects - l_hops) + (not l_done).to_integer
			end

			if Result.error_occurred and then attached Result.error_message as l_message then
				invoke_error_interceptors (l_full_url, a_method, l_message.to_string_8)
			end

			-- Invoke after_response interceptors
			invoke_after_interceptors (l_full_url, a_method, Result)
		end

	exchange (a_method, a_url: STRING; a_body: detachable STRING; a_with_credentials: BOOLEAN): SIMPLE_HTTP_RESPONSE
			-- One exchange of `a_method' on `a_url' carrying `a_body' bytes
			-- verbatim. The Authorization and Cookie headers go only when
			-- `a_with_credentials'. A URL or header the wire cannot carry
			-- is a failed response, never a broken request.
		require
			method_given: not a_method.is_empty
		local
			l_headers: HASH_TABLE [STRING, STRING]
		do
			if not (wire.is_on_wire (a_url) and then transport.is_web_url (a_url) and then transport.is_ascii_url (a_url)) then
				create Result.make_failed ("Not a usable http(s) URL: " + a_url)
			elseif not transport.is_known_method (a_method) then
				create Result.make_failed ("Unsupported HTTP method: " + a_method)
			else
				l_headers := request_headers (a_body /= Void, a_with_credentials)
				if attached unclean_header (l_headers) as l_bad then
					create Result.make_failed ("Header %"" + l_bad + "%" holds characters an HTTP header line cannot carry (printable ASCII only, no CR or LF)")
				else
					transport.set_connect_timeout_seconds (wire_seconds (connect_timeout))
					transport.set_body_maximum (body_maximum)
					create Result.make_from_exchange (transport.send (a_method, a_url, l_headers, a_body, wire_seconds (timeout)))
				end
			end
		end

	request_headers (a_has_body, a_with_credentials: BOOLEAN): HASH_TABLE [STRING, STRING]
			-- The header lines for one exchange: the custom headers (less
			-- Authorization and Cookie unless `a_with_credentials'), the
			-- cookie jar's Cookie when enabled, Accept */* unless set, and
			-- - when `a_has_body' - a Content-Type of
			-- application/x-www-form-urlencoded unless set (the curl
			-- transport's --data default, kept for existing callers).
		local
			l_name: STRING
		do
			create Result.make (custom_headers.count + 3)
			across
				custom_headers as ic
			loop
				l_name := @ic.key
				if a_with_credentials or else not is_credential_header (l_name) then
					Result.force (ic, l_name)
				end
			end
			if a_with_credentials and cookies_enabled and attached cookie_jar as cj and then not cj.is_empty then
				Result.force (cj.cookie_header, "Cookie")
			end
			if not has_header_named (Result, "Accept") then
				Result.force ("*/*", "Accept")
			end
			if a_has_body and not has_header_named (Result, "Content-Type") then
				Result.force ("application/x-www-form-urlencoded", "Content-Type")
			end
		ensure
			accept_present: has_header_named (Result, "Accept")
			content_type_with_body: a_has_body implies has_header_named (Result, "Content-Type")
			credentials_withheld: not a_with_credentials implies not (has_header_named (Result, "Authorization") or has_header_named (Result, "Cookie"))
		end

	is_credential_header (a_name: STRING): BOOLEAN
			-- Is `a_name' a header that must not follow a cross-origin redirect?
		do
			Result := a_name.is_case_insensitive_equal ("Authorization") or a_name.is_case_insensitive_equal ("Cookie")
		end

	has_header_named (a_headers: HASH_TABLE [STRING, STRING]; a_name: STRING): BOOLEAN
			-- Does `a_headers' hold a header named `a_name' (any letter case)?
		do
			across
				a_headers as ic
			until
				Result
			loop
				Result := (@ic.key).is_case_insensitive_equal (a_name)
			end
		end

	unclean_header (a_headers: HASH_TABLE [STRING, STRING]): detachable STRING
			-- Name of the first header in `a_headers' the wire cannot carry
			-- (see SIMPLE_WINHTTP.is_header_table_clean), or Void.
		do
			across
				a_headers as ic
			until
				Result /= Void
			loop
				if not (transport.is_clean_header_name (@ic.key) and transport.is_clean_header_value (ic)) then
					Result := @ic.key
				end
			end
		ensure
			void_when_clean: (Result = Void) = transport.is_header_table_clean (a_headers)
		end

	wire_method (a_method: STRING): STRING
			-- `a_method' in upper case; GET for a method the transport
			-- does not send (the historical default).
		do
			Result := a_method.as_upper
			if not transport.is_known_method (Result) then
				Result := "GET"
			end
		ensure
			known: transport.is_known_method (Result)
		end

	wire_seconds (a_seconds: INTEGER): INTEGER
			-- `a_seconds' as a transport timeout: 0 (no limit, as the curl
			-- transport treated it) and anything beyond the wire's range
			-- become `Unlimited_timeout_seconds'.
		do
			if a_seconds <= 0 or a_seconds > Unlimited_timeout_seconds then
				Result := Unlimited_timeout_seconds
			else
				Result := a_seconds
			end
		ensure
			positive: Result > 0
			bounded: Result <= Unlimited_timeout_seconds
		end

	is_followed_redirect (a_status: INTEGER): BOOLEAN
			-- Is `a_status' a redirect this client follows?
		do
			Result := a_status = 301 or a_status = 302 or a_status = 303 or a_status = 307 or a_status = 308
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

feature -- Constants

	Default_body_maximum: INTEGER = 268_435_456
			-- Default response body ceiling: 256 MiB

	Body_maximum_ceiling: INTEGER = 1_073_741_824
			-- Largest `body_maximum' the transport supports: 1 GiB

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

	Unlimited_timeout_seconds: INTEGER = 2_000_000
			-- Transport timeout standing for "no limit" (about 23 days;
			-- its milliseconds still fit an INTEGER)

invariant
	positive_body_maximum: body_maximum > 0 and body_maximum <= Body_maximum_ceiling
	non_negative_timeout: timeout >= 0
	non_negative_connect_timeout: connect_timeout >= 0
	non_negative_max_redirects: max_redirects >= 0

note
	copyright: "Copyright (c) 2024-2025, Larry Rix"
	license: "MIT License"

end
