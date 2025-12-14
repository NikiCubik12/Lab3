#include <stdio.h>
#include "deck.h"
#include "sort.h"
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define N INT_MAX
#define n INT_MIN

void print_file(Deck* deck)
{
    FILE* result = fopen("Result.txt", "w");
    if (result == NULL)
    {
        printf ("Не удалось открыть файл для вывода! \n");
        return;
    }
    
    for (int i = 0; i < deck->size; i++)
    {
        fprintf(result, "%d ", get_elem_by_index(i, deck)->value);
    }
}

int input(int min, int max, char* message)
{
    int value;
    char string[200];
    while (1)
    {
        if (fgets(string, sizeof(string), stdin) == NULL)
        {
            continue;
        }
        char* pointer;
        value = (int) strtol(string, &pointer, 10); 
        if (*pointer != '\0' && *pointer != '\n') 
        {
            printf("%s", message);
            continue;
        }
        if (min <= value && value <= max)
        {
            return value;
        }
        printf("%s", message);
    }
}

void input_deck(Deck *deck)
{
    char str[200];
    printf("Введите числа через Энтер (в случае остановки напишите 'Стоп'): \n");
    int c; 
    while ((c = getchar()) != '\n' && c != EOF);
    while (1)
    {
        if (fgets(str, sizeof(str), stdin) == NULL)
        {
            break;
        }
        str[strcspn(str, "\n")] = '\0'; // Пометили, что строка заканчивается
        if (strcmp(str, "Stop") == 0)
        {
            break;
        }
        char* pointer;
        int value = (int) strtol(str, &pointer, 10); 
        if (*pointer != '\0' && *pointer != '\n') 
        {
            printf("%s", "Ошибка. Введено некорректное значение. Введите ещё раз: \n");
            continue;
        }
        if (n <= value && value <= N)
        {
            add_to_end(value, deck);
        }
    }
}

