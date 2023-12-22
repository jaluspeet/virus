CC = clang
CFLAGS = -Iinclude -Wall
DEPS = $(wildcard include/*.h)
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o) main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) main