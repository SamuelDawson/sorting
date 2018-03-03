CC=gcc
CFLAGS=-Wall -Wpedantic

DEPS=samsort.h
OBJ=testbench.o common.o insertion.o bubble.o bogo.o merge.o

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
		gcc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
	rm -f test
