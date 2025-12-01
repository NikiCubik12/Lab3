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
    temporarily->size = 0;
    return temporarily;
}

void add_to_end(int val, Deck *deck)
{
    setlocale(LC_ALL, "Rus");
    Element *new_elem = (Element*) malloc(sizeof(Element));
    if (new_elem == NULL)
    {
        printf("Ошибка. Не удалось выделить память\n");
    }
    new_elem->value = val;
    new_elem->next = NULL;
    new_elem->index = deck->size;

    if (deck->head_deck == NULL)
    {
        deck->head_deck = new_elem;
        deck->end_deck = deck->head_deck;
    }
    else 
    {
        deck->end_deck->next = new_elem;
        deck->end_deck = new_elem;
    }
    deck->size++;
}

void print_deck(Deck *deck)
{
    setlocale(LC_ALL, "Rus");
    Element *temporarily = deck->head_deck;
    while (temporarily != NULL)
    {
        printf("%d:", temporarily->index);
        printf("%d ", temporarily->value);
        temporarily = temporarily->next;
    }
}