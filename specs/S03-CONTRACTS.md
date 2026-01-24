# S03 - Contracts

**Library:** simple_http
**Status:** BACKWASH (reverse-engineered from implementation)
**Generated:** 2026-01-23

## SIMPLE_HTTP Contracts

### Timeout Contracts

#### set_timeout (a_seconds: INTEGER)
```eiffel
require
    non_negative: a_seconds >= 0
ensure
    set: timeout = a_seconds
```

#### set_connect_timeout (a_seconds: INTEGER)
```eiffel
require
    non_negative: a_seconds >= 0
ensure
    set: connect_timeout = a_seconds
```

### Redirect Contracts

#### set_max_redirects (a_count: INTEGER)
```eiffel
require
    non_negative: a_count >= 0
ensure
    set: max_redirects = a_count
    disabled_if_zero: a_count = 0 implies not follow_redirects
```

#### set_follow_redirects (a_value: BOOLEAN)
```eiffel
ensure
    set: follow_redirects = a_value
```

### Retry Contracts

#### set_retry_policy (a_policy: SIMPLE_HTTP_RETRY_POLICY)
```eiffel
require
    policy_not_void: a_policy /= Void
ensure
    set: retry_policy = a_policy
```

#### enable_retry_custom (a_max_retries: INTEGER)
```eiffel
require
    positive: a_max_retries > 0
```

#### disable_retry
```eiffel
ensure
    disabled: retry_policy.max_retries = 0
```

### Header Contracts

#### add_header (a_name, a_value: STRING)
```eiffel
require
    name_not_empty: not a_name.is_empty
    value_not_empty: not a_value.is_empty
ensure
    header_set: custom_headers.has (a_name)
```

#### set_headers (a_headers: HASH_TABLE [STRING, STRING])
```eiffel
require
    headers_not_void: a_headers /= Void
```

#### remove_header (a_name: STRING)
```eiffel
require
    name_not_empty: not a_name.is_empty
ensure
    removed: not custom_headers.has (a_name)
```

#### clear_headers
```eiffel
ensure
    empty: custom_headers.is_empty
```

### Authentication Contracts

#### set_bearer_token (a_token: STRING)
```eiffel
require
    token_not_empty: not a_token.is_empty
```

#### set_basic_auth (a_username, a_password: STRING)
```eiffel
require
    username_not_empty: not a_username.is_empty
```

#### set_auth_header (a_value: STRING)
```eiffel
require
    value_not_empty: not a_value.is_empty
```

#### set_api_key (a_header_name, a_key: STRING)
```eiffel
require
    header_name_not_empty: not a_header_name.is_empty
    key_not_empty: not a_key.is_empty
```

### Query Parameter Contracts

#### add_query (a_name, a_value: STRING)
```eiffel
require
    name_not_empty: not a_name.is_empty
ensure
    param_set: query_params.has (a_name)
```

#### set_queries (a_params: HASH_TABLE [STRING, STRING])
```eiffel
require
    params_not_void: a_params /= Void
```

#### remove_query (a_name: STRING)
```eiffel
require
    name_not_empty: not a_name.is_empty
ensure
    removed: not query_params.has (a_name)
```

#### clear_queries
```eiffel
ensure
    empty: query_params.is_empty
```

### HTTP Method Contracts

#### get (a_url: STRING): SIMPLE_HTTP_RESPONSE
```eiffel
require
    url_not_empty: not a_url.is_empty
```

#### post (a_url: STRING; a_data: detachable STRING): SIMPLE_HTTP_RESPONSE
```eiffel
require
    url_not_empty: not a_url.is_empty
```

#### post_json (a_url: STRING; a_json: SIMPLE_JSON_OBJECT): SIMPLE_HTTP_RESPONSE
```eiffel
require
    url_not_empty: not a_url.is_empty
    json_not_void: a_json /= Void
```

#### put (a_url: STRING; a_data: detachable STRING): SIMPLE_HTTP_RESPONSE
```eiffel
require
    url_not_empty: not a_url.is_empty
```

#### put_json (a_url: STRING; a_json: SIMPLE_JSON_OBJECT): SIMPLE_HTTP_RESPONSE
```eiffel
require
    url_not_empty: not a_url.is_empty
    json_not_void: a_json /= Void
```

#### delete (a_url: STRING): SIMPLE_HTTP_RESPONSE
```eiffel
require
    url_not_empty: not a_url.is_empty
```

#### head (a_url: STRING): SIMPLE_HTTP_RESPONSE
```eiffel
require
    url_not_empty: not a_url.is_empty
```

#### patch (a_url: STRING; a_data: detachable STRING): SIMPLE_HTTP_RESPONSE
```eiffel
require
    url_not_empty: not a_url.is_empty
```

#### patch_json (a_url: STRING; a_json: SIMPLE_JSON_OBJECT): SIMPLE_HTTP_RESPONSE
```eiffel
require
    url_not_empty: not a_url.is_empty
    json_not_void: a_json /= Void
```

### Interceptor Contracts

#### add_interceptor (a_interceptor: SIMPLE_HTTP_INTERCEPTOR)
```eiffel
require
    interceptor_not_void: a_interceptor /= Void
ensure
    added: interceptors.has (a_interceptor)
```

#### remove_interceptor (a_interceptor: SIMPLE_HTTP_INTERCEPTOR)
```eiffel
require
    interceptor_not_void: a_interceptor /= Void
ensure
    removed: not interceptors.has (a_interceptor)
```

#### clear_interceptors
```eiffel
ensure
    empty: interceptors.is_empty
```

### Cookie Contracts

#### enable_cookies
```eiffel
ensure
    enabled: cookies_enabled
```

#### disable_cookies
```eiffel
ensure
    disabled: not cookies_enabled
```

#### set_cookie (a_name, a_value: STRING)
```eiffel
require
    name_not_empty: not a_name.is_empty
    cookies_enabled: cookies_enabled
```

#### get_cookie (a_name: STRING): detachable STRING
```eiffel
require
    name_not_empty: not a_name.is_empty
```

---

## SIMPLE_HTTP_RESPONSE Contracts

### Header Access Contracts

#### json_string (a_key: STRING): detachable STRING
```eiffel
require
    key_not_empty: not a_key.is_empty
```

#### json_integer (a_key: STRING): INTEGER
```eiffel
require
    key_not_empty: not a_key.is_empty
```

#### json_boolean (a_key: STRING): BOOLEAN
```eiffel
require
    key_not_empty: not a_key.is_empty
```

#### json_has_key (a_key: STRING): BOOLEAN
```eiffel
require
    key_not_empty: not a_key.is_empty
```

### Body Contracts

#### body_text: STRING_32
```eiffel
ensure
    result_attached: Result /= Void
```

---

## SIMPLE_HTTP_RETRY_POLICY Contracts

### Creation Contracts

#### make_custom (a_max_retries, a_initial_delay_ms, a_max_delay_ms: INTEGER; a_exponential: BOOLEAN)
```eiffel
require
    valid_max_retries: a_max_retries >= 0
    valid_initial_delay: a_initial_delay_ms >= 0
    valid_max_delay: a_max_delay_ms >= a_initial_delay_ms
```
