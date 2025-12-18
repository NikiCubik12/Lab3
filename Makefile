collect2.exe: main.c deque.c sort.c
	gcc -o $@ $^

clean:
	rm -f collect2.exe