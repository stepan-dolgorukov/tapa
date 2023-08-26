CC := /usr/bin/gcc
CFLAGS := \
  -std=c99 \
  -Wall \
  -Wextra

launch: tag.o launch.o
	$(CC) $(CFLAGS) tag.o launch.o -o launch

tag.o: tag.c tag.h settings.h
	$(CC) $(CFLAGS) -c tag.c -o tag.o

launch.o: launch.c tag.h settings.h
	$(CC) $(CFLAGS) -c launch.c -o launch.o