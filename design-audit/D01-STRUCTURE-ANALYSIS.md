# D01: Structure Analysis - simple_http + simple_encoding Integration

## Date: 2026-01-20

## Summary

- Classes: 8 source files
- Current dependencies: simple_zstring (already integrated)
- Proposed addition: simple_encoding

## Current Body Handling

SIMPLE_HTTP_RESPONSE (line 139):
```eiffel
cached_json := l_parser.decode_payload (b.to_string_32)
```

This uses `to_string_32` which assumes ASCII/Latin-1 encoding, not UTF-8.
HTTP responses may have charset specified in Content-Type header.

## Integration Opportunity

1. **Extract charset from Content-Type** header
   - `Content-Type: text/html; charset=utf-8`

2. **Add `body_text` feature** that decodes body using proper charset
   - Uses SIMPLE_ENCODING for proper UTF-8 decoding
   - Falls back to Latin-1 if no charset specified

3. **Improve JSON parsing** to use proper charset decoding

## Changes Required

### ECF
```xml
<library name="simple_encoding" location="$SIMPLE_EIFFEL/simple_encoding/simple_encoding.ecf"/>
```

### SIMPLE_HTTP_RESPONSE

Add features:
- `charset: detachable STRING` - Extract charset from Content-Type
- `body_text: STRING_32` - Decode body using charset via SIMPLE_ENCODING

## Decision

Proceed with integration for proper international character handling.
