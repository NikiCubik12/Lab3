all: collect2.exe
	@echo "Компиляция завершена!"

run: collect2.exe
	@echo "Запуск программы..."
	./collect2.exe

start:
	@echo "Запуск программы..."
	./collect2.exe

clean:
	rm -f collect2.exe main.o sort.o deque.o
	@echo "Очищение файлов..."

collect2.exe: main.o sort.o deque.o
	gcc -o collect2.exe main.o sort.o deque.o

main.o: main.c deque.h sort.h
	gcc -c main.c -o main.o

deque.o: deque.c deque.h 
	gcc -c deque.c -o deque.o

sort.o: sort.c sort.h
	gcc -c sort.c -o sort.o 