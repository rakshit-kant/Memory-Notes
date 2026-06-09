CC = clang

CFLAGS = -Wall -Wextra -Werror -Iinclude -fPIC

SRC = src/notes.c src/file_io.c

LIB = libnotes.so

all:
	$(CC) $(CFLAGS) -shared $(SRC) -o $(LIB)

clean:
	rm -f $(LIB)
