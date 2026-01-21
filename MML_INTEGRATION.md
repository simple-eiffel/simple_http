# MML Integration - simple_http

## Overview
Applied X03 Contract Assault with simple_mml on 2025-01-21.

Focus: SIMPLE_HTTP_CLIENT_CACHE class for connection pooling.

## MML Classes Used
- `MML_MAP [STRING, SIMPLE_HTTP]` - Models host-to-client cache mapping
- `MML_SET [STRING]` - Models set of cached host names

## Model Queries Added
- `model_cache: MML_MAP [STRING, SIMPLE_HTTP]` - Mathematical model of cache: host to client mapping
- `model_hosts: MML_SET [STRING]` - Set of all cached host names (derived from model_cache.domain)

## Model-Based Postconditions
| Feature | Postcondition | Purpose |
|---------|---------------|---------|
| `make` | `model_empty: model_cache.is_empty` | Cache starts empty |
| `client_for_host` | `in_model_domain: model_cache.domain [a_host]`, `returns_cached: model_cache [a_host] = Result`, `idempotent: client_for_host (a_host) = Result` | Get/create is idempotent |
| `is_cached` | `definition: Result = model_cache.domain [a_host]` | Query defined via model |
| `cached_count` | `definition: Result = model_cache.count` | Count matches model |
| `model_cache` | `count_matches: Result.count = cached_count` | Model consistent with state |
| `model_hosts` | `definition: Result \|=\| model_cache.domain` | Hosts equals domain of cache |
| `invalidate` | `not_in_model: not model_cache.domain [a_host]`, `count_decreased_or_same: cached_count <= old cached_count` | Invalidate removes from model |
| `invalidate_all` | `model_empty: model_cache.is_empty`, `model_count_zero: model_cache.count = 0` | Clear empties model |

## Invariants Added
- `count_non_negative: cached_count >= 0` - Count is non-negative
- `model_count_consistent: model_cache.count = cached_count` - Model matches implementation count
- `model_domain_consistent: model_cache.domain.count = cached_count` - Domain size equals count

## Bugs Found
None

## Test Results
- Compilation: SUCCESS
- Tests: All PASS
