note
	description: "[
		Cached HTTP client pool for connection reuse by host.

		X03 Contract Assault applied: MML model queries for specification.
		Model: MML_MAP [STRING, SIMPLE_HTTP] mapping hosts to cached clients.
	]"
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
			create cached_hosts_internal.make_empty
		ensure
			defaults_set: default_timeout = 0 and default_connect_timeout = 0
			hosts_empty: cached_hosts_internal.is_empty
			model_empty: model_cache.is_empty
		end

feature -- Access

	client_for_host (a_host: STRING): SIMPLE_HTTP
			-- Get or create HTTP client configured for `a_host'.
			-- Clients are cached and reused for the same host.
			-- If already cached, returns the cached client.
			-- If not cached, creates a new client, caches it, and returns it.
		require
			host_not_empty: not a_host.is_empty
		do
			Result := internal_cache.item (a_host)
		ensure
			is_cached: is_cached (a_host)
			in_model_domain: model_cache.domain [a_host]
			returns_cached: model_cache [a_host] = Result
			idempotent: client_for_host (a_host) = Result
		end

	is_cached (a_host: STRING): BOOLEAN
			-- Is there a cached client for `a_host'?
		require
			host_not_empty: not a_host.is_empty
		do
			Result := internal_cache.is_cached (a_host)
		ensure
			definition: Result = model_cache.domain [a_host]
		end

	cached_count: INTEGER
			-- Number of cached clients.
		do
			Result := internal_cache.cached_count
		ensure
			definition: Result = model_cache.count
			non_negative: Result >= 0
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
			remove_cached_host (a_host)
		ensure
			not_cached: not is_cached (a_host)
			not_in_model: not model_cache.domain [a_host]
			count_decreased_or_same: cached_count <= old cached_count
		end

	invalidate_all
			-- Clear all cached clients.
		do
			internal_cache.invalidate_all
			clear_cached_hosts
		ensure
			empty: cached_count = 0
			model_empty: model_cache.is_empty
			model_count_zero: model_cache.count = 0
		end

feature -- Model Queries (Specification)

	model_cache: MML_MAP [STRING, SIMPLE_HTTP]
			-- Mathematical model of cache: host -> client mapping.
			-- Used in contracts to specify cache behavior precisely.
		local
			l_keys: ARRAY [STRING]
			l_i: INTEGER
		do
			create Result
			l_keys := cached_hosts
			from l_i := l_keys.lower until l_i > l_keys.upper loop
				if internal_cache.is_cached (l_keys [l_i]) then
					Result := Result.updated (l_keys [l_i], internal_cache.item (l_keys [l_i]))
				end
				l_i := l_i + 1
			end
		ensure
			count_matches: Result.count = cached_count
		end

	model_hosts: MML_SET [STRING]
			-- Set of all cached host names.
		do
			Result := model_cache.domain
		ensure
			definition: Result |=| model_cache.domain
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
			-- Track the host for model queries
			add_cached_host (a_host)
			create Result.make
			if default_timeout > 0 then
				Result.set_timeout (default_timeout)
			end
			if default_connect_timeout > 0 then
				Result.set_connect_timeout (default_connect_timeout)
			end
		ensure
			host_tracked: across cached_hosts as h some h.is_equal (a_host) end
		end

	cached_hosts_internal: ARRAY [STRING]
			-- Tracked hosts that have been cached (for model query support).
		attribute
		end

	cached_hosts: ARRAY [STRING]
			-- All hosts that have been cached.
		do
			if attached cached_hosts_internal as arr then
				Result := arr
			else
				create Result.make_empty
			end
		end

	add_cached_host (a_host: STRING)
			-- Track a newly cached host.
		local
			l_found: BOOLEAN
			l_i: INTEGER
		do
			if attached cached_hosts_internal as arr then
				from l_i := arr.lower until l_i > arr.upper or l_found loop
					if arr [l_i].is_equal (a_host) then
						l_found := True
					end
					l_i := l_i + 1
				end
				if not l_found then
					arr.force (a_host, arr.upper + 1)
				end
			else
				create cached_hosts_internal.make_filled (a_host, 0, 0)
			end
		end

	remove_cached_host (a_host: STRING)
			-- Remove host from tracking.
		local
			l_new: ARRAY [STRING]
			l_i, l_j: INTEGER
		do
			if attached cached_hosts_internal as arr then
				create l_new.make_empty
				l_j := 0
				from l_i := arr.lower until l_i > arr.upper loop
					if not arr [l_i].is_equal (a_host) then
						l_new.force (arr [l_i], l_j)
						l_j := l_j + 1
					end
					l_i := l_i + 1
				end
				cached_hosts_internal := l_new
			end
		end

	clear_cached_hosts
			-- Remove all hosts from tracking.
		do
			create cached_hosts_internal.make_empty
		ensure
			empty: cached_hosts_internal.is_empty
		end

invariant
	count_non_negative: cached_count >= 0
	model_count_consistent: model_cache.count = cached_count
	model_domain_consistent: model_cache.domain.count = cached_count

note
	copyright: "Copyright (c) 2024-2025, Larry Rix"
	license: "MIT License"

end
