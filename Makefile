CC = gcc
CFLAGS = -O2 -std=c11

all: code

code: solution.c
	$(CC) $(CFLAGS) -o code solution.c

clean:
	rm -f code

.PHONY: all clean
