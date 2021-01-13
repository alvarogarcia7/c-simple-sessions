# Testing CMocka

## Scope

Integrate a sample C program (fizzbuzz kata) with [CMocka](https://cmocka.org/)

## Goals

Goals:
  * How to integrate with CMocka (using CMake, but no Conan)
  * How easy it is write test cases
  * How easy it is to adapt (automatically?) existing test cases to CMocka

## Library dependency

This session depends on CMocka. It needs to be included.

You can achieve this by running CMake.

Either manually, or using CLion.

Manually:

```bash
make install-dependencies
```

CLion:

* Open the project, import the CMake configuration

Checking the installation:

* You should see a folder `_deps` inside your cmake build folder
* If you run the tests (either manually or from CLion), 4 tests should pass.

