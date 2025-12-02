#include <stdio.h>
#include "deck.h"
#include "sort.h"
#include "locale.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    Deck *deck1 = make();
    Deck *deck2 = make();
    add_to_end(4, deck1);
    add_to_end(3, deck1);
    add_to_end(2, deck1);
    add_to_end(1, deck1);
    add_to_end(5, deck2);

    print_deck(deck1);
    printf("\n");
    
    remove_from_end(deck1);
    print_deck(deck1);
    printf("\n");
    remove_from_head(deck2);
    print_deck(deck2);
    add_to_end(3, deck2);
    print_deck(deck2);
    return 0;
}