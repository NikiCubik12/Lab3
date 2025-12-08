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
        return;
    }
    new_elem->value = val;
    new_elem->next = NULL;
    new_elem->pref = deck->end_deck;
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

void add_to_head(int val, Deck *deck)
{
    setlocale(LC_ALL, "Rus");
    Element *new_elem = (Element*) malloc(sizeof(Element));
    if (new_elem == NULL)
    {
        printf("Ошибка. Не удалось выделить память\n");
    }
    new_elem->value = val;
    new_elem->next = deck->head_deck;
    deck->head_deck = new_elem;
    deck->size++;
    
    int count = 0;
    Element *temporarily = deck->head_deck;
    while (temporarily != NULL)
    {
        temporarily->index = count;
        count++;
        temporarily = temporarily->next;
    }
}

void remove_from_end(Deck *deck)
{
    setlocale(LC_ALL, "Rus");
    Element *temporarily = deck->end_deck;
    deck->end_deck = temporarily->pref;
    deck->end_deck->next = NULL;
    free(temporarily);
    deck->size--;
}

void remove_from_head(Deck *deck)
{
    setlocale(LC_ALL, "Rus");
    Element *temporarily = deck->head_deck;
    if (deck->size == 1)
    {
        deck->head_deck = NULL;
        deck->end_deck = NULL;
    }
    else 
    {
        deck->head_deck = deck->head_deck->next;
        deck->head_deck->pref = NULL;
        int count = 0;
        Element *temp = deck->head_deck;
        while (temp != NULL)
        {
            temp->index = count;
            count++;
            temp = temp->next;
        }
    }
    free(temporarily);
    deck->size--;
}

void add_by_index(int val, int idx, Deck *deck)
{
    setlocale(LC_ALL, "Rus");
    if (deck->size - 1 == idx) // если idx = размеру deck, то добавляем элемент в конец
    {
        add_to_end(val, deck);
        return;
    }
    Element *temporarily = deck->head_deck;
    while (temporarily->index != idx)
    {
        temporarily = temporarily->next;
    }
    Element *new_elem = (Element*) malloc(sizeof(Element));
    new_elem->index = idx;
    new_elem->value = val;
    new_elem->next = temporarily->next; // new смотрит на 3
    temporarily->next = new_elem; // элемент по idx смотрит на следующий - new
    temporarily->next->next->pref = new_elem; // 3 смотрит на new
    new_elem->pref = temporarily; // new смотрит на второй
    temporarily = temporarily->next;
    while (temporarily != NULL)
    {
        temporarily->index++;
        temporarily = temporarily->next;
    }
    deck->size++;
}

void remove_by_index(int idx, Deck *deck)
{
    setlocale(LC_ALL, "Rus");
    if (idx == 0)
    {
        remove_from_head(deck);
        return;
    }
    if (idx == deck->end_deck->index)
    {
        remove_from_end(deck);
        return;
    }
    Element *temporarily = deck->head_deck;
    while (temporarily->index != idx)
    {
        temporarily = temporarily->next;
    }
    temporarily->pref->next = temporarily->next;
    temporarily->next->pref = temporarily->pref;
    deck->size--;
    temporarily = temporarily->next;
    while (temporarily != NULL)
    {
        temporarily->index--;
        temporarily = temporarily->next;
    }
    free(temporarily);
}

Element *get_elem_by_index(int idx, Deck *deck)
{
    Element *temporarily = deck->head_deck;
    while (temporarily != NULL && temporarily->index != idx)
    {
        temporarily = temporarily->next;
    }
    return temporarily;
}

void swap_elements(Element *elem1, Element *elem2)
{
    int x = elem1->value;
    elem1->value = elem2->value;
    elem2->value = x;
}

void print_deck(Deck *deck)
{
    setlocale(LC_ALL, "Rus");
    Element *temporarily = deck->head_deck; 
    if (temporarily == NULL)
    {
        printf("Пустой список.\n");
    }
    while (temporarily != NULL)
    {
        printf("%d:", temporarily->index);
        printf("%d ", temporarily->value);
        temporarily = temporarily->next;
    }
}