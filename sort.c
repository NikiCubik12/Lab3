#include <stdio.h>
#include "deck.h"
#include "sort.h"
#include "locale.h"

void bubble_sort(Deck *deck)
{
    while (1)
    {
        Element *temporarily = deck->head_deck;
        int flag = 0;
        while (temporarily->next != NULL)
        {
            if (temporarily->value > temporarily->next->value)
            {
                int tmp = temporarily->value;
                temporarily->value = temporarily->next->value;
                temporarily->next->value = tmp;
                flag = 1;
            }
            temporarily = temporarily->next;
        }
        if (flag == 0)
        {
            break;
        }
    }
}

// void piramide_sort(Deck *deck)
// {

// }