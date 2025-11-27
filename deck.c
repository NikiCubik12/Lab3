#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "locale.h"

Deck *make()
{
    setlocale(LC_ALL, "Rus");
    Deck *temporarily = (Deck*) malloc(sizeof(Deck));
    if (temporarily == NULL)
    {
        printf("Ошибка. Не удалось выделить память\n");
        return NULL;
    }
    temporarily->head_deck = NULL;
    temporarily->end_deck = NULL;
    return temporarily;
}

void add(int val, Deck *queue)
{
    setlocale(LC_ALL, "Rus");
    Element *new_elem = (Element*) malloc(sizeof(Element));
    if (new_elem == NULL)
    {
        printf("Ошибка. Не удалось выделить память\n");
    }
    new_elem->value = val;
    new_elem->next = NULL;

    if (queue->head_deck == NULL)
    {
        queue->head_deck = new_elem;
        queue->end_deck = queue->head_deck;
    }
    else 
    {
        queue->end_deck->next = new_elem;
        queue->end_deck = new_elem;
    }
}

void print_deck(Deck *deck)
{
    setlocale(LC_ALL, "Rus");
    Element *temporarily = deck->head_deck;
    // printf("%d", queue->head_queue);
    while (temporarily != NULL)
    {
        printf("%d ", temporarily->value);
        temporarily = temporarily->next;
    }
    // printf("%d", queue->end_queue);
}