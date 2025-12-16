# SIMPLE_HTTP

Simple HTTP client for making web requests in Eiffel applications.

## Features

- HTTP methods: GET, POST, PUT, DELETE, HEAD, PATCH
- JSON request/response support
- Custom headers and query parameters
- Authentication (Bearer, Basic, API key)
- Automatic retry with exponential backoff
- Cookie management
- Redirect handling
- Request interceptors
- Fluent request builder API
- Timeout configuration

## Installation

Set the ecosystem environment variable (one-time setup for all simple_* libraries):
```
SIMPLE_EIFFEL=D:\prod
```

Add to your ECF file:

```xml
<library name="simple_http" location="$SIMPLE_EIFFEL/simple_http/simple_http.ecf"/>
```

## Quick Start (Zero-Configuration)

Use `SIMPLE_HTTP_QUICK` for the simplest possible HTTP operations:

```eiffel
local
    http: SIMPLE_HTTP_QUICK
do
    create http.make

    -- GET request returns body directly
    print (http.get ("https://api.example.com/data"))

    -- GET JSON parses automatically
    if attached http.get_json ("https://api.example.com/users/1") as user then
        print (user.string_item ("name"))
    end

    -- POST form data
    print (http.post ("https://api.example.com/login", "user=alice&pass=secret"))

    -- POST JSON
    if attached {SIMPLE_JSON_VALUE} my_json as json then
        print (http.post_json ("https://api.example.com/users", json))
    end

    -- Download file
    if http.download ("https://example.com/file.zip", "C:\downloads\file.zip") then
        print ("Downloaded successfully")
    end

    -- Authentication
    http.set_bearer_token ("my-api-token")
    http.set_basic_auth ("username", "password")

    -- Error handling
    if http.has_error then
        print ("Error: HTTP " + http.last_status_code.out)
    end
end
```

## Standard API (Full Control)

Use `SIMPLE_HTTP` for complete control over requests:

```eiffel
local
    http: SIMPLE_HTTP
    response: SIMPLE_HTTP_RESPONSE
do
    create http.make

    -- Simple GET request
    response := http.get ("https://api.example.com/users")
    if response.is_success then
        print (response.body)
    end

    -- POST with JSON
    http.set_content_type_json
    response := http.post ("https://api.example.com/users",
        "{%"name%": %"John%"}")
end
```

## API Overview

### HTTP Methods
| Feature | Description |
|---------|-------------|
| `get (url)` | GET request |
| `post (url, data)` | POST request |
| `put (url, data)` | PUT request |
| `delete (url)` | DELETE request |
| `head (url)` | HEAD request |
| `patch (url, data)` | PATCH request |

### Configuration
| Feature | Description |
|---------|-------------|
| `set_timeout` | Request timeout |
| `set_connect_timeout` | Connection timeout |
| `set_max_redirects` | Max redirects to follow |
| `add_header` | Add custom header |
| `add_query` | Add query parameter |

### Authentication
| Feature | Description |
|---------|-------------|
| `set_bearer_token` | Set Bearer auth |
| `set_basic_auth` | Set Basic auth |
| `set_api_key` | Set API key header |

### Retry Support
| Feature | Description |
|---------|-------------|
| `enable_retry` | Default retry policy |
| `enable_retry_custom` | Custom retry settings |
| `set_retry_policy` | Full retry configuration |

### Cookies
| Feature | Description |
|---------|-------------|
| `enable_cookies` | Enable cookie management |
| `set_cookie` | Set a cookie |
| `get_cookie` | Get cookie value |
| `clear_cookies` | Clear all cookies |

## Fluent Builder

```eiffel
response := http.request
    .url ("https://api.example.com/users")
    .header ("X-Custom", "value")
    .query ("page", "1")
    .bearer_token ("my-token")
    .timeout (30)
    .get
```

## Documentation

- [API Documentation](https://simple-eiffel.github.io/simple_http/)

## Dependencies

- simple_base64 (for Basic auth)
- simple_json (for JSON methods)

## License

MIT License - see LICENSE file for details.

## Author

Larry Rix
