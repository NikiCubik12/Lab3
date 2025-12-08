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
void add_by_index(int val, int idx, Deck *deck);
void remove_by_index(int idx, Deck *deck);
Element *get_elem_by_index(int idx, Deck *deck);
void swap_elements(Element *elem1, Element *elem2);
void print_deck(Deck *deck);

#endif