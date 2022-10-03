#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../base/cell/cell.h"
#include "../base/list/list.h"

#define TAI 10

int main()
{
    srand((unsigned) time(NULL));
    int tab[TAI] = {5,4, 6, 5, 5, 0, 7,5,1,5};
    t_std_list list;
    int check;

    list.head = NULL;
    printf("\nadding values 4, 6, -10, 0, 7 to a linked list : \n");
    displayStdList(list);
    for (int cpt = 0; cpt < TAI; cpt++)
    {
        addHeadStd(&list, tab[cpt]);
        displayStdList(list);
    }
    testDisplaySimplelist(list);
    for (int cpt = 0; cpt < TAI; cpt++)
    {
        check = isValInList(list,tab[cpt]);
        printf("valeur %d dans la liste : %d\n",tab[cpt],check);
    }

    check = isValInList(list,5);
    printf("valeur %d dans la liste : %d\n",5,check);

/*    printf("removing 3\n");
    removeValFromList(&list, 3);
    displayStdList(list);

    printf("removing -10\n");
    removeValFromList(&list, -10);
    displayStdList(list);

    printf("removing 4\n");
    removeValFromList(&list, 4);
    displayStdList(list);

    printf("removing 12\n");
    removeValFromList(&list, 12);
    displayStdList(list);
*/
    // test de remove allVals
    printf("removing all 5s\n");

    removeAllValFromList(&list, 5);
    displayStdList(list);

    return 0;
}
