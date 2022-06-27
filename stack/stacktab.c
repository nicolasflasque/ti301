//
// Created by flasque on 21/06/2022.
//
#include <stdio.h>

#include "stacktab.h"


t_stacktab initEmptySt()
{
    t_stacktab s;
    s.tab.nbElts = 0;

    return s;
}

void displayStacktab(t_stacktab s)
{
    int size = s.tab.nbElts;

    printf("stack (top) ");
    for (int cpt = size - 1; cpt >= 0; cpt--)
    {
        printf(" : %d ", s.tab.values[cpt]);
    }
    printf("\n");

    return;
}

int isEmptySt(t_stacktab s)
{
    return (s.tab.nbElts == 0);
}


void pushSt(t_stacktab *p_s, int val)
{
    if (p_s->tab.nbElts == MAX_SIZE)
    {
        printf("Stack is full, cannot push %d\n", val);
    } else
    {
        p_s->tab.values[p_s->tab.nbElts] = val;
        (p_s->tab.nbElts)++;
    }
    return;
}

int topSt(t_stacktab s)
{
    int res;
    int elt_idx = s.tab.nbElts;

    if (isEmptySt(s))
    {
        printf("no element available - stack is empty\n");
        res = -1;
    } else
    {
        res = s.tab.values[elt_idx - 1];
    }

    return res;
}

int popSt(t_stacktab *s)
{
    int res = topSt(*s);
    if (!isEmptySt(*s))
    {
        s->tab.nbElts--;
    }
    return res;
}