all: main

main: linkedlist main.cc 
	g++ main.cc -o main.o

linkedlist: include/ds/linkedlist.h
stack: include/ds/stack.h
queue: include/ds/queue.h

clean:
	rm -rf *o main valgrind-out.txt
