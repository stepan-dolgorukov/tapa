CC := /usr/bin/gcc
CFLAGS := \
  -std=c99 \
  -Wall \
  -Wextra

launch: tag.o launch.o
	$(CC) tag.o launch.o -o launch

tag.o: tag.c
	$(CC) $(CFLAGS) -c tag.c -o tag.o

launch.o: launch.c
	$(CC) $(CFLAGS) -c launch.c -o launch.o