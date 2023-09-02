#!/usr/bin/env bash

id_commit_head="$(git rev-parse --short HEAD)"
name_image="libtapa-test"
tag_image_commit="${name_image}:${id_commit_head}"
tag_image_latest="${name_image}:latest"
dockerfile="${name_image}.dockerfile"

docker build \
  --tag "${tag_image_commit}" \
  --tag "${tag_image_latest}" \
  --file "${dockerfile}" \
  "$(pwd)"