#ifndef QUEUE_H
#define QUEUE_H

typedef struct Element
{
    int value;
    struct Element *next;
} Element;

typedef struct Queue
{
    Element *head_queue;
    Element *end_queue;
} Queue;

Queue *make();
void add(int val, Queue *queue);
void print_queue(Queue *queue);

#endif