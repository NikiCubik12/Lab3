#ifndef DEQUE_H
#define DEQUE_H

typedef struct Element
{
    int value;
    struct Element *next;
    struct Element *pref;
} Element;

typedef struct Deque
{
    Element *head_deque;
    Element *end_deque;
} Deque;

Deque *make_deque();
void add_to_end(int val, Deque *deque);
void add_to_head(int val, Deque *deque);
void remove_from_end(Deque *deque);
void remove_from_head(Deque *deque);
void add_by_index(int val, int idx, Deque *deque);
void remove_by_index(int idx, Deque *deque);
int size_deque(Deque *deque);
Element *get_elem_by_index(int idx, Deque *deque);
void print_deque(Deque *deque);

#endif