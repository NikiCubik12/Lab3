#include <stdio.h>
#include "deck.h"
#include "sort.h"
#include "locale.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    FILE *List;
    int number, option, is_working = 1;
    // Открываем файл для чтения ("r")
    List = fopen("Lists.txt", "r");
    // Проверяем, успешно ли открылся файл
    if (List == NULL) {
        printf("Ошибка: не удалось открыть файл.\n");
        return 1; // Возвращаем код ошибки
    }
    printf("Считываем числа из файла:\n");
    // Читаем числа, пока не достигнут конец файла (EOF)
    // fscanf возвращает количество успешно считанных элементов
    Deck *deck = make();
    while (fscanf(List, "%d", &number) == 1) 
    {
        add_to_end(number, deck);
    }
    print_deck(deck);
    printf("\n");
    
    fclose(List);
    
    printf("Дек загружен из файла. Выберите действие от 1 до 6:\n");
    printf("1. Добавление элемента в начало дека\n");
    printf("2. Удаление элемента из начала дека\n");
    printf("3. Добавление элемента в конец дека\n");
    printf("4. Удаление элемента из конца дека\n");
    printf("5. Добавление элемента по индексу\n");
    printf("6. Удаление элемента по индексу\n");
    while (is_working == 1)
    {
        scanf("%d", &option);
        int input_number, input_index;
        
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
                print_deck(deck);
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
        printf("Отсортированный дек:\n");
        bubble_sort(deck);
        print_deck(deck);
        printf("\n");
        printf("Хотите продолжить программу?\n");
        scanf("%d", &is_working);
        if (is_working == 0)
        {
            break;
        }
    }
    printf("Выход из программы...\n");
    return 0;
}