//
// Created by flasque on 23/06/2022.
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../circlist/circlist.h"

int main()
{
    srand((unsigned )time(NULL));
    t_circ_list cl = createEmptyCircList();
    int values[7];

    for (int cpt = 0; cpt < 7; cpt++)
    {
        values[cpt] = rand() % 67 - 33;
    }

    printf("empty list :\n");
    displayCircList(cl);

    printf("inserting from head\n");
    for (int cpt = 0; cpt < 7; cpt++)
    {
        insertValueHead(&cl, values[cpt]);
        printf("inserting %d\n", values[cpt]);
        displayCircList(cl);
    }

    cl = createEmptyCircList();
    printf("empty list :\n");
    displayCircList(cl);

    printf("inserting from tail\n");
    for (int cpt = 0; cpt < 7; cpt++)
    {
        insertValueTail(&cl, values[cpt]);
        printf("inserting %d\n", values[cpt]);
        displayCircList(cl);
    }

    printf("try to remove cells....\n");

    p_cell out;
    for (int cptr = 0; cptr < 8; cptr++)
    {
        out = cl.head;
        int idx = rand() % 12;
        if (!isEmptyHtList(cl))
        {
            for (int cpti = 0; cpti < idx; cpti++)
            {
                out = out->next;
            }
            printf("removing cell : %d\n", out->value);
        }
        removeCell(&cl, out);
        displayCircList(cl);
    }

    return 0;
}