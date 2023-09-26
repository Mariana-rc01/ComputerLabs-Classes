CC= gcc
CFLAGS= -c -g -Wall
LDFLAGS=

deque: deque.o node.o main.o
	$(CC) $(LDFLAGS) $^ -o deque

main.o: main.c

deque.o: deque.c

node.o: node.c

clean:
	rm deque.o main.o node.o
