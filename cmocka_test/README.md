# Testing CMocka

## Scope

Integrate a sample C program (fizzbuzz kata) with [CMocka](https://cmocka.org/)

## Goals

Goals:
  * How to integrate with CMocka (using CMake, but no Conan)
  * How easy it is write test cases
  * How easy it is to adapt (automatically?) existing test cases to CMocka

## Library dependency

This session depends on CMocka. It needs to be compiled externally and included in the project.

This session has been (manually) tested on bef5c9cc280937053ba8b530d2fd0cf734aea4e0, using the following setup:

```bash
find vendor/ -type f
```

```bash
vendor/cmocka/include/cmocka.h
vendor/cmocka/libcmocka.so.0
```
