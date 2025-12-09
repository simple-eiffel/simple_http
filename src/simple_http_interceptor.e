note
	description: "Interceptor interface for HTTP requests/responses"
	author: "Larry Rix"
	date: "$Date$"
	revision: "$Revision$"

deferred class
	SIMPLE_HTTP_INTERCEPTOR

feature -- Interception

	before_request (a_url, a_method: STRING; a_headers: HASH_TABLE [STRING, STRING]; a_body: detachable STRING)
			-- Called before request is sent.
			-- Override to modify request, add logging, etc.
		require
			url_not_empty: not a_url.is_empty
			method_not_empty: not a_method.is_empty
		do
			-- Default: do nothing
		end

	after_response (a_url, a_method: STRING; a_response: SIMPLE_HTTP_RESPONSE)
			-- Called after response is received.
			-- Override to log, transform, cache, etc.
		require
			url_not_empty: not a_url.is_empty
			method_not_empty: not a_method.is_empty
			response_not_void: a_response /= Void
		do
			-- Default: do nothing
		end

	on_error (a_url, a_method: STRING; a_error_message: STRING)
			-- Called when an error occurs.
			-- Override for error logging, metrics, etc.
		require
			url_not_empty: not a_url.is_empty
			method_not_empty: not a_method.is_empty
		do
			-- Default: do nothing
		end

note
	copyright: "Copyright (c) 2024-2025, Larry Rix"
	license: "MIT License"

end
