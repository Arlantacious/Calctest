CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O3 -g -fsanitize=address
SOURCES = $(shell find . -type f -name '*.c')
OBJECTS = $(SOURCES:.c=.o)

calculator: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -rf calculator calculator.dSYM $(OBJECTS)
