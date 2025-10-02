TARGET = run-tests

# TODO: make clean command just to delete build directory and bin file

CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -Iinclude

SRC = $(shell find src -name "*.c") main.c

OBJ = $(patsubst src/%.c, build/%.o, $(SRC))


$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf build $(TARGET)
