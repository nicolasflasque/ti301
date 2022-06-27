//
// Created by flasque on 22/06/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "../queue/queuelist.h"

int main()
{
    printf("Queue with list\n");
    t_queuelist ql;
    ql = initEmptyQl();
    printf("empty queue :");

    displayQl(ql);
    printf("enqueuing 4 : ");
    enqueueQl(&ql, 4);
    displayQl(ql);
    printf("enqueing -2 : ");
    enqueueQl(&ql, -2);
    displayQl(ql);
    printf("dequeing %d\n", dequeueQl(&ql));
    displayQl(ql);
    printf("dequeing %d\n", dequeueQl(&ql));
    displayQl(ql);
    printf("dequeing %d\n", dequeueQl(&ql));
    displayQl(ql);

    printf("enqueing 53 random values : ");
    for (int i = 0; i < 53; i++)
    {
        int val = rand() % 100 - 50;
        enqueueQl(&ql, val);
    }

    displayQl(ql);

    return 0;
}