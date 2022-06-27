#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../base/cell/cell.h"
#include "../base/list/list.h"

#define TAI 5

int main()
{
    srand((unsigned) time(NULL));
    int tab[TAI] = {4, 6, -10, 0, 7};
    t_std_list list;
    t_ht_list htlist;

    list.head = NULL;
    htlist.head = htlist.tail = NULL;
    printf("\nadding values 4, 6, -10, 0, 7 to a linked list : \n");
    displayStdList(list);
    for (int cpt = 0; cpt < TAI; cpt++)
    {
        addHeadStd(&list, tab[cpt]);
        displayStdList(list);
    }

    printf("\nlist with head and tail access\n");
    printf("adding 7 values at random :\n");

    displayHtList(htlist);

    for (int cpt = 0; cpt < 7; cpt++)
    {
        int value = rand() % 151 - 75;
        int h_or_t = rand() % 2;
        printf(" inserting %d ", value);
        if (h_or_t == 1)
        {
            printf("at head of list\n");
            addHeadHt(&htlist, value);
        } else
        {
            printf("at tail of list\n");
            addTailHt(&htlist, value);
        }
        displayHtList(htlist);
    }
    return 0;
}
