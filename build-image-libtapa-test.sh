#!/usr/bin/env bash

id_commit_head="$(git rev-parse --short HEAD)"
tag_image_commit="libtapa-test:${id_commit_head}"
tag_image_latest="libtapa-test:latest"
dockerfile="libtapa-test.dockerfile"

docker build \
  -t "${tag_image_commit}" \
  -t "${tag_image_latest}" \
  -f "${dockerfile}" \
  "$(pwd)"