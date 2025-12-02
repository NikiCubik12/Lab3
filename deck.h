#ifndef DECK_H
#define DECK_H

typedef struct Element
{
    int value;
    int index;
    struct Element *next;
    struct Element *pref;
} Element;

typedef struct Deck
{
    Element *head_deck;
    Element *end_deck;
    int size;
} Deck;

Deck *make();
void add_to_end(int val, Deck *deck);
void add_to_head(int val, Deck *deck);
void remove_from_end(Deck *deck);
void remove_from_head(Deck *deck);
void print_deck(Deck *deck);

#endif