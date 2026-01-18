note
	description: "Configurable retry policy for HTTP requests with exponential backoff"
	author: "Larry Rix"
	date: "$Date$"
	revision: "$Revision$"

class
	SIMPLE_HTTP_RETRY_POLICY

create
	make_default,
	make_custom,
	make_none

feature {NONE} -- Initialization

	make_default
			-- Create default retry policy (3 retries, exponential backoff with jitter).
		do
			max_retries := Default_max_retries
			initial_delay_ms := Default_initial_delay_ms
			max_delay_ms := Default_max_delay_ms
			use_jitter := True
			create retryable_status_codes.make (4)
			retryable_status_codes.extend (Status_too_many_requests)
			retryable_status_codes.extend (Status_bad_gateway)
			retryable_status_codes.extend (Status_service_unavailable)
			retryable_status_codes.extend (Status_gateway_timeout)
			retry_on_network_error := True
		end

	make_custom (a_max_retries, a_initial_ms, a_max_ms: INTEGER; a_jitter: BOOLEAN)
			-- Create custom retry policy.
		require
			non_negative_retries: a_max_retries >= 0
			positive_initial: a_initial_ms > 0
			positive_max: a_max_ms > 0
			max_greater_than_initial: a_max_ms >= a_initial_ms
		do
			max_retries := a_max_retries
			initial_delay_ms := a_initial_ms
			max_delay_ms := a_max_ms
			use_jitter := a_jitter
			create retryable_status_codes.make (4)
			retryable_status_codes.extend (Status_too_many_requests)
			retryable_status_codes.extend (Status_bad_gateway)
			retryable_status_codes.extend (Status_service_unavailable)
			retryable_status_codes.extend (Status_gateway_timeout)
			retry_on_network_error := True
		ensure
			max_set: max_retries = a_max_retries
			initial_set: initial_delay_ms = a_initial_ms
			max_delay_set: max_delay_ms = a_max_ms
			jitter_set: use_jitter = a_jitter
		end

	make_none
			-- Create policy that never retries.
		do
			max_retries := 0
			initial_delay_ms := Default_initial_delay_ms
			max_delay_ms := Default_initial_delay_ms
			use_jitter := False
			create retryable_status_codes.make (0)
			retry_on_network_error := False
		ensure
			no_retries: max_retries = 0
		end

feature -- Access

	max_retries: INTEGER
			-- Maximum number of retry attempts

	initial_delay_ms: INTEGER
			-- Initial delay in milliseconds before first retry

	max_delay_ms: INTEGER
			-- Maximum delay in milliseconds between retries

	use_jitter: BOOLEAN
			-- Add random jitter to prevent thundering herd?

	retryable_status_codes: ARRAYED_SET [INTEGER]
			-- HTTP status codes that trigger retry

	retry_on_network_error: BOOLEAN
			-- Retry on network/connection errors?

feature -- Configuration

	set_max_retries (a_count: INTEGER)
			-- Set maximum retry attempts.
		require
			non_negative: a_count >= 0
		do
			max_retries := a_count
		ensure
			set: max_retries = a_count
		end

	set_initial_delay (a_ms: INTEGER)
			-- Set initial delay in milliseconds.
		require
			positive: a_ms > 0
		do
			initial_delay_ms := a_ms
		ensure
			set: initial_delay_ms = a_ms
		end

	set_max_delay (a_ms: INTEGER)
			-- Set maximum delay in milliseconds.
		require
			positive: a_ms > 0
		do
			max_delay_ms := a_ms
		ensure
			set: max_delay_ms = a_ms
		end

	enable_jitter
			-- Enable random jitter.
		do
			use_jitter := True
		ensure
			enabled: use_jitter
		end

	disable_jitter
			-- Disable random jitter.
		do
			use_jitter := False
		ensure
			disabled: not use_jitter
		end

	add_retryable_status (a_status: INTEGER)
			-- Add status code that should trigger retry.
		require
			valid_status: a_status >= 100 and a_status < 600
		do
			retryable_status_codes.extend (a_status)
		ensure
			added: retryable_status_codes.has (a_status)
		end

	remove_retryable_status (a_status: INTEGER)
			-- Remove status code from retryable list.
		do
			retryable_status_codes.prune (a_status)
		ensure
			removed: not retryable_status_codes.has (a_status)
		end

	set_retry_on_network_error (a_value: BOOLEAN)
			-- Set whether to retry on network errors.
		do
			retry_on_network_error := a_value
		ensure
			set: retry_on_network_error = a_value
		end

