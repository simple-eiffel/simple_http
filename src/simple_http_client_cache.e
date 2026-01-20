note
	description: "Cached HTTP client pool for connection reuse by host"
	author: "Larry Rix"
	date: "$Date$"
	revision: "$Revision$"

class
	SIMPLE_HTTP_CLIENT_CACHE

create
	make

feature {NONE} -- Initialization

	make
			-- Create HTTP client cache.
		do
			default_timeout := 0
			default_connect_timeout := 0
		ensure
			defaults_set: default_timeout = 0 and default_connect_timeout = 0
		end

feature -- Access

	client_for_host (a_host: STRING): SIMPLE_HTTP
			-- Get or create HTTP client configured for `a_host'.
			-- Clients are cached and reused for the same host.
		require
			host_not_empty: not a_host.is_empty
		do
			Result := internal_cache.item (a_host)
		ensure
			result_exists: Result /= Void
			is_cached: is_cached (a_host)
		end

	is_cached (a_host: STRING): BOOLEAN
			-- Is there a cached client for `a_host'?
		require
			host_not_empty: not a_host.is_empty
		do
			Result := internal_cache.is_cached (a_host)
		end

	cached_count: INTEGER
			-- Number of cached clients.
		do
			Result := internal_cache.cached_count
		end

feature -- Configuration

	default_timeout: INTEGER
			-- Default timeout for new clients (0 = use client default).
		attribute
		end

	default_connect_timeout: INTEGER
			-- Default connect timeout for new clients (0 = use client default).
		attribute
		end

	set_default_timeout (a_seconds: INTEGER)
			-- Set default timeout for new clients.
		require
			positive: a_seconds >= 0
		do
			default_timeout := a_seconds
		ensure
			set: default_timeout = a_seconds
		end

	set_default_connect_timeout (a_seconds: INTEGER)
			-- Set default connect timeout for new clients.
		require
			positive: a_seconds >= 0
		do
			default_connect_timeout := a_seconds
		ensure
			set: default_connect_timeout = a_seconds
		end

feature -- Cache Management

	invalidate (a_host: STRING)
			-- Remove cached client for `a_host'.
		require
			host_not_empty: not a_host.is_empty
		do
			internal_cache.invalidate (a_host)
		ensure
			not_cached: not is_cached (a_host)
		end

	invalidate_all
			-- Clear all cached clients.
		do
			internal_cache.invalidate_all
		ensure
			empty: cached_count = 0
		end

feature {NONE} -- Implementation

	internal_cache: SIMPLE_CACHED_VALUE [SIMPLE_HTTP, STRING]
			-- Cache of HTTP clients by host (lazy initialization).
		once ("OBJECT")
			create Result.make (agent create_client_for_host)
		end

	create_client_for_host (a_host: STRING): SIMPLE_HTTP
			-- Create new HTTP client for `a_host'.
		do
			create Result.make
			if default_timeout > 0 then
				Result.set_timeout (default_timeout)
			end
			if default_connect_timeout > 0 then
				Result.set_connect_timeout (default_connect_timeout)
			end
		end

invariant
	count_non_negative: cached_count >= 0

note
	copyright: "Copyright (c) 2024-2025, Larry Rix"
	license: "MIT License"

end
