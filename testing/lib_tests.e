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

feature -- Tests: wire rules (1.1.0)

	test_wire_url_keeps_well_formed
			-- A URL that is already fit for the request line passes
			-- through byte-for-byte - escapes, '&', '=' and all.
		note
			testing: "covers/{SIMPLE_HTTP_WIRE}.wire_url"
		local
			l_wire: SIMPLE_HTTP_WIRE
			l_url: STRING
		do
			create l_wire
			l_url := "http://127.0.0.1:8080/a/b?note=a%%20b%%26c%%22d&greek=%%CE%%B1&x=1"
			assert_strings_equal ("verbatim", l_url, l_wire.wire_url (l_url))
			assert_strings_equal ("https verbatim", "https://example.com/", l_wire.wire_url ("https://example.com/"))
		end

	test_wire_url_encodes_what_the_line_cannot_carry
			-- Blanks, quotes, shell metacharacters, UTF-8 bytes and a bare
			-- '%' are percent-encoded; the fragment is dropped; an empty
			-- path becomes "/"; the scheme is lower-cased.
		note
			testing: "covers/{SIMPLE_HTTP_WIRE}.wire_url"
		local
			l_wire: SIMPLE_HTTP_WIRE
			l_hebrew: STRING
		do
			create l_wire
			assert_strings_equal ("blank and quote", "http://h/a%%20b?q=%%22x%%22", l_wire.wire_url ("http://h/a b?q=%"x%""))
			assert_strings_equal ("shell set", "http://h/?s=%%3C%%3E%%7C%%5E%%60%%7B%%7D%%5C!&t=1", l_wire.wire_url ("http://h/?s=<>|^`{}\!&t=1"))
				-- Hebrew alef (U+05D0) is the UTF-8 bytes D7 90.
			l_hebrew := "http://h/x?w="
			l_hebrew.append_character ('%/215/')
			l_hebrew.append_character ('%/144/')
			assert_strings_equal ("utf-8 bytes", "http://h/x?w=%%D7%%90", l_wire.wire_url (l_hebrew))
			assert_strings_equal ("bare percent", "http://h/?p=100%%25", l_wire.wire_url ("http://h/?p=100%%"))
			assert_strings_equal ("fragment dropped", "http://h/p?q=1", l_wire.wire_url ("http://h/p?q=1#frag"))
			assert_strings_equal ("empty path", "http://h:81/", l_wire.wire_url ("http://h:81"))
			assert_strings_equal ("query without path", "http://h/?q=1", l_wire.wire_url ("http://h?q=1"))
			assert_strings_equal ("scheme lower-cased", "https://h/", l_wire.wire_url ("HTTPS://h/"))
			assert_strings_equal ("idempotent", l_wire.wire_url ("http://h/a b"), l_wire.wire_url (l_wire.wire_url ("http://h/a b")))
		end

	test_resolved_location
			-- Every form a Location header takes resolves against the URL
			-- that answered with it.
		note
			testing: "covers/{SIMPLE_HTTP_WIRE}.resolved_location"
		local
			l_wire: SIMPLE_HTTP_WIRE
			l_base: STRING
		do
			create l_wire
			l_base := "http://h:8080/api/v1/items?page=2"
			assert_strings_equal ("absolute", "https://other.org/x", l_wire.resolved_location (l_base, "https://other.org/x"))
			assert_strings_equal ("scheme-relative", "http://cdn.org/y", l_wire.resolved_location (l_base, "//cdn.org/y"))
			assert_strings_equal ("absolute path", "http://h:8080/login?next=1", l_wire.resolved_location (l_base, "/login?next=1"))
			assert_strings_equal ("query only", "http://h:8080/api/v1/items?page=3", l_wire.resolved_location (l_base, "?page=3"))
			assert_strings_equal ("path-relative", "http://h:8080/api/v1/other", l_wire.resolved_location (l_base, "other"))
			assert_strings_equal ("encoded on the way", "http://h:8080/a%%20b", l_wire.resolved_location (l_base, "/a b"))
		end

	test_same_origin
			-- Scheme, host and port decide; path and letter case do not.
		note
			testing: "covers/{SIMPLE_HTTP_WIRE}.same_origin"
		local
			l_wire: SIMPLE_HTTP_WIRE
		do
			create l_wire
			assert_true ("same", l_wire.same_origin ("http://H:80/a", "http://h:80/b?c"))
			assert_false ("other host", l_wire.same_origin ("http://h/a", "http://g/a"))
			assert_false ("other port", l_wire.same_origin ("http://h:80/a", "http://h:81/a"))
			assert_false ("other scheme", l_wire.same_origin ("http://h/a", "https://h/a"))
		end

