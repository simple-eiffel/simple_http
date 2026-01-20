note
	description: "Tests for SIMPLE_HTTP"
	author: "Larry Rix"
	testing: "covers"

class
	LIB_TESTS

inherit
	TEST_SET_BASE
		redefine
			on_prepare
		end

feature {NONE} -- Setup

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
			create http.make
			assert_attached ("client created", http)
			assert_integers_equal ("default timeout", 30, http.timeout)
			assert_integers_equal ("default connect_timeout", 10, http.connect_timeout)
		end

	test_response_status_helpers
			-- Test response status helper methods.
		local
			http: SIMPLE_HTTP
		do
			create http.make
			assert_void ("no response yet", http.last_response)
			assert_false ("not success without request", http.is_success)
		end

	test_timeout_settings
			-- Test timeout configuration.
		local
			http: SIMPLE_HTTP
		do
			create http.make
			http.set_timeout (60)
			http.set_connect_timeout (20)

			assert_integers_equal ("timeout set", 60, http.timeout)
			assert_integers_equal ("connect_timeout set", 20, http.connect_timeout)
		end

	test_header_management
			-- Test custom header management.
		local
			http: SIMPLE_HTTP
		do
			create http.make

			http.add_header ("X-Custom", "value1")
			assert_true ("header added", True)

			http.add_header ("X-Another", "value2")
			assert_true ("multiple headers", True)

			http.remove_header ("X-Custom")
			assert_true ("header removed", True)

			http.add_header ("X-Temp", "temp")
			http.clear_headers
			assert_true ("headers cleared", True)
		end

	test_authentication_helpers
			-- Test authentication helper methods.
		local
			http: SIMPLE_HTTP
		do
			create http.make

			http.set_bearer_token ("my_jwt_token")
			assert_true ("bearer token set", True)

			http.clear_headers
			http.set_basic_auth ("user", "pass")
			assert_true ("basic auth set", True)

			http.clear_headers
			http.set_api_key ("X-API-Key", "secret123")
			assert_true ("api key set", True)

			http.clear_headers
			http.set_auth_header ("Custom auth-value")
			assert_true ("auth header set", True)
		end

	test_query_parameters
			-- Test query parameter management.
		local
			http: SIMPLE_HTTP
		do
			create http.make

			http.add_query ("page", "1")
			assert_true ("param added", True)

			http.add_query ("limit", "20")
			http.add_query ("sort", "name")
			assert_true ("multiple params", True)

			http.remove_query ("sort")
			assert_true ("param removed", True)

			http.clear_queries
			assert_true ("params cleared", True)
		end

	test_content_type_helpers
			-- Test content type helper methods.
		local
			http: SIMPLE_HTTP
		do
			create http.make

			http.set_accept_json
			assert_true ("accept json set", True)

			http.set_content_type_json
			assert_true ("content type json set", True)

			http.clear_headers
			http.set_content_type_form
			assert_true ("content type form set", True)
		end

	test_url_building
			-- Test URL building with query parameters.
		local
			http: SIMPLE_HTTP
		do
			create http.make

			assert_true ("no params", True)

			http.add_query ("page", "1")
			http.add_query ("limit", "20")
			assert_true ("with params", True)

			http.clear_queries
			http.add_query ("search", "hello world")
			assert_true ("encoded spaces", True)
		end

	test_retry_policy_default
			-- Test default retry policy.
		local
			policy: SIMPLE_HTTP_RETRY_POLICY
		do
			create policy.make_default

			assert_integers_equal ("default max retries", 3, policy.max_retries)
			assert_integers_equal ("default initial delay", 100, policy.initial_delay_ms)
			assert_integers_equal ("default max delay", 30000, policy.max_delay_ms)
			assert_true ("jitter enabled", policy.use_jitter)
			assert_true ("retry on network error", policy.retry_on_network_error)
			assert_true ("retry on 429", policy.should_retry_status (429))
			assert_true ("retry on 503", policy.should_retry_status (503))
			assert_false ("no retry on 404", policy.should_retry_status (404))
		end

	test_retry_policy_custom
			-- Test custom retry policy.
		local
			policy: SIMPLE_HTTP_RETRY_POLICY
			delay1, delay2: INTEGER
		do
			create policy.make_custom (5, 200, 10000, False)

			assert_integers_equal ("custom max retries", 5, policy.max_retries)
			assert_integers_equal ("custom initial delay", 200, policy.initial_delay_ms)
			assert_integers_equal ("custom max delay", 10000, policy.max_delay_ms)
			assert_false ("jitter disabled", policy.use_jitter)

			delay1 := policy.delay_for_attempt (1)
			delay2 := policy.delay_for_attempt (2)
			assert_integers_equal ("attempt 1 delay", 200, delay1)
			assert_integers_equal ("attempt 2 delay", 400, delay2)
		end

	test_retry_policy_none
			-- Test no-retry policy.
		local
			policy: SIMPLE_HTTP_RETRY_POLICY
		do
			create policy.make_none

			assert_integers_equal ("no retries", 0, policy.max_retries)
			assert_false ("no network retry", policy.retry_on_network_error)
			assert_false ("no 429 retry", policy.should_retry_status (429))
			assert_false ("no 503 retry", policy.should_retry_status (503))
		end

	test_redirect_settings
			-- Test redirect configuration.
		local
			http: SIMPLE_HTTP
		do
			create http.make

			assert_integers_equal ("default max redirects", 10, http.max_redirects)
			assert_true ("follow redirects by default", http.follow_redirects)

			http.set_follow_redirects (False)
			assert_false ("redirects disabled", http.follow_redirects)

			http.set_max_redirects (5)
			assert_integers_equal ("max redirects set", 5, http.max_redirects)

			http.set_max_redirects (0)
			assert_integers_equal ("zero redirects", 0, http.max_redirects)
			assert_false ("disabled by zero", http.follow_redirects)
		end

	test_request_builder
			-- Test fluent request builder.
		local
			http: SIMPLE_HTTP
			builder: SIMPLE_HTTP_REQUEST_BUILDER
		do
			create http.make
			builder := http.request

			builder := builder.url ("http://example.com")
				.get_method
				.header ("Accept", "application/json")
				.query ("page", "1")
				.timeout (60)

			assert_true ("builder created", builder /= Void)

			builder := http.request
				.url ("http://example.com/api")
				.post_method
				.content_type_json
				.body ("test body data")

			assert_true ("post builder", builder /= Void)

			builder := http.request
				.url ("http://example.com")
				.bearer_token ("my_token")

			assert_true ("auth builder", builder /= Void)
		end

	test_cookie_jar
			-- Test cookie jar functionality.
		local
			jar: SIMPLE_HTTP_COOKIE_JAR
			http: SIMPLE_HTTP
		do
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

			jar.set_cookie ("user", "john")
			assert_true ("header contains session", jar.cookie_header.has_substring ("session=abc123"))
			assert_true ("header contains user", jar.cookie_header.has_substring ("user=john"))

			jar.clear
			jar.parse_set_cookie_header ("token=xyz789; Path=/; HttpOnly")
			assert_true ("parsed cookie", jar.has_cookie ("token"))
			if attached jar.cookie_value ("token") as tv then
				assert_strings_equal ("parsed value", "xyz789", tv)
			else
				assert_true ("token value not void", False)
			end

			jar.clear
			assert_true ("cleared", jar.is_empty)

			create http.make
			assert_false ("cookies disabled by default", http.cookies_enabled)

			http.enable_cookies
			assert_true ("cookies enabled", http.cookies_enabled)

			http.disable_cookies
			assert_false ("cookies disabled", http.cookies_enabled)
		end

	test_interceptors
			-- Test interceptor functionality.
		local
			http: SIMPLE_HTTP
			logger: SIMPLE_HTTP_LOGGER_INTERCEPTOR
		do
			create http.make
			create logger.make

			http.add_interceptor (logger)
			assert_true ("interceptor added", True)

			http.remove_interceptor (logger)
			assert_true ("interceptor removed", True)

			http.add_interceptor (logger)
			http.clear_interceptors
			assert_true ("interceptors cleared", True)

			logger.set_verbose (True)
			logger.set_prefix ("[TEST] ")
			assert_true ("logger configured", True)
		end

	test_client_cache
			-- Test HTTP client cache.
		local
			cache: SIMPLE_HTTP_CLIENT_CACHE
			client1, client2: SIMPLE_HTTP
		do
			create cache.make
			assert_integers_equal ("initially empty", 0, cache.cached_count)

			-- Get client for host (creates new)
			client1 := cache.client_for_host ("api.example.com")
			assert_attached ("client created", client1)
			assert_integers_equal ("one cached", 1, cache.cached_count)
			assert_true ("is cached", cache.is_cached ("api.example.com"))

			-- Get same client again (reuses cached)
			client2 := cache.client_for_host ("api.example.com")
			assert_true ("same client", client1 = client2)
			assert_integers_equal ("still one", 1, cache.cached_count)

			-- Get client for different host
			client2 := cache.client_for_host ("other.example.com")
			assert_integers_equal ("two cached", 2, cache.cached_count)

			-- Invalidate one
			cache.invalidate ("api.example.com")
			assert_integers_equal ("one remaining", 1, cache.cached_count)
			assert_false ("not cached", cache.is_cached ("api.example.com"))

			-- Invalidate all
			cache.invalidate_all
			assert_integers_equal ("all cleared", 0, cache.cached_count)
		end

	test_client_cache_config
			-- Test HTTP client cache configuration.
		local
			cache: SIMPLE_HTTP_CLIENT_CACHE
			client: SIMPLE_HTTP
		do
			create cache.make
			cache.set_default_timeout (60)
			cache.set_default_connect_timeout (15)

			client := cache.client_for_host ("example.com")
			assert_integers_equal ("timeout applied", 60, client.timeout)
			assert_integers_equal ("connect_timeout applied", 15, client.connect_timeout)
		end

end
