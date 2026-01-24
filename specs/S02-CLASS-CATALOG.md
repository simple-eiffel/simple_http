# S02 - Class Catalog

**Library:** simple_http
**Status:** BACKWASH (reverse-engineered from implementation)
**Generated:** 2026-01-23

## Class Hierarchy

```
ANY
 +-- SIMPLE_HTTP                    [Main HTTP client]
 +-- SIMPLE_HTTP_RESPONSE           [Response wrapper]
 +-- SIMPLE_HTTP_REQUEST_BUILDER    [Fluent builder]
 +-- SIMPLE_HTTP_RETRY_POLICY       [Retry configuration]
 +-- SIMPLE_HTTP_INTERCEPTOR        [Deferred interceptor]
 +-- SIMPLE_HTTP_COOKIE_JAR         [Cookie storage]
```

## Class Details

### SIMPLE_HTTP

**Purpose:** Main HTTP client facade for making web requests.

**Responsibilities:**
- Execute HTTP methods (GET, POST, PUT, DELETE, HEAD, PATCH)
- Manage custom headers and query parameters
- Handle authentication (Bearer, Basic, API Key)
- Configure timeouts and redirect behavior
- Retry failed requests with exponential backoff
- Manage cookies
- Chain interceptors

**Creation Procedures:**
- `make` - Create HTTP client

**Internal Components:**
- `client: NET_HTTP_CLIENT` - Underlying ISE HTTP client
- `custom_headers: HASH_TABLE [STRING, STRING]` - Request headers
- `query_params: HASH_TABLE [STRING, STRING]` - URL query parameters
- `interceptors: ARRAYED_LIST [SIMPLE_HTTP_INTERCEPTOR]` - Interceptor chain
- `cookie_jar: detachable SIMPLE_HTTP_COOKIE_JAR` - Cookie storage

**Collaborators:**
- NET_HTTP_CLIENT (delegation for actual HTTP)
- SIMPLE_HTTP_RESPONSE (result type)
- SIMPLE_HTTP_RETRY_POLICY (retry configuration)
- SIMPLE_HTTP_INTERCEPTOR (request/response hooks)
- SIMPLE_HTTP_COOKIE_JAR (cookie management)
- SIMPLE_BASE64 (Basic auth encoding)
- SIMPLE_ZSTRING_ESCAPER (URL encoding)

---

### SIMPLE_HTTP_RESPONSE

**Purpose:** Wrapper around HTTP_CLIENT_RESPONSE with JSON parsing.

**Responsibilities:**
- Store status, body, headers
- Parse headers into hash table
- Detect content type and charset
- Parse JSON (cached)
- Provide convenience JSON accessors

**Creation Procedures:**
- `make_from_response (a_response: HTTP_CLIENT_RESPONSE)`

**Collaborators:**
- SIMPLE_JSON (JSON parsing)
- SIMPLE_ENCODING (charset conversion)

---

### SIMPLE_HTTP_REQUEST_BUILDER

**Purpose:** Fluent builder for HTTP requests.

**Responsibilities:**
- Build request step by step
- Configure method, URL, headers, body
- Execute and return response

**Creation Procedures:**
- `make (a_client: SIMPLE_HTTP)`

**Fluent Methods:**
- url, method, header, query, body, json_body
- timeout, auth_bearer, auth_basic
- get, post, put, delete (terminal operations)

**Collaborators:**
- SIMPLE_HTTP (for execution)

---

### SIMPLE_HTTP_RETRY_POLICY

**Purpose:** Configuration for automatic request retries.

**Responsibilities:**
- Define max retry count
- Configure retry delay (initial, max, exponential)
- Determine which status codes to retry
- Determine if errors should be retried

**Creation Procedures:**
- `make_none` - No retries
- `make_default` - 3 retries, exponential backoff
- `make_custom (max_retries, initial_delay_ms, max_delay_ms, exponential)`

**Collaborators:**
- SIMPLE_HTTP (used by)

---

### SIMPLE_HTTP_INTERCEPTOR (Deferred)

**Purpose:** Interface for request/response interceptors.

**Responsibilities:**
- Hook before request
- Hook after response
- Hook on error

**Deferred Features:**
- `before_request (url, method, headers, body)`
- `after_response (url, method, response)`
- `on_error (url, method, error)`

**Usage:**
- Logging interceptor
- Metrics interceptor
- Caching interceptor
- Authentication refresh

---

### SIMPLE_HTTP_COOKIE_JAR

**Purpose:** Storage for HTTP cookies.

**Responsibilities:**
- Store cookies by name
- Extract cookies from Set-Cookie headers
- Generate Cookie header for requests
- Clear cookies

**Creation Procedures:**
- `make` - Create empty cookie jar

**Collaborators:**
- SIMPLE_HTTP (used by)
- SIMPLE_HTTP_RESPONSE (extracts cookies from)

## Design Patterns

### Facade Pattern
SIMPLE_HTTP provides a unified interface over NET_HTTP_CLIENT with additional features.

### Builder Pattern
SIMPLE_HTTP_REQUEST_BUILDER enables fluent request construction.

### Strategy Pattern
SIMPLE_HTTP_RETRY_POLICY encapsulates retry behavior.

### Chain of Responsibility
Interceptors form a chain for request/response processing.

### Template Method
SIMPLE_HTTP_INTERCEPTOR defines hooks with empty default implementations.
