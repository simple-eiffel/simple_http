# S04 - Feature Specifications

**Library:** simple_http
**Status:** BACKWASH (reverse-engineered from implementation)
**Generated:** 2026-01-23

## SIMPLE_HTTP Features

### Initialization

| Feature | Signature | Description |
|---------|-----------|-------------|
| make | () | Create HTTP client |

### Access

| Feature | Returns | Description |
|---------|---------|-------------|
| timeout | INTEGER | Request timeout in seconds |
| connect_timeout | INTEGER | Connection timeout in seconds |
| max_redirects | INTEGER | Maximum redirects to follow |
| follow_redirects | BOOLEAN | Follow redirects? |
| retry_policy | SIMPLE_HTTP_RETRY_POLICY | Current retry policy |
| last_response | detachable SIMPLE_HTTP_RESPONSE | Last response |
| retry_count | INTEGER | Retries on last request |
| cookies_enabled | BOOLEAN | Cookie management enabled? |

### Timeout Settings

| Feature | Signature | Description |
|---------|-----------|-------------|
| set_timeout | (a_seconds) | Set request timeout |
| set_connect_timeout | (a_seconds) | Set connection timeout |

### Redirect Settings

| Feature | Signature | Description |
|---------|-----------|-------------|
| set_max_redirects | (a_count) | Set max redirects (0 disables) |
| set_follow_redirects | (a_value) | Enable/disable redirects |

### Retry Settings

| Feature | Signature | Description |
|---------|-----------|-------------|
| set_retry_policy | (a_policy) | Set retry policy |
| enable_retry | () | Enable default retry (3 retries) |
| enable_retry_custom | (a_max_retries) | Enable custom retry count |
| disable_retry | () | Disable retries |

### Header Management

| Feature | Signature | Description |
|---------|-----------|-------------|
| add_header | (a_name, a_value) | Add custom header |
| set_headers | (a_headers) | Set multiple headers |
| remove_header | (a_name) | Remove header |
| clear_headers | () | Remove all headers |

### Authentication

| Feature | Signature | Description |
|---------|-----------|-------------|
| set_bearer_token | (a_token) | Set Bearer token |
| set_basic_auth | (a_username, a_password) | Set Basic auth |
| set_auth_header | (a_value) | Set Authorization directly |
| set_api_key | (a_header_name, a_key) | Set API key in header |

### Query Parameters

| Feature | Signature | Description |
|---------|-----------|-------------|
| add_query | (a_name, a_value) | Add query parameter |
| set_queries | (a_params) | Set multiple parameters |
| remove_query | (a_name) | Remove parameter |
| clear_queries | () | Remove all parameters |

### Content Type Helpers

| Feature | Signature | Description |
|---------|-----------|-------------|
| set_accept_json | () | Set Accept: application/json |
| set_content_type_json | () | Set Content-Type: application/json |
| set_content_type_form | () | Set Content-Type: application/x-www-form-urlencoded |

### HTTP Methods

| Feature | Signature | Returns | Description |
|---------|-----------|---------|-------------|
| get | (a_url) | SIMPLE_HTTP_RESPONSE | GET request (retried) |
| post | (a_url, a_data) | SIMPLE_HTTP_RESPONSE | POST request (not retried) |
| post_json | (a_url, a_json) | SIMPLE_HTTP_RESPONSE | POST with JSON body |
| put | (a_url, a_data) | SIMPLE_HTTP_RESPONSE | PUT request (retried) |
| put_json | (a_url, a_json) | SIMPLE_HTTP_RESPONSE | PUT with JSON body |
| delete | (a_url) | SIMPLE_HTTP_RESPONSE | DELETE request (retried) |
| head | (a_url) | SIMPLE_HTTP_RESPONSE | HEAD request (retried) |
| patch | (a_url, a_data) | SIMPLE_HTTP_RESPONSE | PATCH request (retried) |
| patch_json | (a_url, a_json) | SIMPLE_HTTP_RESPONSE | PATCH with JSON body |

### Status Report

| Feature | Returns | Description |
|---------|---------|-------------|
| is_success | BOOLEAN | Last response 2xx? |
| has_error | BOOLEAN | Last response had error? |

### Request Builder

| Feature | Returns | Description |
|---------|---------|-------------|
| request | SIMPLE_HTTP_REQUEST_BUILDER | Create fluent builder |

### Interceptors

| Feature | Signature | Description |
|---------|-----------|-------------|
| add_interceptor | (a_interceptor) | Add interceptor |
| remove_interceptor | (a_interceptor) | Remove interceptor |
| clear_interceptors | () | Remove all interceptors |

### Cookie Management

