CC := /usr/bin/gcc
CFLAGS := \
  -std=c99 \
  -Wall \
  -Wextra

libtapa.so: tag.o
	$(CC) $(CFLAGS) tag.o -shared -o libtapa.so

tag.o: tag.c tag.h settings.h
	$(CC) $(CFLAGS) -c tag.c -o tag.o
