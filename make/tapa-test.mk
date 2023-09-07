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

tapa-test: tapa-test.o
	$(CC) $(CFLAGS) tapa-test.o -o tapa-test -L. -ltapa

tapa-test.o: tapa-test.c tapa.h
	$(CC) $(CFLAGS) -c tapa-test.c -o tapa-test.o