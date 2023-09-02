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

libtapa-test: libtapa-test.o
	$(CC) $(CFLAGS) libtapa-test.o -o libtapa-test -L. -ltapa

libtapa-test.o: libtapa-test.c tapa.h
	$(CC) $(CFLAGS) -c libtapa-test.c -o libtapa-test.o