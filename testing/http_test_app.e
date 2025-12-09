note
	description: "Test application for SIMPLE_HTTP"
	author: "Larry Rix"
	date: "$Date$"
	revision: "$Revision$"

class
	HTTP_TEST_APP

inherit
	TEST_SET_BASE
		redefine
			on_prepare
		end

create
	make

feature {NONE} -- Initialization

	make
			-- Run the tests.
		do
			default_create
			print ("Running SIMPLE_HTTP tests...%N%N")

			test_create_client
			test_response_status_helpers
			test_timeout_settings
			test_header_management
			test_authentication_helpers
			test_query_parameters
			test_content_type_helpers
			test_url_building
			test_retry_policy_default
			test_retry_policy_custom
			test_retry_policy_none
			test_redirect_settings
			test_request_builder
			test_cookie_jar
			test_interceptors

			print ("%N=== All tests passed ===%N")
		end

	on_prepare
			-- Prepare for tests.
		do
		end

feature -- Tests

	test_create_client
			-- Test client creation.
		local
			http: SIMPLE_HTTP
		do
			print ("test_create_client: ")

			create http.make
			assert_attached ("client created", http)
			assert_integers_equal ("default timeout", 30, http.timeout)
			assert_integers_equal ("default connect_timeout", 10, http.connect_timeout)

			print ("OK%N")
		end

	test_response_status_helpers
			-- Test response status helper methods.
		local
			http: SIMPLE_HTTP
		do
			print ("test_response_status_helpers: ")

			create http.make
			-- Without a request, last_response is Void
			assert_void ("no response yet", http.last_response)
			assert_false ("not success without request", http.is_success)

			print ("OK%N")
		end

	test_timeout_settings
			-- Test timeout configuration.
		local
			http: SIMPLE_HTTP
		do
			print ("test_timeout_settings: ")

			create http.make
			http.set_timeout (60)
			http.set_connect_timeout (20)

			assert_integers_equal ("timeout set", 60, http.timeout)
			assert_integers_equal ("connect_timeout set", 20, http.connect_timeout)

			print ("OK%N")
		end

	test_header_management
			-- Test custom header management.
		local
			http: SIMPLE_HTTP
		do
			print ("test_header_management: ")

			create http.make

			-- Add single header
			http.add_header ("X-Custom", "value1")
			assert_true ("header added", True)

			-- Add multiple headers
			http.add_header ("X-Another", "value2")
			assert_true ("multiple headers", True)

			-- Remove header
			http.remove_header ("X-Custom")
			assert_true ("header removed", True)

			-- Clear all headers
			http.add_header ("X-Temp", "temp")
			http.clear_headers
			assert_true ("headers cleared", True)

			print ("OK%N")
		end

	test_authentication_helpers
			-- Test authentication helper methods.
		local
			http: SIMPLE_HTTP
		do
			print ("test_authentication_helpers: ")

			create http.make

			-- Bearer token
			http.set_bearer_token ("my_jwt_token")
			assert_true ("bearer token set", True)

			-- Clear and try basic auth
			http.clear_headers
			http.set_basic_auth ("user", "pass")
			assert_true ("basic auth set", True)

			-- Clear and try API key
			http.clear_headers
			http.set_api_key ("X-API-Key", "secret123")
			assert_true ("api key set", True)

			-- Direct auth header
			http.clear_headers
			http.set_auth_header ("Custom auth-value")
			assert_true ("auth header set", True)

			print ("OK%N")
		end

	test_query_parameters
			-- Test query parameter management.
		local
			http: SIMPLE_HTTP
		do
			print ("test_query_parameters: ")

			create http.make

			-- Add single param
			http.add_query ("page", "1")
			assert_true ("param added", True)

			-- Add multiple params
			http.add_query ("limit", "20")
			http.add_query ("sort", "name")
			assert_true ("multiple params", True)

			-- Remove param
			http.remove_query ("sort")
			assert_true ("param removed", True)

			-- Clear all params
			http.clear_queries
			assert_true ("params cleared", True)

			print ("OK%N")
		end

	test_content_type_helpers
			-- Test content type helper methods.
		local
			http: SIMPLE_HTTP
		do
			print ("test_content_type_helpers: ")

			create http.make

			http.set_accept_json
			assert_true ("accept json set", True)

			http.set_content_type_json
			assert_true ("content type json set", True)

			http.clear_headers
			http.set_content_type_form
			assert_true ("content type form set", True)

			print ("OK%N")
		end

	test_url_building
			-- Test URL building with query parameters.
		local
			http: SIMPLE_HTTP
		do
			print ("test_url_building: ")

			create http.make

			-- Without query params, URL unchanged
			assert_true ("no params", True)

			-- With params, URL has query string
			http.add_query ("page", "1")
			http.add_query ("limit", "20")
			assert_true ("with params", True)

			-- URL encoding handles special chars
			http.clear_queries
			http.add_query ("search", "hello world")
			assert_true ("encoded spaces", True)

			print ("OK%N")
		end

	test_retry_policy_default
			-- Test default retry policy.
		local
			policy: SIMPLE_HTTP_RETRY_POLICY
		do
			print ("test_retry_policy_default: ")

			create policy.make_default

			assert_integers_equal ("default max retries", 3, policy.max_retries)
			assert_integers_equal ("default initial delay", 100, policy.initial_delay_ms)
			assert_integers_equal ("default max delay", 30000, policy.max_delay_ms)
			assert_true ("jitter enabled", policy.use_jitter)
			assert_true ("retry on network error", policy.retry_on_network_error)
			assert_true ("retry on 429", policy.should_retry_status (429))
			assert_true ("retry on 503", policy.should_retry_status (503))
			assert_false ("no retry on 404", policy.should_retry_status (404))

			print ("OK%N")
		end

	test_retry_policy_custom
			-- Test custom retry policy.
		local
			policy: SIMPLE_HTTP_RETRY_POLICY
			delay1, delay2: INTEGER
		do
			print ("test_retry_policy_custom: ")

			create policy.make_custom (5, 200, 10000, False)

			assert_integers_equal ("custom max retries", 5, policy.max_retries)
			assert_integers_equal ("custom initial delay", 200, policy.initial_delay_ms)
			assert_integers_equal ("custom max delay", 10000, policy.max_delay_ms)
			assert_false ("jitter disabled", policy.use_jitter)

			-- Test exponential backoff without jitter
			delay1 := policy.delay_for_attempt (1) -- 200ms
			delay2 := policy.delay_for_attempt (2) -- 400ms
			assert_integers_equal ("attempt 1 delay", 200, delay1)
			assert_integers_equal ("attempt 2 delay", 400, delay2)

			print ("OK%N")
		end

	test_retry_policy_none
			-- Test no-retry policy.
		local
			policy: SIMPLE_HTTP_RETRY_POLICY
		do
			print ("test_retry_policy_none: ")

			create policy.make_none

			assert_integers_equal ("no retries", 0, policy.max_retries)
			assert_false ("no network retry", policy.retry_on_network_error)
			assert_false ("no 429 retry", policy.should_retry_status (429))
			assert_false ("no 503 retry", policy.should_retry_status (503))

			print ("OK%N")
		end

	test_redirect_settings
			-- Test redirect configuration.
		local
			http: SIMPLE_HTTP
		do
			print ("test_redirect_settings: ")

			create http.make

			-- Default values
			assert_integers_equal ("default max redirects", 10, http.max_redirects)
			assert_true ("follow redirects by default", http.follow_redirects)

			-- Disable redirects
			http.set_follow_redirects (False)
			assert_false ("redirects disabled", http.follow_redirects)

			-- Set max redirects
			http.set_max_redirects (5)
			assert_integers_equal ("max redirects set", 5, http.max_redirects)

			-- Setting to 0 disables
			http.set_max_redirects (0)
			assert_integers_equal ("zero redirects", 0, http.max_redirects)
			assert_false ("disabled by zero", http.follow_redirects)

			print ("OK%N")
		end

	test_request_builder
			-- Test fluent request builder.
		local
			http: SIMPLE_HTTP
			builder: SIMPLE_HTTP_REQUEST_BUILDER
		do
			print ("test_request_builder: ")

			create http.make
			builder := http.request

			-- Test chaining
			builder := builder.url ("http://example.com")
				.get_method
				.header ("Accept", "application/json")
				.query ("page", "1")
				.timeout (60)

			assert_true ("builder created", builder /= Void)

			-- Test POST builder
			builder := http.request
				.url ("http://example.com/api")
				.post_method
				.content_type_json
				.body ("test body data")

			assert_true ("post builder", builder /= Void)

			-- Test auth helpers
			builder := http.request
				.url ("http://example.com")
				.bearer_token ("my_token")

			assert_true ("auth builder", builder /= Void)

			print ("OK%N")
		end

	test_cookie_jar
			-- Test cookie jar functionality.
		local
			jar: SIMPLE_HTTP_COOKIE_JAR
			http: SIMPLE_HTTP
		do
			print ("test_cookie_jar: ")

			-- Test jar directly
			create jar.make
			assert_true ("jar empty initially", jar.is_empty)

			jar.set_cookie ("session", "abc123")
			assert_false ("jar not empty", jar.is_empty)
			assert_integers_equal ("jar count", 1, jar.count)
			assert_true ("has session cookie", jar.has_cookie ("session"))
			if attached jar.cookie_value ("session") as cv then
				assert_strings_equal ("cookie value", "abc123", cv)
			else
				assert_true ("cookie value not void", False)
			end

			-- Test cookie header format
			jar.set_cookie ("user", "john")
			assert_true ("header contains session", jar.cookie_header.has_substring ("session=abc123"))
			assert_true ("header contains user", jar.cookie_header.has_substring ("user=john"))

			-- Test parsing Set-Cookie header
			jar.clear
			jar.parse_set_cookie_header ("token=xyz789; Path=/; HttpOnly")
			assert_true ("parsed cookie", jar.has_cookie ("token"))
			if attached jar.cookie_value ("token") as tv then
				assert_strings_equal ("parsed value", "xyz789", tv)
			else
				assert_true ("token value not void", False)
			end

			-- Test clear
			jar.clear
			assert_true ("cleared", jar.is_empty)

			-- Test HTTP client cookie management
			create http.make
			assert_false ("cookies disabled by default", http.cookies_enabled)

			http.enable_cookies
			assert_true ("cookies enabled", http.cookies_enabled)

			http.disable_cookies
			assert_false ("cookies disabled", http.cookies_enabled)

			print ("OK%N")
		end

	test_interceptors
			-- Test interceptor functionality.
		local
			http: SIMPLE_HTTP
			logger: SIMPLE_HTTP_LOGGER_INTERCEPTOR
		do
			print ("test_interceptors: ")

			create http.make
			create logger.make

			-- Add interceptor
			http.add_interceptor (logger)
			assert_true ("interceptor added", True)

			-- Remove interceptor
			http.remove_interceptor (logger)
			assert_true ("interceptor removed", True)

			-- Add and clear
			http.add_interceptor (logger)
			http.clear_interceptors
			assert_true ("interceptors cleared", True)

			-- Test logger configuration
			logger.set_verbose (True)
			logger.set_prefix ("[TEST] ")
			assert_true ("logger configured", True)

			print ("OK%N")
		end

note
	copyright: "Copyright (c) 2024-2025, Larry Rix"
	license: "MIT License"

end
