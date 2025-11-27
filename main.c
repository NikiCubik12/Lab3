#include <stdio.h>
#include "deck.h"
#include "locale.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    Deck *deck1 = make();
    add(5, deck1);
    add(6, deck1);
    add(1, deck1);
    add(2, deck1);
    print_deck(deck1);
    return 0;
}