# S01 - Project Inventory

**Library:** simple_http
**Version:** 1.0.0
**Status:** BACKWASH (reverse-engineered from implementation)
**Generated:** 2026-01-23

## Overview

simple_http provides a high-level HTTP client for Eiffel applications. It wraps the ISE NET_HTTP_CLIENT with a simplified API including automatic JSON parsing, retry support, redirect handling, cookie management, interceptors, and a fluent request builder.

## Project Files

### Source Files (src/)

| File | Class | Description | LOC |
|------|-------|-------------|-----|
| simple_http.e | SIMPLE_HTTP | Main HTTP client facade | ~730 |
| simple_http_response.e | SIMPLE_HTTP_RESPONSE | Response wrapper with JSON | ~330 |
| simple_http_request_builder.e | SIMPLE_HTTP_REQUEST_BUILDER | Fluent request builder | ~200 |
| simple_http_retry_policy.e | SIMPLE_HTTP_RETRY_POLICY | Retry configuration | ~150 |
| simple_http_interceptor.e | SIMPLE_HTTP_INTERCEPTOR | Request/response interceptor | ~80 |
| simple_http_cookie_jar.e | SIMPLE_HTTP_COOKIE_JAR | Cookie storage | ~120 |

### Test Files (testing/)

| File | Description |
|------|-------------|
| test_app.e | Main test application entry point |
| lib_tests.e | Library test suite |

### Research Files (research/)

| File | Description |
|------|-------------|
| SIMPLE_HTTP_RESEARCH.md | 7-step research process documentation |

### Configuration Files

| File | Description |
|------|-------------|
| simple_http.ecf | ECF configuration |

## Dependencies

### ISE Libraries
- `$ISE_LIBRARY/library/base/base.ecf` - Base library
- `$ISE_LIBRARY/library/net/http_client.ecf` - HTTP client (NET_HTTP_CLIENT)
- `$ISE_LIBRARY/library/time/time.ecf` - For sleep in retry

### Simple Ecosystem Dependencies
- simple_json - JSON parsing for responses
- simple_base64 - Basic authentication encoding
- simple_encoding - Character encoding

## Key Statistics

- **Total Source LOC:** ~1610
- **Number of Classes:** 6
- **HTTP Methods:** 7 (GET, POST, PUT, DELETE, HEAD, PATCH + JSON variants)
- **Authentication:** Bearer, Basic, API Key
- **Features:** Retry, Redirects, Cookies, Interceptors

## Phase Status

- Phase 1: Core functionality - COMPLETE
- Phase 2: Expanded features - COMPLETE
- Phase 3: Performance optimization - NOT STARTED
- Phase 4: API documentation - IN PROGRESS
- Phase 5: Test coverage - PARTIAL
- Phase 6: Production hardening - NOT STARTED
