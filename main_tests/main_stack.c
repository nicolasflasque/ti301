//
// Created by flasque on 21/06/2022.
//
#include <stdio.h>
#include "../stack/stack.h"

int main()
{
    t_stack st = emptyStack();
    int val;
    printf("stack with list\n");
    displayStack(st);
    printf("trying to pop() a value\n");
    val = pop(&st);
    printf("pushing 3\n");
    push(&st, 3);
    displayStack(st);
    printf("getting the top() value : ");
    printf("top() : %d\n", top(st));
    printf("pushing -6\n");
    push(&st, -6);
    displayStack(st);
    printf("pop() from stack\n");
    val = pop(&st);
    printf("pop() : %d\n", val);
    displayStack(st);

    return 0;
}