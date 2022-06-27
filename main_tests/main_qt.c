//
// Created by flasque on 21/06/2022.
//

#include <stdio.h>
#include <stdlib.h>

#include "../queue/queuetab.h"

int main()
{
    printf("Queue with array\n");
    t_queuetab qt;
    qt = initEmptyQt();
    printf("empty queue :");
    displayQt(qt);
    printf("enqueuing 4 : ");
    enqueueQt(&qt, 4);
    displayQt(qt);
    printf("enqueing -2 : ");
    enqueueQt(&qt, -2);
    displayQt(qt);
    printf("dequeing %d\n", dequeueQt(&qt));
    displayQt(qt);
    printf("dequeing %d\n", dequeueQt(&qt));
    displayQt(qt);
    printf("dequeing %d\n", dequeueQt(&qt));
    displayQt(qt);

    printf("enqueing 53 random values : ");
    for (int i = 0; i < 53; i++)
    {
        int val = rand() % 100 - 50;
        enqueueQt(&qt, val);
    }

    displayQt(qt);
    return 0;
}