NAME_IMAGE ?= tapa-test
DOCKERFILE := "${NAME_IMAGE}.dockerfile"

ID_COMMIT_HEAD != git rev-parse --short HEAD
TAG_IMAGE_COMMIT := $(NAME_IMAGE):$(ID_COMMIT_HEAD)
TAG_IMAGE_LATEST := $(NAME_IMAGE):latest

image-$(NAME_IMAGE):
	docker build \
	--tag $(TAG_IMAGE_COMMIT) \
	--tag $(TAG_IMAGE_LATEST) \
	--file $(DOCKERFILE) \
	$(PWD)
