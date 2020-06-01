#!/usr/bin/env bash

set -euxo pipefail

cd /app/cmake-build-debug

conan install .. --build libcurl

