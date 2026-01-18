<p align="center">
  <img src="docs/images/logo.png" alt="simple_http logo" width="200">
</p>

<h1 align="center">simple_http</h1>

<p align="center">
  <a href="https://simple-eiffel.github.io/simple_http/">Documentation</a> •
  <a href="https://github.com/simple-eiffel/simple_http">GitHub</a>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/License-MIT-blue.svg" alt="License: MIT">
  <img src="https://img.shields.io/badge/Eiffel-25.02-purple.svg" alt="Eiffel 25.02">
  <img src="https://img.shields.io/badge/DBC-Contracts-green.svg" alt="Design by Contract">
</p>

**Simple HTTP client for making web requests** — Fluent API, automatic retry, authentication. Part of the [Simple Eiffel](https://github.com/simple-eiffel) ecosystem.

## Status

✅ **Production Ready** — v1.0.0
- All HTTP methods (GET, POST, PUT, DELETE, HEAD, PATCH)
- Authentication (Bearer, Basic, API key)
- Automatic retry with exponential backoff
- Full Design by Contract coverage

## Overview

SIMPLE_HTTP provides a clean HTTP client for Eiffel applications with JSON support, cookie management, redirect handling, and a fluent builder API. It offers both a zero-configuration quick API and a full-control standard API.

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

## API Reference

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

## Features

- ✅ All HTTP methods (GET, POST, PUT, DELETE, HEAD, PATCH)
- ✅ JSON request/response support
- ✅ Custom headers and query parameters
- ✅ Authentication (Bearer, Basic, API key)
- ✅ Automatic retry with exponential backoff
- ✅ Cookie management
- ✅ Redirect handling
- ✅ Request interceptors
- ✅ Fluent request builder API
- ✅ Design by Contract throughout
- ✅ Void-safe
- ✅ SCOOP-compatible

## Installation

Add to your ECF file:

```xml
<library name="simple_http" location="$SIMPLE_LIBS/simple_http/simple_http.ecf"/>
```

### Environment Setup

Set the `SIMPLE_LIBS` environment variable:
```bash
export SIMPLE_LIBS=/path/to/simple/libraries
```

## Dependencies

| Library | Purpose |
|---------|---------|
| simple_base64 | For Basic auth encoding |
| simple_json | For JSON methods |

## License

MIT License - see [LICENSE](LICENSE) file.

---

Part of the [Simple Eiffel](https://github.com/simple-eiffel) ecosystem.