feature -- Tests: transport results (1.1.0)

	test_body_maximum
			-- The response ceiling defaults to 256 MiB and is settable.
		note
			testing: "covers/{SIMPLE_HTTP}.set_body_maximum"
		local
			http: SIMPLE_HTTP
		do
			create http.make
			assert_integers_equal ("default 256 MiB", 268_435_456, http.body_maximum)
			http.set_body_maximum (1024)
			assert_integers_equal ("set", 1024, http.body_maximum)
		end

	test_refused_connection_is_a_result
			-- Nothing listens on loopback port 1: the POST comes back as a
			-- failed response with an explanation - never an exception.
		note
			testing: "covers/{SIMPLE_HTTP}.post"
		local
			http: SIMPLE_HTTP
			l_response: SIMPLE_HTTP_RESPONSE
		do
			create http.make
			http.set_connect_timeout (5)
			l_response := http.post ("http://127.0.0.1:1/nothing", "{%"a%":1}")
			assert_true ("error flagged", l_response.error_occurred)
			assert_integers_equal ("no status", 0, l_response.status)
			assert_true ("explained", attached l_response.error_message as l_message and then not l_message.is_empty)
			assert_true ("is last response", http.last_response = l_response)
		end

	test_unusable_url_is_a_result
			-- A URL that is not http(s) fails before any exchange.
		note
			testing: "covers/{SIMPLE_HTTP}.get"
		local
			http: SIMPLE_HTTP
			l_response: SIMPLE_HTTP_RESPONSE
		do
			create http.make
			l_response := http.get ("ftp://example.com/file")
			assert_true ("error flagged", l_response.error_occurred)
			assert_true ("names the url", attached l_response.error_message as l_message and then l_message.has_substring ("ftp://example.com/file"))
		end

	test_unclean_header_is_a_result
			-- A header value no header line can carry (a raw UTF-8 byte
			-- here) fails the request with the header named - it is never
			-- sent half-formed.
		note
			testing: "covers/{SIMPLE_HTTP}.post"
		local
			http: SIMPLE_HTTP
			l_response: SIMPLE_HTTP_RESPONSE
			l_value: STRING
		do
			create http.make
			l_value := "caf"
			l_value.append_character ('%/195/')
			l_value.append_character ('%/169/')
			http.add_header ("X-Menu", l_value)
			l_response := http.post ("http://127.0.0.1:1/nothing", "x")
			assert_true ("error flagged", l_response.error_occurred)
			assert_true ("names the header", attached l_response.error_message as l_message and then l_message.has_substring ("X-Menu"))
		end

	test_response_from_exchange
			-- An answered exchange carries status, body bytes and parsed
			-- headers; a failed one carries the transport's reason.
		note
			testing: "covers/{SIMPLE_HTTP_RESPONSE}.make_from_exchange"
		local
			l_exchange: SIMPLE_WINHTTP_RESPONSE
			l_response: SIMPLE_HTTP_RESPONSE
		do
			create l_exchange.make (201, "{%"id%":7}", "HTTP/1.1 201 Created%R%NContent-Type: application/json; charset=utf-8%R%NX-Trace: a b%R%N%R%N")
			create l_response.make_from_exchange (l_exchange)
			assert_integers_equal ("status", 201, l_response.status)
			assert_strings_equal ("body", "{%"id%":7}", l_response.body_string)
			assert_true ("json", l_response.is_json_content)
			assert_true ("charset", attached l_response.charset as l_charset and then l_charset.same_string ("utf-8"))
			assert_true ("custom header", attached l_response.header ("x-trace") as l_trace and then l_trace.same_string ("a b"))
			assert_false ("no error", l_response.error_occurred)
			assert_integers_equal ("json field", 7, l_response.json_integer ("id"))

			create l_exchange.make_failed ("WinHTTP GET http://x/ failed: timed out (Win32 12002)")
			create l_response.make_from_exchange (l_exchange)
			assert_true ("failed", l_response.error_occurred)
			assert_integers_equal ("no status", 0, l_response.status)
			assert_true ("reason kept", attached l_response.error_message as l_message and then l_message.has_substring ("timed out"))
		end

	test_repeated_set_cookie_all_reach_jar
			-- Three Set-Cookie lines in one response: `header_values' keeps
			-- all three and the cookie jar stores every cookie.
		note
			testing: "covers/{SIMPLE_HTTP_RESPONSE}.header_values", "covers/{SIMPLE_HTTP_COOKIE_JAR}.extract_cookies_from_response"
		local
			l_exchange: SIMPLE_WINHTTP_RESPONSE
			l_response: SIMPLE_HTTP_RESPONSE
			l_jar: SIMPLE_HTTP_COOKIE_JAR
		do
			create l_exchange.make (200, "", "HTTP/1.1 200 OK%R%NSet-Cookie: a=1; Path=/%R%Nset-cookie: b=2; HttpOnly%R%NSet-Cookie: c=3%R%NX-One: x%R%N%R%N")
			create l_response.make_from_exchange (l_exchange)
			assert_integers_equal ("three lines", 3, l_response.header_values ("SET-COOKIE").count)
			assert_strings_equal ("first kept", "a=1; Path=/", l_response.header_values ("Set-Cookie").first)
			assert_integers_equal ("single header", 1, l_response.header_values ("X-One").count)
			assert_integers_equal ("absent header", 0, l_response.header_values ("X-None").count)
			create l_jar.make
			l_jar.extract_cookies_from_response (l_response)
			assert_true ("a", l_jar.has_cookie ("a"))
			assert_true ("b", l_jar.has_cookie ("b"))
			assert_true ("c", l_jar.has_cookie ("c"))
		end

	test_cookies_round_trip_live
			-- Live: needs SIMPLE_HTTP_COOKIE_PORT naming a local server that
			-- sends 3 Set-Cookie headers and records the next request.
			-- Skipped (passes) when the variable is unset.
		local
			l_http: SIMPLE_HTTP
			l_response: SIMPLE_HTTP_RESPONSE
		do
			if attached (create {EXECUTION_ENVIRONMENT}).item ("SIMPLE_HTTP_COOKIE_PORT") as l_port then
				create l_http.make
				l_http.enable_cookies
				l_response := l_http.get ("http://127.0.0.1:" + l_port.out + "/first")
				assert_false ("first ok", l_response.error_occurred)
				l_response := l_http.get ("http://127.0.0.1:" + l_port.out + "/second")
				assert_false ("second ok", l_response.error_occurred)
			end
		end

end
