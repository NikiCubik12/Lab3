#include <stdio.h>
#include "deck.h"
#include "sort.h"
#include <locale.h>

void bubble_sort(Deck *deck)
{
    int temp;
    
    for (int i=0; i < deck->size-1; i++)
    {
        for (int j=i+1; j < deck->size; j++)
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

void tree_rebuild(int r, int q, Deck *deck)
{
    int v;
    int i, j;
    int pp = 0;
    i = r;
    v = get_elem_by_index(i, deck)->value;
    j = 2*i + 1;
    while (j <= q && !pp)
    {
        if (j < q)
        {
            if (get_elem_by_index(j, deck)->value < get_elem_by_index(j + 1, deck)->value)
            {
                j++;
            }
        }
        if (v >= get_elem_by_index(j, deck)->value)
        {
            pp = 1;
        }
        else 
        {
            get_elem_by_index(i, deck)->value = get_elem_by_index(j, deck)->value;
            i = j;
            j = 2*i + 1;
        }
    }
    get_elem_by_index(i, deck)->value = v;
}

void piramide_sort(Deck *deck)
{
    for (int i = (deck->size/2 - 1); i >= 0; i--)
    {
        tree_rebuild(i, deck->size-1, deck);
    }
    for (int i = (deck->size - 1); i > 0; i--)
    {
        int x = get_elem_by_index(0, deck)->value;
        get_elem_by_index(0, deck)->value = get_elem_by_index(i, deck)->value;
        get_elem_by_index(i, deck)->value = x;
        tree_rebuild(0, i-1, deck);
    }
}