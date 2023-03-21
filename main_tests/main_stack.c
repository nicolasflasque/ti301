//
// Created by flasque on 21/06/2022.
//
#include <stdio.h>
#include "../stack/stack.h"

int main()
{
    t_stack_list st = emptyStack();
    int val;
    printf("stack with list\n");
    displayStack(st);

    push(&st, 3);
    displayStack(st);
    push(&st, -6);
    push(&st, 5);push(&st, 17);push(&st, 0);
    displayStack(st);


    return 0;
}