//
// Created by flasque on 26/08/2022.
//

#include <stdio.h>
#include <time.h>

#include "../base/list/list.h"


int checkOrderedCells(p_cell ptr_cell)
{
    int result;
    if ((ptr_cell != NULL) && (ptr_cell->next != NULL))
    {
        if ((ptr_cell->value) > (ptr_cell->next->value))
        {
            result = 0;
        } else
        {
            result = checkOrderedCells(ptr_cell->next);
        }
    } else
    {
        return 1;
    }

    return result;
}


int main()
{
    t_ht_list myhtlist;
    myhtlist.head = myhtlist.tail = NULL;

    int check;

    addTailHt(&myhtlist, 6);
    insertOrderedHtList(&myhtlist, 1);
    displayHtList(myhtlist);
    addTailHt(&myhtlist, 31);

    displayHtList(myhtlist);

    insertOrderedHtList(&myhtlist, 25);
    displayHtList(myhtlist);

    insertOrderedHtList(&myhtlist, -4);
    displayHtList(myhtlist);

    insertOrderedHtList(&myhtlist, 50);
    displayHtList(myhtlist);

    check = checkOrderedCells(myhtlist.head);
    printf("liste ordonnée : %d\n", check);

    addTailHt(&myhtlist, 5);
    displayHtList(myhtlist);

    check = checkOrderedCells(myhtlist.head);
    printf("liste ordonnée : %d\n", check);


    return 0;
}
