#include <stdio.h>
#include "deque.h"
#include "sort.h"
#include <locale.h>

void bubble_sort(Deque *deck)
{
    int temp;
    for (int i = 0; i < deck->end_deque->index; i++)
    {
        for (int j = i+1; j < deck->end_deque->index + 1; j++)
        {
            if (get_elem_by_index(i, deck)->value > get_elem_by_index(j, deck)->value)
            {
                temp = get_elem_by_index(i, deck)->value;
                get_elem_by_index(i, deck)->value = get_elem_by_index(j, deck)->value;
                get_elem_by_index(j, deck)->value = temp;
            }
        }
    }
}

void tree_rebuild(int r, int q, Deque *deque)
{
    int v;
    int i, j;
    int pp = 0;
    i = r;
    v = get_elem_by_index(i, deque)->value;
    j = 2*i + 1;
    while (j <= q && !pp)
    {
        if (j < q)
        {
            if (get_elem_by_index(j, deque)->value < get_elem_by_index(j + 1, deque)->value)
            {
                j++;
            }
        }
        if (v >= get_elem_by_index(j, deque)->value)
        {
            pp = 1;
        }
        else 
        {
            get_elem_by_index(i, deque)->value = get_elem_by_index(j, deque)->value;
            i = j;
            j = 2*i + 1;
        }
    }
    get_elem_by_index(i, deque)->value = v;
}

void piramide_sort(Deque *deque)
{
    for (int i = ((deque->end_deque->index + 1)/2 - 1); i >= 0; i--)
    {
        tree_rebuild(i, deque->end_deque->index, deque);
    }
    for (int i = (deque->end_deque->index); i > 0; i--)
    {
        int x = get_elem_by_index(0, deque)->value;
        get_elem_by_index(0, deque)->value = get_elem_by_index(i, deque)->value;
        get_elem_by_index(i, deque)->value = x;
        tree_rebuild(0, i-1, deque);
    }
}