void generating_of_elements(Deck *deck, int count_add)
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    for (int i = 0; i < count_add; i++)         
    {
        int x = rand() %100000 + 1; 
        add_to_end(x, deck);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int option, action, choice, is_working = 1;
    int input_number, input_index;
    double time;
    Deck *deck = make();
    clock_t before, after;
    while (is_working == 1)
    {
        printf("Выберете метод работы с программой 1 или 2: 1 - чтение из файла, 2 - ввод с клавиатуры\n");
        action = input(n, N, "Ошибка. Введено некорректное значение. Введите ещё раз:\n");
        switch (action)
        {
            case 1:
                FILE *List;
                int number;
                char buffer[200];
                List = fopen("Lists.txt", "r");
                if (List == NULL) 
                {
                    printf("Ошибка. Не удалось открыть файл.\n");
                    return 1; 
                }
                printf("Считываем числа из файла:\n");

                while (fscanf(List, "%199s", buffer) == 1) 
                {
                    errno = 0;
                    long num = strtol(buffer, NULL, 10);
                    if (errno == ERANGE)
                    {
                        printf("Есть некорректные значения в файле.\n");
                        break;
                    }
                    printf("Все корректные прочитанные значения из файла:\n");
                    number = (int) num;
                    add_to_end(number, deck);
                }
                print_deck(deck);
                printf("\n");
                printf("Количество элементов в деке: %d", deck->size);
                printf("\n");
                fclose(List);
                printf("Дек загружен из файла. Выберите действие от 1 до 6:\n");
                printf("1. Добавление элемента в начало дека\n");
                printf("2. Удаление элемента из начала дека\n");
                printf("3. Добавление элемента в конец дека\n");
                printf("4. Удаление элемента из конца дека\n");
                printf("5. Добавление элемента по индексу\n");
                printf("6. Удаление элемента по индексу\n");
                option = input(1, 6, "Ошибка. Введено некорректное значение. Введите ещё раз:\n");
                
                
                switch (option)
                {
                    case 1:
                        printf("Введите число от -2147483648 до 2147483647:\n");
                        input_number = input(n, N, "Ошибка. Введено некорректное значение. Введите ещё раз:");
                        // scanf("%d", &input_number);
                        add_to_head(input_number, deck);
                        print_deck(deck);
                        printf("\n");
                        break;
                    case 2:
                        remove_from_head(deck);
                        print_deck(deck);
                        printf("\n");
                        break;
                    case 3:
                        printf("Введите число от -2147483648 до 2147483647:\n");
                        input_number = input(n, N, "Ошибка. Введено некорректное значение. Введите ещё раз:");
                        add_to_end(input_number, deck);
                        print_deck(deck);
                        printf("\n");
                        break;
                    case 4:
                        remove_from_end(deck);
                        print_deck(deck);
                        printf("\n");
                        break;
                    case 5:
                        printf("Введите число от -2147483648 до 2147483647 и индекс через клавишу Энтер:\n");
                        input_number = input(n, N, "Ошибка. Введено некорректное значение. Введите ещё раз:");
                        input_index = input(0, deck->size-1, "Ошибка. Введено некорректное значение. Введите ещё раз:");
                        add_by_index(input_number, input_index, deck);
                        print_deck(deck);
                        printf("\n");
                        break;
                    case 6:
                        printf("Введите индекс:\n");
                        input_index = input(0, deck->size-1, "Ошибка. Введено некорректное значение. Введите ещё раз:");
                        remove_by_index(input_index, deck);
                        print_deck(deck);
                        printf("\n");
                        break;
                }
                printf ("Выберите сортировку: 1 - пузырьком, 2 - пирамидальная \n");
                option = input(1, 6, "Ошибка. Введено некорректное значение. Введите ещё раз:");
                switch (option)
                {
                    case 1:
                            before = clock();
                            bubble_sort(deck);
                            after = clock();
                            printf("Отсортированный дек:\n");
                            print_deck(deck);
                            printf("\n");
                            time = ((double) (after - before))/CLOCKS_PER_SEC;
                            printf("Время работы сортировки пузырьком: %f\n", time);
                            printf ("Количество элементов: %d \n", deck->size);
                            print_file (deck);
                            break;
                    case 2:
                            before = clock();
                            piramide_sort(deck);
                            after = clock();
                            printf("Отсортированный дек:\n");
                            time = ((double) (after - before))/CLOCKS_PER_SEC;
                            print_deck(deck);
                            printf("\n");
                            printf("Время работы пирамидальной сортировки: %f\n", time);
                            printf ("Количество элементов: %d \n", deck->size);
                            print_file (deck);
                            break;
                }

                printf("Хотите продолжить программу? 1 - да, 2 - нет\n");
                is_working = input(1, 2, "Ошибка. Введено некорректное значение. Введите ещё раз:");
                break; 
        
            
            case 2:
                printf("Хотите сгенерировать или ввести числа? 1 - сгенерировать, 2 - ручной ввод\n");
                choice = input(1, 2, "Ошибка. Введено некорректное значение. Введите ещё раз:\n");
                switch (choice)
                {
                    case 1:
                    {
                        int count_add;
                        printf("Введите количество сгенерируемых элементов:\n");
                        count_add = input(1, N, "Ошибка. Введено некорректное значение. Введите ещё раз:\n");
                        generating_of_elements(deck, count_add);
                        break;
                    }
                    case 2:
                    {
                        input_deck(deck);
                        printf("Количество значений в деке: %d\n", deck->size);
                        print_deck(deck);
                        break;
                    }
                }
                printf("1. Добавление элемента в начало дека\n");
                printf("2. Удаление элемента из начала дека\n");
                printf("3. Добавление элемента в конец дека\n");
                printf("4. Удаление элемента из конца дека\n");
                printf("5. Добавление элемента по индексу\n");
                printf("6. Удаление элемента по индексу\n");
                option = input(1, 6, "Ошибка. Введено некорректное значение. Введите ещё раз:");
                
                switch (option)
                {
                    case 1:
                        printf("Введите число:\n");
                        scanf("%d", &input_number);
                        add_to_head(input_number, deck);
                        print_deck(deck);
                        printf("\n");
                        break;
                    case 2:
                        remove_from_head(deck);
                        // print_deck(deck);
                        printf("\n");
                        break;
                    case 3:
                        printf("Введите число:\n");
                        scanf("%d", &input_number);
                        add_to_end(input_number, deck);
                        print_deck(deck);
                        printf("\n");
                        break;
                    case 4:
                        remove_from_end(deck);
                        print_deck(deck);
                        printf("\n");
                        break;
                    case 5:
                        printf("Введите число и индекс через клавишу Энтер:\n");
                        scanf("%d", &input_number);
                        scanf("%d", &input_index);
                        add_by_index(input_number, input_index, deck);
                        print_deck(deck);
                        printf("\n");
                        break;
                    case 6:
                        printf("Введите индекс:\n");
                        scanf("%d", &input_index);
                        remove_by_index(input_index, deck);
                        print_deck(deck);
                        printf("\n");
                        break;
                }
                printf ("Выберите сортировку: 1 - пузырьком, 2 - пирамидальная \n");
                scanf("%d", &option);
                
                switch (option)
                {
                    case 1:
                            before = clock();
                            bubble_sort(deck);
                            after = clock();
                            printf("Отсортированный дек:\n");
                            //print_deck(deck);
                            printf("\n");
                            time = ((double) (after - before))/CLOCKS_PER_SEC;
                            printf("Время работы сотировки пузырьком: %f\n", time);
                            printf ("Количество элементов: %d \n", deck->size);
                            print_file (deck);
                            break;
                    case 2:
                            before = clock();
                            piramide_sort(deck);
                            after = clock();
                            printf("Отсортированный дек:\n");
                            //print_deck(deck);
                            printf("\n");
                            time = ((double) (after - before))/CLOCKS_PER_SEC;
                            printf("Время работы пирамидальной сортировки: %f\n", time);
                            printf ("Количество элементов: %d \n", deck->size);
                            print_file (deck);
                            break;
                }
                printf("Хотите продолжить программу? 1 - да, 0 - нет\n");
                is_working = input(1, 2, "Ошибка. Введено некорректное значение. Введите ещё раз:");
                break; 
        }
    }
    printf("Выход из программы...\n");
    return 0;
}