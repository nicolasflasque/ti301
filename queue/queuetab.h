//
// Created by flasque on 21/06/2022.
//

#ifndef UNTITLED_QUEUETAB_H
#define UNTITLED_QUEUETAB_H

#define MAX_SIZE_QTAB 50

typedef struct s_qtab
{
    int values[MAX_SIZE_QTAB];
    int eq_idx, dq_idx;
} t_qtab;

typedef struct s_queuetab
{
    t_qtab queue;
} t_queuetab;

t_queuetab initEmptyQt();

int isEmptyQt(t_queuetab);

void displayQt(t_queuetab);

void enqueueQt(t_queuetab *, int);

int dequeueQt(t_queuetab *);

#endif //UNTITLED_QUEUETAB_H
