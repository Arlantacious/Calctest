CC = clang
CFLAGS = -Wall -Wextra -std=c99 -g -fsanitize=address -I/opt/homebrew/Cellar/raylib/4.5.0/include
LDFLAGS = -L/opt/homebrew/Cellar/raylib/4.5.0/lib -lraylib

SOURCES = $(shell find . -type f -name '*.c')
OBJECTS = $(SOURCES:.c=.o)

	#$(CC) -fsanitize=address -o $@ $^ $(LDFLAGS) -lraylib
calculator: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -rf calculator calculator.dSYM $(OBJECTS)