| Feature | Signature | Description |
|---------|-----------|-------------|
| enable_cookies | () | Enable cookie handling |
| disable_cookies | () | Disable cookie handling |
| clear_cookies | () | Clear all cookies |
| set_cookie | (a_name, a_value) | Set cookie manually |
| get_cookie | (a_name): detachable STRING | Get cookie value |

### Constants

| Constant | Value | Description |
|----------|-------|-------------|
| Default_timeout_seconds | 30 | Default request timeout |
| Default_connect_timeout_seconds | 10 | Default connect timeout |
| Default_max_redirects | 10 | Default max redirects |
| Default_initial_delay_ms | 100 | Default initial retry delay |
| Default_max_delay_ms | 30000 | Default max retry delay |

---

## SIMPLE_HTTP_RESPONSE Features

### Access

| Feature | Returns | Description |
|---------|---------|-------------|
| status | INTEGER | HTTP status code |
| body | detachable READABLE_STRING_8 | Response body |
| raw_header | READABLE_STRING_8 | Raw HTTP headers |
| error_message | detachable READABLE_STRING_8 | Error message if any |
| headers | HASH_TABLE [STRING, STRING] | Parsed headers |

### Header Access

| Feature | Returns | Description |
|---------|---------|-------------|
| header (a_name) | detachable STRING | Get header (case-insensitive) |
| content_type | detachable STRING | Content-Type header |
| charset | detachable STRING | Charset from Content-Type |
| content_length | INTEGER | Content-Length (0 if none) |

### Status Report

| Feature | Returns | Description |
|---------|---------|-------------|
| is_success | BOOLEAN | Status 2xx? |
| is_redirect | BOOLEAN | Status 3xx? |
| is_client_error | BOOLEAN | Status 4xx? |
| is_server_error | BOOLEAN | Status 5xx? |
| has_error | BOOLEAN | Error occurred? |
| error_occurred | BOOLEAN | Transport error? |
| is_json_content | BOOLEAN | Content-Type is JSON? |

### Output

| Feature | Returns | Description |
|---------|---------|-------------|
| body_string | STRING | Body as STRING |
| body_text | STRING_32 | Body decoded with charset |

### JSON Access

| Feature | Returns | Description |
|---------|---------|-------------|
| json | detachable SIMPLE_JSON_VALUE | Parsed JSON (cached) |
| json_object | detachable SIMPLE_JSON_OBJECT | Body as JSON object |
| json_array | detachable SIMPLE_JSON_ARRAY | Body as JSON array |
| json_string (a_key) | detachable STRING | Get string from JSON |
| json_integer (a_key) | INTEGER | Get integer from JSON |
| json_boolean (a_key) | BOOLEAN | Get boolean from JSON |
| json_has_key (a_key) | BOOLEAN | Check JSON key exists |

---

## SIMPLE_HTTP_RETRY_POLICY Features

### Initialization

| Feature | Signature | Description |
|---------|-----------|-------------|
| make_none | () | No retries |
| make_default | () | 3 retries, exponential |
| make_custom | (max, initial, max_delay, exp) | Custom configuration |

### Access

| Feature | Returns | Description |
|---------|---------|-------------|
| max_retries | INTEGER | Maximum retry count |
| initial_delay_ms | INTEGER | Initial delay (ms) |
| max_delay_ms | INTEGER | Maximum delay (ms) |
| exponential_backoff | BOOLEAN | Use exponential backoff? |

### Queries

| Feature | Returns | Description |
|---------|---------|-------------|
| should_retry_status (code) | BOOLEAN | Retry this status? |
| should_retry_error | BOOLEAN | Retry on error? |
| delay_for_attempt (attempt) | INTEGER | Delay for attempt (ms) |

---

## SIMPLE_HTTP_INTERCEPTOR Features (Deferred)

| Feature | Signature | Description |
|---------|-----------|-------------|
| before_request | (url, method, headers, body) | Called before request |
| after_response | (url, method, response) | Called after response |
| on_error | (url, method, error) | Called on error |

---

## SIMPLE_HTTP_COOKIE_JAR Features

### Initialization

| Feature | Signature | Description |
|---------|-----------|-------------|
| make | () | Create empty jar |

### Access

| Feature | Returns | Description |
|---------|---------|-------------|
| cookie_value (a_name) | detachable STRING | Get cookie by name |
| cookie_header | STRING | Cookie header string |
| is_empty | BOOLEAN | No cookies stored? |

### Element Change

| Feature | Signature | Description |
|---------|-----------|-------------|
| set_cookie | (a_name, a_value) | Set cookie |
| clear | () | Remove all cookies |
| extract_cookies_from_response | (a_response) | Parse Set-Cookie headers |
