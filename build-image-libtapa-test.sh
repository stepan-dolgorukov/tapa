#!/usr/bin/env bash

id_commit_head=$(git rev-parse --short HEAD)
tag_image_libtapa_test=libtapa-test:${id_commit_head}

docker build \
  -t ${tag_image_libtapa_test} \
  -f libtapa-test.dockerfile \
  $(pwd)