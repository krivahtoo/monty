CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89 -ggdb
DEPS=monty.h
OBJ=monty.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

monty: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm *.o monty
