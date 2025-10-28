\
    # math_guard (upgraded)

    Upgraded version: includes unit tests, CI workflow (GitHub Actions), JSON-line logging to file, configurable sabotage return values, and additional wrappers.

    ## What's new
    - Unit tests: `test/test_math_guard.c` (run via `make test`)
    - CI: `.github/workflows/ci.yml` runs `make test`
    - Logging: `math_ledger.c` writes human-readable stderr + JSON-line records to a ledger file (env var `MATH_LEDGER_FILE`).
    - Configurable sabotage return values through macros in `math_guard.h`.
    - Additional wrappers: `safe_exp`, `safe_fmod`, `safe_sin`.

    ## Build & Test
    ```bash
    make
    make test
    ```

    Example test run sets `MATH_LEDGER_FILE=test_logs.jsonl` and expects sabotage entries.

    ## License
    MIT