feature -- Query

	should_retry_status (a_status: INTEGER): BOOLEAN
			-- Should retry for this HTTP status code?
		do
			Result := retryable_status_codes.has (a_status)
		end

	should_retry_error: BOOLEAN
			-- Should retry on network/connection error?
		do
			Result := retry_on_network_error
		end

	delay_for_attempt (a_attempt: INTEGER): INTEGER
			-- Calculate delay in milliseconds for given attempt number (1-based).
		require
			valid_attempt: a_attempt >= 1
		local
			l_base_delay: INTEGER
			l_jitter: INTEGER
			l_random: RANDOM
		do
			-- Exponential backoff: initial * 2^(attempt-1)
			l_base_delay := initial_delay_ms * (Exponential_base ^ (a_attempt - 1)).truncated_to_integer

			-- Cap at max delay
			if l_base_delay > max_delay_ms then
				l_base_delay := max_delay_ms
			end

			-- Add jitter (0-50% of base delay)
			if use_jitter and l_base_delay > 0 then
				-- Use attempt number and base delay for pseudo-random jitter
				increment_jitter_seed
				create l_random.set_seed (jitter_seed)
				l_random.forth
				l_jitter := (l_random.item \\ (l_base_delay // Jitter_divisor + 1)).abs
				Result := l_base_delay + l_jitter
			else
				Result := l_base_delay
			end
		ensure
			non_negative: Result >= 0
			within_max: Result <= max_delay_ms * 2 -- With jitter can exceed slightly
		end

feature {NONE} -- Jitter Implementation

	jitter_seed: INTEGER
			-- Seed for jitter randomization

	increment_jitter_seed
			-- Increment seed for next random value.
		do
			jitter_seed := jitter_seed + Jitter_seed_increment
			if jitter_seed < 0 then
				jitter_seed := 1
			end
		end

feature {NONE} -- Constants

	Default_max_retries: INTEGER = 3
			-- Default maximum retry attempts

	Default_initial_delay_ms: INTEGER = 100
			-- Default initial delay in milliseconds

	Default_max_delay_ms: INTEGER = 30000
			-- Default maximum delay in milliseconds (30 seconds)

	Status_too_many_requests: INTEGER = 429
			-- HTTP 429 Too Many Requests

	Status_bad_gateway: INTEGER = 502
			-- HTTP 502 Bad Gateway

	Status_service_unavailable: INTEGER = 503
			-- HTTP 503 Service Unavailable

	Status_gateway_timeout: INTEGER = 504
			-- HTTP 504 Gateway Timeout

	Exponential_base: INTEGER = 2
			-- Base for exponential backoff calculation

	Jitter_divisor: INTEGER = 2
			-- Divisor for jitter range (50% of base delay)

	Jitter_seed_increment: INTEGER = 12345
			-- Increment for pseudo-random jitter seed

invariant
	non_negative_max_retries: max_retries >= 0
	positive_initial_delay: initial_delay_ms > 0
	positive_max_delay: max_delay_ms > 0
	max_at_least_initial: max_delay_ms >= initial_delay_ms
	status_codes_not_void: retryable_status_codes /= Void

note
	copyright: "Copyright (c) 2024-2025, Larry Rix"
	license: "MIT License"

end
