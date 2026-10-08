# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Changed
- Post-session update 2025-12-08 20:52
- Remove EIFGENs from git tracking
- Post-session update 2025-12-08 20:45
- Post-session update 2025-12-08 20:16
- Add Phase 2 & 3 enhancements: streaming, advanced options, fluent builders, interceptors, cookies
- first commit

## [1.1.1] - 2026-10-08

### Fixed
- **Every `Set-Cookie` header now reaches the cookie jar.** `SIMPLE_HTTP_RESPONSE`
  parsed headers into a one-value-per-name table, so when a response carried
  several `Set-Cookie` lines only the last survived. The transport
  (SIMPLE_WINHTTP) was innocent: it hands over the raw header block intact.
  Added `SIMPLE_HTTP_RESPONSE.header_values (name)` (every line, in order;
  `header` is unchanged and still returns the last), and
  `extract_cookies_from_response` now walks all of them. Verified against a
  local server sending 3 Set-Cookie headers: the follow-up request carried
  `Cookie: a=1; b=2; c=3`. Suite 28 of 28.

## [1.1.0] - 2026-10-08

### Fixed
- **Request bodies, headers and URLs now reach the server byte-for-byte.**
  `post`, `post_json`, `put`, `put_json`, `patch` and `patch_json` sent a
  mangled body. The transport was ISE's `curl_http_client`, which runs the
  curl PROGRAM and builds ` --data "<body>"` and ` --header "<name>:<value>"`
  on a command line with no escaping
  (`$ISE_LIBRARY/contrib/library/network/http_client/src/spec/curl/curl_http_client_request.e`,
  lines 158-160 and 228-235). Every `"` in a JSON body was dropped, a blank
  could cut the argument, `%` `^` `&` `|` `<` `>` were at the mercy of the
  shell, UTF-8 text was re-encoded, and a large body hit the command-line
  length limit and never left the process. A `"` in any header value broke
  every header after it, so `post_json`'s `Content-Type: application/json`
  was lost and the request went out as `application/x-www-form-urlencoded`.

  Captured at a local server with the 1.0.x code, 0 of 29 checks passed:
  `{"message_id": "test_msg_001", ...}` arrived as
  `{message_id: test_msg_001, ...}`; a body with shell characters arrived as
  its first 6 bytes; Hebrew and Greek arrived double-encoded; every 1 MiB
  body except PUT's never arrived; custom headers arrived cut at the first
  `"` or not at all. With 1.1.0, 29 of 29 pass: four payloads (JSON with
  quotes and blanks, shell characters, Hebrew and Greek UTF-8, 1 MiB) through
  all six body methods, a pre-encoded URL, custom headers, and redirects.
- `SIMPLE_HTTP_QUICK`: five implicit `as_string_8` conversions (obsolete calls,
  `Result := body`) made explicit with `to_string_8`; every simple_http class
  now compiles with zero warnings.

### Changed
- **Transport moved onto simple_winhttp** (WinHTTP, part of every supported
  Windows; nothing to redistribute). `curl_http_client` is gone from the ECF.
  The public API is unchanged. Behavior kept from the curl transport: a body
  with no Content-Type header is sent as `application/x-www-form-urlencoded`
  (curl's `--data` default); `Accept: */*` unless the caller sets one;
  301/302/303/307/308 are followed up to `max_redirects` when
  `follow_redirects`; `timeout` / `connect_timeout` of 0 mean no limit.
- Redirects follow the HTTP rules: 303 - and 301/302 after a POST -
  continue as a GET without the body; 307/308 repeat the method and body.
  A redirect to another origin (scheme, host, port) does not carry the
  Authorization or Cookie header onward.
- `timeout` is now honored (the curl transport ignored it); it bounds each
  wait for the server (WinHTTP send/receive timeouts).
- A network condition is a result: `error_occurred`, `status` 0 and an
  `error_message` (connection refused, timeout, TLS failure, oversized
  body). A URL that is not http(s), or a header value an HTTP header line
  cannot carry (non-ASCII, CR, LF), fails the request with an explanation
  instead of sending it half-formed. `on_error` interceptors now run for
  these failures.
- `before_request` interceptors run before the header lines are built, so a
  header an interceptor adds travels with that same request.
- `SIMPLE_HTTP_RESPONSE.make_from_response (HTTP_CLIENT_RESPONSE)` is
  replaced by `make_from_exchange (SIMPLE_WINHTTP_RESPONSE)` and
  `make_failed`. No client in the ecosystem created responses directly.

### Added
- `SIMPLE_HTTP_WIRE`: the URL rules, pure and tested - `wire_url`
  (percent-encodes exactly what a request line cannot carry: blanks, UTF-8
  bytes, `" < > \ ^ ` { | }`, a bare `%`; drops the fragment; idempotent, so
  a well-formed URL travels verbatim), `resolved_location`, `same_origin`.
- `body_maximum` / `set_body_maximum`: response body ceiling, default 256 MiB
  (at most 1 GiB); a larger body fails cleanly instead of growing unbounded.
- Tests: wire rules, redirect resolution, origin checks, refused connection,
  unusable URL and unclean header as results, response construction; the two
  client-cache tests that existed but were never run are now registered
  (15 -> 26 tests).

## [1.0.0] - 2025-12-08

### Added
- Initial release
- Core functionality implemented
- Test suite with comprehensive coverage
- Documentation and examples

[Unreleased]: https://github.com/simple-eiffel/simple_http/compare/v1.1.0...HEAD
[1.1.1]: https://github.com/simple-eiffel/simple_http/compare/v1.1.0...v1.1.1
[1.1.0]: https://github.com/simple-eiffel/simple_http/compare/v1.0.0...v1.1.0
[1.0.0]: https://github.com/simple-eiffel/simple_http/releases/tag/v1.0.0
