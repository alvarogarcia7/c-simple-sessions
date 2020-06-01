#!/usr/bin/env bash

set -euxo pipefail

cd /app/cmake-build-debug

cmake ..
make all

