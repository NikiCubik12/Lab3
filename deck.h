#ifndef DECK_H
#define DECK_H

typedef struct Element
{
    int value;
    struct Element *next;
} Element;

typedef struct Deck
{
    Element *head_deck;
    Element *end_deck;
} Deck;

Deck *make();
void add(int val, Deck *deck);
// void remove(int val, Deck *deck);
void print_deck(Deck *deck);

#endif