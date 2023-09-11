#!/usr/bin/env bash

export NAME_IMAGE='tapa-test'

make --file "${NAME_IMAGE}.mk" && \
docker run --rm "${NAME_IMAGE}":latest
