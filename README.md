# simple_http

Simple HTTP client for Eiffel applications.

## Features

- Simple GET, POST, PUT, DELETE, HEAD, PATCH requests
- Configurable timeouts
- Response status helpers (is_success, is_redirect, etc.)
- Header access and parsing
- Response body handling
- Error detection and messages

## Installation

Add to your ECF file:
```xml
<library name="simple_http" location="$SIMPLE_HTTP\simple_http.ecf"/>
```

## Quick Start

```eiffel
local
    http: SIMPLE_HTTP
    response: SIMPLE_HTTP_RESPONSE
do
    create http.make
    http.set_timeout (60)

    -- GET request
    response := http.get ("https://api.example.com/users")
    if response.is_success then
        print ("Got: " + response.body_string)
    end

    -- POST request with data
    response := http.post ("https://api.example.com/users", "{%"name%": %"John%"}")
    print ("Status: " + response.status.out)
end
```

## Dependencies

- base (EiffelStudio base library)
- net_http_client (EiffelStudio contrib HTTP client)

## Documentation

See [docs/index.html](docs/index.html) for full API documentation.

## License

MIT License - Copyright (c) 2024-2025, Larry Rix
