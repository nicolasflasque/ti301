//
// Created by flasque on 21/06/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void displayStack(t_stack_list s)
{
    printf("stack [");
    if (isStackEmpty(s))
    {
        printf("empty");
    }
    while (s.head != NULL)
    {
        printf(" : %d ", s.head->value);
        s.head = s.head->next;
    }
    printf("]\n");

    return;
}

t_stack_list emptyStack()
{
    t_stack_list s;
    s.head = NULL;

    return s;
}

int isStackEmpty(t_stack_list s)
{
    return (s.head == NULL);
}

void push(t_stack_list *p_s, int val)
{
    addHeadStd(p_s, val);
    return;
}

int top(t_stack_list s)
{
    int res;

    if (isStackEmpty(s))
    {
        printf("WARNING - cannot top() from an empty stack\n");
        res = -1;
    } else
    {
        res = s.head->value;
    }

    return res;
}

int pop(t_stack_list *p_s)
{
    int res;

    if (isStackEmpty(*p_s))
    {
        printf("WARNING - cannot pop() from an empty stack\n");
        res = -1;
    } else
    {
        res = p_s->head->value;
        p_cell p_old = p_s->head;
        p_s->head = p_s->head->next;
        free(p_old);
    }

    return res;
}

typedef struct s_queue
{
    int values[30];
    int nbElts;
} t_queue;

int dequeue_v1(t_queue q)
{
    int res;
    int cpt;
    res = q.values[0];
    for (cpt = 0; cpt < q.nbElts - 1; cpt++)
    {
        q.values[cpt] = q.values[cpt + 1];
    }
    return res;
}

int dequeue_v2(t_queue q)
{
    int res;
    int cpt;
    res = q.values[0];
    for (cpt = 0; cpt < q.nbElts - 1; cpt++)
    {
        q.values[cpt] = q.values[cpt + 1];
    }
    q.nbElts--;
    return res;
}

int dequeue_v3(t_queue *pq)
{
    int res;
    int cpt;
    res = pq->values[0];
    for (cpt = 0; cpt < pq->nbElts - 1; cpt++)
    {
        pq->values[cpt] = pq->values[cpt + 1];
    }
    return res;
}

int dequeue_v4(t_queue *pq)
{
    int res;
    int cpt;
    res = pq->values[0];
    for (cpt = 0; cpt < pq->nbElts - 1; cpt++)
    {
        pq->values[cpt] = pq->values[cpt + 1];
    }
    (pq->nbElts)--;
    return res;
}