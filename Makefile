all: collect2

main.o: main.c
	gcc -c main.c

deque.o: deque.c
	gcc -c deque.c

sort.o: sort.c
	gcc -c sort.c

collect2: main.o deque.o sort.o
	gcc -o collect2 main.o deque.o sort.o