#!/usr/bin/env bash

export NAME_IMAGE='tapa-cppcheck'

make "image-${NAME_IMAGE}" && \
docker run --rm "${NAME_IMAGE}":latest
