CC = gcc
CFLAGS =-c -Wall -Wextra

laba: main.o deque.o sort.o
  $(CC) main.o deque.o sort.o -o laba

main.o: main.c deque.h sort.h
  $(CC) $(CFLAGS) -c main.c

deque.o: deque.c deque.h
  $(CC) $(CFLAGS) -c deque.c

sort.o: sort.c sort.h deque.h
  $(CC) $(CFLAGS) -c sort.c

clean:
  rm -f *.o laba

.PHONY: clean