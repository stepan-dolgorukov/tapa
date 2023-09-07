#!/usr/bin/env bash

make --file tapa-test.mk && \
docker run --rm tapa-test:latest