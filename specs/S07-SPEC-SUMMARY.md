# S07 - Specification Summary

**Library:** simple_http
**Status:** BACKWASH (reverse-engineered from implementation)
**Generated:** 2026-01-23

## Executive Summary

simple_http is a high-level HTTP client library for Eiffel that wraps the ISE NET_HTTP_CLIENT with a simplified, feature-rich API. It provides:

1. **SIMPLE_HTTP** - Main HTTP client with all HTTP methods
2. **SIMPLE_HTTP_RESPONSE** - Response wrapper with JSON parsing
3. **SIMPLE_HTTP_REQUEST_BUILDER** - Fluent request construction
4. **SIMPLE_HTTP_RETRY_POLICY** - Configurable retry behavior
5. **SIMPLE_HTTP_INTERCEPTOR** - Request/response hooks
6. **SIMPLE_HTTP_COOKIE_JAR** - Cookie management

## Key Design Decisions

### 1. Simplified API
All common HTTP patterns available with minimal code:
```eiffel
response := http.get (url)
response := http.post_json (url, json)
```

### 2. Automatic JSON Handling
Response JSON parsing is cached and easily accessible:
```eiffel
name := response.json_string ("name")
count := response.json_integer ("count")
```

### 3. Retry with Backoff
Automatic retry for transient failures:
- Exponential backoff
- Respects Retry-After header
- Only retries idempotent methods
- Configurable via policy

### 4. Interceptor Chain
Extensible request/response processing:
- Logging
- Metrics
- Authentication refresh
- Caching

### 5. Fluent Builder
Optional fluent API for complex requests:
```eiffel
response := http.request
    .url (url)
    .header ("X-Custom", "value")
    .auth_bearer (token)
    .get
```

## API Surface Summary

| Class | Purpose | Feature Count |
|-------|---------|---------------|
| SIMPLE_HTTP | Main client | ~50 |
| SIMPLE_HTTP_RESPONSE | Response wrapper | ~25 |
| SIMPLE_HTTP_REQUEST_BUILDER | Fluent builder | ~20 |
| SIMPLE_HTTP_RETRY_POLICY | Retry config | ~10 |
| SIMPLE_HTTP_INTERCEPTOR | Hooks (deferred) | ~3 |
| SIMPLE_HTTP_COOKIE_JAR | Cookie storage | ~6 |

## Usage Patterns

### Basic GET Request
```eiffel
create http.make
response := http.get ("https://api.example.com/users")
if response.is_success then
    users := response.json_array
end
```

### POST with JSON
```eiffel
create json.make
json.put ("name", "John")
json.put ("email", "john@example.com")

http.set_content_type_json
response := http.post_json ("https://api.example.com/users", json)
```

### Authentication
```eiffel
-- Bearer token
http.set_bearer_token (token)

-- Basic auth
http.set_basic_auth (username, password)

-- API key
http.set_api_key ("X-API-Key", key)
```

### Retry Configuration
```eiffel
-- Default: 3 retries, exponential backoff
http.enable_retry

-- Custom
http.enable_retry_custom (5)

-- Disable
http.disable_retry
```

### Cookie Management
```eiffel
http.enable_cookies
response := http.get (login_url)  -- Cookies auto-stored
response := http.get (protected_url)  -- Cookies auto-sent
```

### Interceptors
```eiffel
class LOGGING_INTERCEPTOR inherit SIMPLE_HTTP_INTERCEPTOR
feature
    before_request (url, method, headers, body: ...)
        do
            print ("Request: " + method + " " + url + "%N")
        end

    after_response (url, method, response: ...)
        do
            print ("Response: " + response.status.out + "%N")
        end
end

http.add_interceptor (create {LOGGING_INTERCEPTOR})
```

## Testing Strategy

1. **Unit Tests**: Individual method tests with mock responses
2. **Integration Tests**: Real HTTP requests to test server
3. **Retry Tests**: Verify retry behavior with failing endpoints
4. **JSON Tests**: Parse various JSON structures
5. **Interceptor Tests**: Verify hook invocation

## Known Limitations

1. No HTTP/2 support (ISE library limitation)
2. No file upload (multipart/form-data)
3. No streaming for large responses
4. No advanced cookie features (domain, expiry)
5. Not thread-safe

## Future Enhancements (Proposed)

1. File upload support (multipart)
2. Streaming response support
3. HTTP cache support
4. Proxy configuration
5. OAuth 2.0 helper
6. Connection pooling control
7. Request/response compression
8. Advanced cookie jar (RFC compliant)
