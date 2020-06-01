#!/usr/bin/env bash

set -euxo pipefail

cd /app/build-docker

conan install .. --build libcurl

