CC = clang

CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC = src/main.c src/notes.c src/file_io.c

OUT = build/memory-notes-cli

all:
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -rf build
