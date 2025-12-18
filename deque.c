#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
#include <locale.h>

Deque *make()
{
    setlocale(LC_ALL, "Rus");
    Deque *pointer_deque = (Deque*) malloc(sizeof(Deque));
    
    if (pointer_deque == NULL)
    {
        printf("Ошибка. Не удалось выделить память.\n");
        return NULL;
    }
    pointer_deque->head_deque = NULL;
    pointer_deque->end_deque = NULL;
    return pointer_deque;
}

void add_to_end(int val, Deque *deque)
{
    setlocale(LC_ALL, "Rus");
    Element *new_elem = (Element*) malloc(sizeof(Element));
    if (new_elem == NULL)
    {
        printf("Ошибка. Не удалось выделить память.\n");
        return;
    }
    new_elem->value = val;
    new_elem->next = NULL;
    new_elem->pref = deque->end_deque;
    if (deque->end_deque == NULL)
    {
        new_elem->index = 0;
    }
    else 
    {
        new_elem->index = deque->end_deque->index + 1;
    }
    if (deque->head_deque == NULL)
    {
        deque->head_deque = new_elem;
        deque->end_deque = new_elem;
    }
    else 
    {
        deque->end_deque->next = new_elem;
        deque->end_deque = new_elem;
    }
}

void add_to_head(int val, Deque *deque)
{
    setlocale(LC_ALL, "Rus");
    Element *new_elem = (Element*) malloc(sizeof(Element));
    if (new_elem == NULL)
    {
        printf("Ошибка. Не удалось выделить память.\n");
    }
    new_elem->value = val;
    new_elem->next = deque->head_deque;
    deque->head_deque = new_elem;
    
    int count = 0;
    Element *temporarily = deque->head_deque;
    while (temporarily != NULL)
    {
        temporarily->index = count;
        count++;
        temporarily = temporarily->next;
    }
}

void remove_from_end(Deque *deque)
{
    setlocale(LC_ALL, "Rus");
    Element *temporarily = deque->end_deque;
    if (deque->end_deque != NULL && deque->end_deque->index == 0)
    {
        deque->head_deque = NULL;
        deque->end_deque = NULL;
    }
    else 
    {
        deque->end_deque = temporarily->pref;
        deque->end_deque->next = NULL;
    }
    free(temporarily);
}

void remove_from_head(Deque *deque)
{
    setlocale(LC_ALL, "Rus");
    Element *temporarily = deque->head_deque;
    if (deque->end_deque != NULL && deque->end_deque->index == 0)
    {
        deque->head_deque = NULL;
        deque->end_deque = NULL;
    }
    else 
    {
        deque->head_deque = deque->head_deque->next;
        deque->head_deque->pref = NULL;
        int count = 0;
        Element *temp = deque->head_deque; // обновляем индексы
        while (temp != NULL)
        {
            temp->index = count;
            count++;
            temp = temp->next;
        }
    }
    free(temporarily);
}

void add_by_index(int val, int idx, Deque *deque)
{
    setlocale(LC_ALL, "Rus");
    if (idx == deque->end_deque->index) 
    {
        add_to_end(val, deque);
        return;
    }
    Element *temporarily = deque->head_deque;
    while (temporarily->index != idx)
    {
        temporarily = temporarily->next;
    }
    Element *new_elem = (Element*) malloc(sizeof(Element));
    new_elem->index = idx;
    new_elem->value = val;

    new_elem->next = temporarily->next; 
    temporarily->next = new_elem; 
    temporarily->next->next->pref = new_elem; 
    new_elem->pref = temporarily; 

    temporarily = temporarily->next;
    while (temporarily != NULL)
    {
        temporarily->index++;
        temporarily = temporarily->next;
    }
}

void remove_by_index(int idx, Deque *deque)
{
    setlocale(LC_ALL, "Rus");
    if (idx == 0)
    {
        remove_from_head(deque);
        return;
    }
    if (idx == deque->end_deque->index)
    {
        remove_from_end(deque);
        return;
    }
    Element *temporarily = deque->head_deque;
    while (temporarily->index != idx)
    {
        temporarily = temporarily->next;
    }
    temporarily->pref->next = temporarily->next;
    temporarily->next->pref = temporarily->pref;

    Element *temp = temporarily;
    temporarily = temporarily->next;
    while (temporarily != NULL)
    {
        temporarily->index--;
        temporarily = temporarily->next;
    }
    free(temp);
}

Element *get_elem_by_index(int idx, Deque *deque)
{
    Element *temporarily = deque->head_deque;

    while (temporarily != NULL && temporarily->index != idx)
    {
        temporarily = temporarily->next;
    }
    return temporarily;
}

void print_deque(Deque *deque)
{
    setlocale(LC_ALL, "Rus");
    Element *temporarily = deque->head_deque; 
    if (temporarily == NULL)
    {
        printf("Ошибка вывода.\n");
    }
    while (temporarily != NULL)
    {
        printf("%d:", temporarily->index);
        printf("%d ", temporarily->value);
        temporarily = temporarily->next;
    }
}