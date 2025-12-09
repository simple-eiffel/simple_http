note
	description: "Logging interceptor for HTTP requests/responses"
	author: "Larry Rix"
	date: "$Date$"
	revision: "$Revision$"

class
	SIMPLE_HTTP_LOGGER_INTERCEPTOR

inherit
	SIMPLE_HTTP_INTERCEPTOR
		redefine
			before_request,
			after_response,
			on_error
		end

create
	make,
	make_verbose

feature {NONE} -- Initialization

	make
			-- Create logger with standard output.
		do
			verbose := False
			create log_prefix.make_from_string ("[HTTP] ")
		end

	make_verbose
			-- Create verbose logger.
		do
			verbose := True
			create log_prefix.make_from_string ("[HTTP] ")
		end

feature -- Configuration

	set_verbose (a_verbose: BOOLEAN)
			-- Set verbose mode.
		do
			verbose := a_verbose
		ensure
			verbose_set: verbose = a_verbose
		end

	set_prefix (a_prefix: STRING)
			-- Set log prefix.
		require
			prefix_not_void: a_prefix /= Void
		do
			log_prefix := a_prefix
		ensure
			prefix_set: log_prefix = a_prefix
		end

feature -- Interception

	before_request (a_url, a_method: STRING; a_headers: HASH_TABLE [STRING, STRING]; a_body: detachable STRING)
			-- Log request details.
		do
			print (log_prefix + "Request: " + a_method + " " + a_url + "%N")
			if verbose then
				print_headers (a_headers)
				if attached a_body as b and then not b.is_empty then
					print (log_prefix + "  Body: " + truncate (b, 200) + "%N")
				end
			end
		end

	after_response (a_url, a_method: STRING; a_response: SIMPLE_HTTP_RESPONSE)
			-- Log response details.
		do
			print (log_prefix + "Response: " + a_response.status.out + " from " + a_url + "%N")
			if verbose then
				if attached a_response.content_type as ct then
					print (log_prefix + "  Content-Type: " + ct + "%N")
				end
				print (log_prefix + "  Content-Length: " + a_response.content_length.out + "%N")
			end
		end

	on_error (a_url, a_method: STRING; a_error_message: STRING)
			-- Log error.
		do
			print (log_prefix + "ERROR: " + a_method + " " + a_url + " - " + a_error_message + "%N")
		end

feature {NONE} -- Implementation

	verbose: BOOLEAN
			-- Verbose logging?

	log_prefix: STRING
			-- Prefix for log messages

	print_headers (a_headers: HASH_TABLE [STRING, STRING])
			-- Print headers if not empty.
		local
			l_keys: ARRAY [STRING]
			i: INTEGER
		do
			if not a_headers.is_empty then
				print (log_prefix + "  Headers:%N")
				l_keys := a_headers.current_keys
				from i := l_keys.lower until i > l_keys.upper loop
					if attached a_headers.item (l_keys.item (i)) as v then
						print (log_prefix + "    " + l_keys.item (i) + ": " + v + "%N")
					end
					i := i + 1
				end
			end
		end

	truncate (a_string: STRING; a_max: INTEGER): STRING
			-- Truncate string to max length.
		do
			if a_string.count <= a_max then
				Result := a_string
			else
				Result := a_string.substring (1, a_max) + "..."
			end
		end

note
	copyright: "Copyright (c) 2024-2025, Larry Rix"
	license: "MIT License"

end
