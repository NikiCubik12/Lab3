TARGET = collect2.exe
CC = gcc
CFLAGS = -Wall 
OBJECTS = main.o sort.o deque.o 

.PHONY: all run start clean

all: $(TARGET)
	@echo "Компиляция завершена!"

run: $(TARGET)
	@echo "Запуск программы..."
	./$(TARGET)

start:
	@echo "Запуск программы..."
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)
	@echo "Очищение файлов..."

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

main.o: main.c deque.h sort.h
	$(CC) $(CFLAGS) -c main.c -o main.o

deque.o: deque.c deque.h 
	$(CC) $(CFLAGS) -c deque.c -o deque.o

sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c sort.c -o sort.o 