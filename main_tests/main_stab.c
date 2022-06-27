//
// Created by flasque on 21/06/2022.
//

#include <stdio.h>
#include "../stack/stacktab.h"

int main()
{
    int val;
    printf("stack with array\n");

    t_stacktab stab = initEmptySt();

    val = popSt(&stab);
    displayStacktab(stab);

    pushSt(&stab, 3);
    displayStacktab(stab);
    printf("top() : %d\n", topSt(stab));

    pushSt(&stab, -6);
    displayStacktab(stab);

    val = popSt(&stab);
    printf("pop() : %d\n", val);
    displayStacktab(stab);

    return 0;
}