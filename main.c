#include <stdio.h>
#include "queue.h"
#include "locale.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    Queue *queue1 = make();
    add(5, queue1);
    add(6, queue1);
    add(1, queue1);
    add(2, queue1);
    print_queue(queue1);
    return 0;
}