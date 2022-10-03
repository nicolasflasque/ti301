//
// Created by flasque on 28/09/2022.
//

#include <stdio.h>

#include "pnode_queuetab.h"


t_node_qtab initEmptyQt()
{
    t_queuetab qt;
    qt.queue.eq_idx = qt.queue.dq_idx = 0;

    return qt;
}

int isEmptyQt(t_queuetab qt)
{
    return (qt.queue.eq_idx - qt.queue.dq_idx == 0);
}

void displayQt(t_queuetab qt)
{
    printf(" in -> ");
    for (int cpt = qt.queue.eq_idx - 1; cpt >= qt.queue.dq_idx; cpt--)
    {
        printf(" %d ", qt.queue.values[cpt]);
        if (cpt != qt.queue.dq_idx)
        {
            printf(":");
        }
    }
    if (!isEmptyQt(qt))
    {
        printf(" -> ");
    }
    printf("out\n");

    return;
}

void enqueueQt(t_queuetab *p_qt, int val)
{
    if (p_qt->queue.eq_idx == MAX_SIZE_QTAB)
    {
        printf("queue is full - cannot enqueue %d\n", val);
    } else
    {
        p_qt->queue.values[p_qt->queue.eq_idx++] = val;
    }
    return;
}

int dequeueQt(t_queuetab *p_qt)
{
    int res;

    if (isEmptyQt(*p_qt))
    {
        printf("queue is empty - cannot deque\n");
        res = -1;
    } else
    {
        res = p_qt->queue.values[p_qt->queue.dq_idx++];
    }

    return res;
}