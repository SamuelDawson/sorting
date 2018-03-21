CC=gcc
SRC = $(wildcard src/*.c)
TEST_SRC = $(wildcard test_src/*.c)
INC = include
OBJ = $(TEST_SRC:.c=.o)
CFLAGS= -g2 -Wall -Wextra -pedantic -iquote $(INC) -iquote src
test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) test
