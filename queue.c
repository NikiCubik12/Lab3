#include <stdio.h>
#include "queue.h"
#include "locale.h"

Queue *make()
{
    setlocale(LC_ALL, "Rus");
    Queue *temporarily = (Queue*) malloc(sizeof(Queue));
    if (temporarily == NULL)
    {
        printf("Ошибка. Не удалось выделить память\n");
        return NULL;
    }
    temporarily->head_queue = NULL;
    temporarily->end_queue = NULL;
    return temporarily;
}

void add(int val, Queue *queue)
{
    setlocale(LC_ALL, "Rus");
    Element *new_elem = (Element*) malloc(sizeof(Element));
    if (new_elem == NULL)
    {
        printf("Ошибка. Не удалось выделить память\n");
        return NULL;
    }
    new_elem->value = val;
    new_elem->next = NULL;

    if (queue->head_queue == NULL)
    {
        queue->head_queue = new_elem;
        queue->end_queue = queue->head_queue;
    }
    else 
    {
        queue->end_queue->next = new_elem;
        queue->end_queue = new_elem;
    }
}

void print_queue(Queue *queue)
{
    setlocale(LC_ALL, "Rus");
    Element *temporarily = queue->head_queue;
    // printf("%d", queue->head_queue);
    while (temporarily != NULL)
    {
        printf("%d ", temporarily->value);
        temporarily = temporarily->next;
    }
    // printf("%d", queue->end_queue);
}