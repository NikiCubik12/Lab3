all: collect2

main.o: main.c
	gcc -c main.c

deck.o: deck.c
	gcc -c deck.c

sort.o: sort.c
	gcc -c sort.c

collect2: main.o deck.o sort.o
	gcc -o collect2 main.o deck.o sort.o