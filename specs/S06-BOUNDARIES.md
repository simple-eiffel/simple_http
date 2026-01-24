# S06 - Boundaries

**Library:** simple_http
**Status:** BACKWASH (reverse-engineered from implementation)
**Generated:** 2026-01-23

## Scope Boundaries

### In Scope

1. **HTTP Methods**
   - GET, POST, PUT, DELETE, HEAD, PATCH
   - JSON body variants for POST, PUT, PATCH
   - Custom headers and query parameters

2. **Authentication**
   - Bearer token
   - Basic authentication
   - API key (any header)
   - Custom Authorization header

3. **Response Handling**
   - Status code access
   - Header parsing
   - Body as string/bytes
   - Charset detection and decoding
   - JSON parsing (object, array, values)

4. **Retry Support**
   - Configurable retry count
   - Exponential backoff
   - Status code filtering
   - Retry-After header support

5. **Redirect Support**
   - Configurable max redirects
   - Enable/disable following

6. **Cookie Support**
   - Enable/disable
   - Manual set/get
   - Automatic from Set-Cookie

7. **Interceptors**
   - Before request hooks
   - After response hooks
   - Error hooks

8. **Fluent Builder**
   - Method chaining for request construction

### Out of Scope

1. **Advanced HTTP**
   - HTTP/2
   - WebSockets
   - Server-Sent Events
   - Chunked transfer encoding (manual)

2. **File Handling**
   - File uploads (multipart/form-data)
   - File downloads (streaming)
   - Range requests

3. **Advanced Authentication**
   - OAuth 2.0 flows
   - JWT refresh
   - Digest authentication
   - NTLM/Kerberos

4. **Caching**
   - HTTP cache (ETag, If-Modified-Since)
   - Response caching
   - Cache-Control handling

5. **Proxy Support**
   - HTTP proxies
   - SOCKS proxies
   - Proxy authentication

6. **Advanced Cookies**
   - Domain/path matching
   - Expiration handling
   - Secure/HttpOnly flags
   - Cookie persistence

7. **Connection Management**
   - Connection pooling (manual)
   - Keep-alive control
   - Connection limiting

8. **Metrics/Observability**
   - Request timing
   - Metrics collection
   - Distributed tracing

## API Boundaries

### Public API

All features in all 6 classes are public.

### Internal API (feature {NONE})

| Class | Feature | Purpose |
|-------|---------|---------|
| SIMPLE_HTTP | client | Underlying NET_HTTP_CLIENT |
| SIMPLE_HTTP | custom_headers | Header storage |
| SIMPLE_HTTP | query_params | Query parameter storage |
| SIMPLE_HTTP | configure_session | Session setup |
| SIMPLE_HTTP | build_url | URL construction |
| SIMPLE_HTTP | url_encode | URL encoding |
| SIMPLE_HTTP | execute_with_retry | Retry logic |
| SIMPLE_HTTP | execute_single_request | Single request |
| SIMPLE_HTTP_RESPONSE | json_parsed | Parse state |
| SIMPLE_HTTP_RESPONSE | cached_json | Cached parse result |
| SIMPLE_HTTP_RESPONSE | parse_headers | Header parsing |

### Extension Points

1. **SIMPLE_HTTP_INTERCEPTOR**
   - Inherit to create custom interceptors
   - Implement before_request, after_response, on_error

2. **SIMPLE_HTTP_RETRY_POLICY**
   - Override should_retry_status for custom logic
   - Override delay_for_attempt for custom delays

3. **SIMPLE_HTTP_COOKIE_JAR**
   - Inherit for advanced cookie handling
   - Override extract_cookies_from_response

## Dependency Boundaries

### Required Dependencies
- EiffelStudio base library
- EiffelStudio net/http_client
- EiffelStudio time library
- simple_json
- simple_base64
- simple_encoding

### No Dependencies On
- File I/O libraries
- Database libraries
- GUI libraries

## Data Boundaries

### Input Boundaries
- URL: STRING (8-bit, must be valid URL)
- Headers: STRING key-value pairs
- Query params: STRING key-value pairs
- Body: STRING or SIMPLE_JSON_OBJECT
- Timeout: INTEGER (seconds)

### Output Boundaries
- Status: INTEGER (0-599)
- Body: READABLE_STRING_8 (raw)
- Body: STRING_32 (decoded)
- Headers: HASH_TABLE [STRING, STRING]
- JSON: SIMPLE_JSON_VALUE hierarchy

### Size Limits
- Body size: Memory limited
- Header count: No explicit limit
- URL length: OS/server dependent
- Cookie count: No explicit limit

## Error Boundaries

### Recoverable Errors
- HTTP 4xx/5xx responses
- Connection timeouts
- DNS resolution failures
- Retry-able status codes

### Non-Recoverable Errors
- Out of memory
- Invalid URL format
- SSL/TLS failures (depends on ISE)

### Not Handled
- Partial responses
- Interrupted transfers
- Certificate validation errors (ISE dependent)
