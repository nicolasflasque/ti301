//
// Created by flasque on 28/09/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../bintree/bintree.h"
#include "breadth_first.h"

t_pnode_queue initEmptyQueue()
{
    t_pnode_queue qt;
    qt.first = qt.last = 0;

    return qt;
}

int isEmptyQueue(t_pnode_queue qt)
{
    return (qt.last-qt.first == 0);
}

void enqueueQt(t_pnode_queue *p_qt, p_node val)
{
    if (p_qt->last == 50)
    {
        printf("queue is full - cannot enqueue %d\n", val);
    } else
    {
        p_qt->values[p_qt->last] = val;
        p_qt->last = p_qt->last+1;
    }
    return;
}

p_node dequeueQt(t_pnode_queue *p_qt)
{
    p_node res;

    if (isEmptyQueue(*p_qt))
    {
        printf("queue is empty - cannot deque\n");
        res = NULL;
    }
    else
    {
        res = p_qt->values[p_qt->first];
        p_qt->first = p_qt->first+1;
    }

    return res;
}
void breadthFirstVisit(t_tree t)
{
    p_node pcur;
    t_pnode_queue visitqueue=initEmptyQueue();

    if (t.root != NULL)
    {
        enqueueQt(&visitqueue, t.root);
        while (isEmptyQueue(visitqueue) == 0)
        {
            pcur = dequeueQt(&visitqueue);
            if (pcur->left != NULL)
            {
                enqueueQt(&visitqueue, pcur->left);
            }
            if (pcur->right != NULL)
            {
                enqueueQt(&visitqueue, pcur->right);
            }
            printf(" %d ", pcur->value);
        }
    }
    return;
}

