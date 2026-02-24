# test_helpers

Lightweight test helpers and minimal test runner for modern C++.

`test_helpers` provides a small and explicit API for writing unit tests
without depending on heavy frameworks. It includes basic matchers and a
minimal test suite runner.

Header-only. Zero external dependencies.

## Download

https://vixcpp.com/registry/pkg/gaspardkirira/test_helpers

## Why test_helpers?

Unlike full testing frameworks, this library:

-   Provides simple expectation helpers
-   Includes a minimal test runner
-   Produces deterministic CLI output
-   Is fully header-only
-   Has no external dependencies
-   Is easy to integrate into small libraries

Perfect for:

-   Small open-source libraries
-   Header-only projects
-   Lightweight CI checks
-   Internal tools
-   Embedded or constrained environments

## Installation

### Using Vix Registry

``` bash
vix add gaspardkirira/test_helpers
vix deps
```

### Manual

Clone the repository:

``` bash
git clone https://github.com/GaspardKirira/test_helpers.git
```

Add the `include/` directory to your project.

## Quick Example

``` cpp
#include <test_helpers/test_helpers.hpp>

int main()
{
  using namespace test_helpers;

  TestSuite suite;

  suite.add("equality test", [] {
    expect_eq(5, 5);
  });

  suite.add("boolean test", [] {
    expect_true(10 > 1);
  });

  return suite.run();
}
```

### Output
```
    [PASS] equality test
    [PASS] boolean test

    Summary: 2/2 passed
```
## Failure Example

``` cpp
suite.add("failing test", [] {
  expect_eq(2 + 2, 5, "Math is broken");
});
```

### Output
```
    [FAIL] failing test -> Math is broken

    Summary: 0/1 passed
```
## Features

-   Header-only
-   C++17 compatible
-   Minimal test runner
-   Simple matchers
-   Custom failure messages
-   Deterministic output
-   No macros required
-   No global state

## API Overview

``` cpp
test_helpers::TestSuite suite;

suite.add("my test", [] {
  test_helpers::expect_true(true);
});

return suite.run();
```

Available helpers:

-   `expect_true(bool);`
-   `expect_false(bool);`
-   `expect_eq(a, b);`
-   `expect_ne(a, b);`

All helpers throw an internal failure object captured by the test
runner.

## Design Philosophy

`test_helpers` focuses on:

-   Simplicity over feature bloat
-   Clear and explicit expectations
-   Small API surface
-   Zero configuration
-   Deterministic console output

It is intentionally minimal and does not aim to replace large frameworks
like Catch2 or GoogleTest.

## Tests

Run:

``` bash
vix build
vix tests
```

## License

MIT License
Copyright (c) Gaspard Kirira

