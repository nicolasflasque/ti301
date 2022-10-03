//
// Created by flasque on 28/09/2022.
//

#ifndef UNTITLED_PNODE_QUEUETAB_H
#define UNTITLED_PNODE_QUEUETAB_H
#define MAX_SIZE_QTAB 50

#include "../../base/node/node.h"

typedef struct s_node_qtab
{
    p_node values[MAX_SIZE_QTAB];
    int eq_idx, dq_idx;
} t_node_qtab;

typedef struct s_node_qtab t_node_qtab;

t_queuetab initEmptyNodeQt();

int isEmptyNodeQt(t_node_qtab);

void displayNodeQt(t_node_qtab);

void enqueueNodeQt(t_node_qtab *, int);

int dequeueNodeQt(t_node_qtab *);

#endif //UNTITLED_PNODE_QUEUETAB_H
