note
	description: "Test application for SIMPLE_HTTP"
	author: "Larry Rix"

class
	TEST_APP

create
	make

feature {NONE} -- Initialization

	make
			-- Run the tests.
		do
			create tests
			print ("Running SIMPLE_HTTP tests...%N%N")

			passed := 0
			failed := 0

			run_test (agent tests.test_create_client, "test_create_client")
			run_test (agent tests.test_response_status_helpers, "test_response_status_helpers")
			run_test (agent tests.test_timeout_settings, "test_timeout_settings")
			run_test (agent tests.test_header_management, "test_header_management")
			run_test (agent tests.test_authentication_helpers, "test_authentication_helpers")
			run_test (agent tests.test_query_parameters, "test_query_parameters")
			run_test (agent tests.test_content_type_helpers, "test_content_type_helpers")
			run_test (agent tests.test_url_building, "test_url_building")
			run_test (agent tests.test_retry_policy_default, "test_retry_policy_default")
			run_test (agent tests.test_retry_policy_custom, "test_retry_policy_custom")
			run_test (agent tests.test_retry_policy_none, "test_retry_policy_none")
			run_test (agent tests.test_redirect_settings, "test_redirect_settings")
			run_test (agent tests.test_request_builder, "test_request_builder")
			run_test (agent tests.test_cookie_jar, "test_cookie_jar")
			run_test (agent tests.test_interceptors, "test_interceptors")

			print ("%N========================%N")
			print ("Results: " + passed.out + " passed, " + failed.out + " failed%N")

			if failed > 0 then
				print ("TESTS FAILED%N")
			else
				print ("ALL TESTS PASSED%N")
			end
		end

feature {NONE} -- Implementation

	tests: LIB_TESTS

	passed: INTEGER
	failed: INTEGER

	run_test (a_test: PROCEDURE; a_name: STRING)
			-- Run a single test and update counters.
		local
			l_retried: BOOLEAN
		do
			if not l_retried then
				a_test.call (Void)
				print ("  PASS: " + a_name + "%N")
				passed := passed + 1
			end
		rescue
			print ("  FAIL: " + a_name + "%N")
			failed := failed + 1
			l_retried := True
			retry
		end

end
