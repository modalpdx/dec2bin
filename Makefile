CC = gcc
ARGS = -g

all: dec2bin

dec2bin: tobinary.o main.o 
	$(CC) $(ARGS) tobinary.o main.o -o dec2bin -lm

tobinary.o:
	$(CC) $(ARGS) -c tobinary.c

main.o:
	$(CC) $(ARGS) -c main.c

clean:
	rm *.o dec2bin

