//
// Created by flasque on 22/06/2022.
//
#include <stdio.h>

#include "queuelist.h"

void displayContent(t_ht_list);

t_queuelist initEmptyQl()
{
    t_queuelist ql;
    ql.list.head = NULL;
    ql.list.tail = NULL;

    return ql;
}

int isEmptyQl(t_queuelist ql)
{
    return ql.list.head == NULL;
}


void displayContent(t_ht_list htl)
{
    p_cell head = htl.head;
    int val;

    if (head != NULL)
    {
        val = htl.head->value;
        htl.head = htl.head->next;
        displayContent(htl);
        printf(" %d :", val);
    }

    return;
}

void displayQl(t_queuelist ql)
{
    printf(" in -> ");
    if (ql.list.head != NULL)
    {
        displayContent(ql.list);
        printf(" -> ");
    }
    printf("out\n");

    return;
}

void enqueueQl(t_queuelist *p_ql, int val)
{
    addTailHt(&(p_ql->list), val);

    return;
}

int dequeueQl(t_queuelist *p_ql)
{
    int res;

    if (isEmptyQl(*p_ql))
    {
        printf("queue is empty - cannot deque\n");
        res = -1;
    } else
    {
        res = p_ql->list.head->value;
        p_ql->list.head = p_ql->list.head->next;
    }
    return res;
}