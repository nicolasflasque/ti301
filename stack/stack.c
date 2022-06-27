//
// Created by flasque on 21/06/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void displayStack(t_stack s)
{
    printf("stack--> ");
    if (isStackEmpty(s))
    {
        printf("[empty]");
    }
    while (s.list.head != NULL)
    {
        printf(" %d : ", s.list.head->value);
        s.list.head = s.list.head->next;
    }
    printf("\n");

    return;
}

t_stack emptyStack()
{
    t_stack s;
    s.list.head = NULL;

    return s;
}

int isStackEmpty(t_stack s)
{
    return (s.list.head == NULL);
}

void push(t_stack *p_s, int val)
{
    addHeadStd(&(p_s->list), val);
    return;
}

int top(t_stack s)
{
    int res;

    if (isStackEmpty(s))
    {
        printf("WARNING - cannot top() from an empty stack\n");
        res = -1;
    } else
    {
        res = s.list.head->value;
    }

    return res;
}

int pop(t_stack *p_s)
{
    int res;

    if (isStackEmpty(*p_s))
    {
        printf("WARNING - cannot pop() from an empty stack\n");
        res = -1;
    } else
    {
        res = p_s->list.head->value;
        p_cell p_old = p_s->list.head;
        p_s->list.head = p_s->list.head->next;
        free(p_old);
    }

    return res;
}