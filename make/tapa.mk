CC := /usr/bin/gcc
CFLAGS := \
  -std=c99 \
  -Wall \
  -Wextra

ifeq ($(SANITIZE),yes)
CFLAGS += \
  -O0 \
  -ggdb \
  -fsanitize=address
endif

libtapa.so: tag.o
	$(CC) $(CFLAGS) tag.o -shared -o libtapa.so

tag.o: tag.c tag.h settings.h
	$(CC) $(CFLAGS) -c tag.c -o tag.o
