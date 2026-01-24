# S05 - Constraints

**Library:** simple_http
**Status:** BACKWASH (reverse-engineered from implementation)
**Generated:** 2026-01-23

## Type Constraints

### URL Constraints
- URLs must be non-empty strings
- URLs are automatically upgraded from HTTP to HTTPS
- Query parameters are URL-encoded via SIMPLE_ZSTRING_ESCAPER
- Fragment identifiers (#) not explicitly handled

### String Constraints
- Headers use STRING (8-bit)
- Body can be STRING or SIMPLE_JSON_OBJECT
- Response body uses READABLE_STRING_8
- Decoded body uses STRING_32 (Unicode)

### Timeout Constraints
- Timeouts are in seconds (INTEGER)
- Must be non-negative
- Zero means no timeout (depends on ISE implementation)

## Operational Constraints

### Retry Behavior
- Only idempotent methods are retried by default:
  - GET, PUT, DELETE, HEAD, PATCH: Retried
  - POST: NOT retried (non-idempotent)
- Retry on status codes: 429 (Too Many Requests), 5xx
- Retry on connection errors
- Exponential backoff with jitter
- Respects Retry-After header on 429/503

### Redirect Behavior
- Default: Follow up to 10 redirects
- Redirect following can be disabled
- POST/PUT body handling on redirects: ISE library behavior

### Cookie Behavior
- Cookies disabled by default
- Manual enable required via enable_cookies
- Cookies extracted from Set-Cookie header
- Cookies sent via Cookie header
- No domain/path matching (simple jar)
- No expiration handling

### Interceptor Behavior
- Interceptors called in order added
- before_request called for all requests
- after_response called for all responses
- on_error called on transport errors
- Interceptors cannot abort requests

## Network Constraints

### Underlying Transport
- Uses ISE NET_HTTP_CLIENT
- HTTP/1.1 protocol
- HTTPS via ISE SSL support
- No HTTP/2 support

### Connection Constraints
- Connection timeout configurable
- Request timeout configurable
- Keep-alive handled by ISE library
- Connection pooling: ISE library behavior

## Encoding Constraints

### Character Encoding
- Request body assumed UTF-8
- Response body decoded per charset
- Default charset: UTF-8
- Fallback: Latin-1 for unknown charsets

### Content Type
- JSON: application/json
- Form: application/x-www-form-urlencoded
- Content-Type header set manually or via helpers

### URL Encoding
- Query parameters automatically encoded
- Uses SIMPLE_ZSTRING_ESCAPER
- Handles special characters

## Error Handling Constraints

### Response States
- is_success: Status 200-299
- is_redirect: Status 300-399
- is_client_error: Status 400-499
- is_server_error: Status 500-599
- error_occurred: Transport/network error

### No Exceptions
- Errors returned in response object
- Check error_occurred and error_message
- Status code 0 may indicate connection failure

## Performance Constraints

### Memory Usage
- Entire response body loaded into memory
- JSON parsing caches result
- No streaming for large responses

### Time Limits
- Default request timeout: 30 seconds
- Default connect timeout: 10 seconds
- Retry delays add to total time

### Retry Timing
- Initial delay: 100ms (configurable)
- Maximum delay: 30s (configurable)
- Exponential: delay * 2^attempt

## Thread Safety Constraints

### Not Thread-Safe
- SIMPLE_HTTP not thread-safe
- Shared headers/params not synchronized
- One request at a time per client instance

### Recommended Usage
- One client per thread
- Or external synchronization
- SCOOP not directly supported

## JSON Constraints

### Parsing
- Uses SIMPLE_JSON from ecosystem
- Caches parsed result
- Returns Void for invalid JSON
- No schema validation

### Access
- json_string returns STRING (8-bit)
- json_integer returns 0 if not found
- json_boolean returns False if not found
- No deep path access (single level)
