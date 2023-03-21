//
// Created by flasque on 28/09/2022.
//

#ifndef UNTITLED_BREADTH_FIRST_H
#define UNTITLED_BREADTH_FIRST_H

#include "../bintree.h"

typedef struct s_pnode_queue
{
    p_node values[50];
    int first, last;
} t_pnode_queue;


void breadthFirstVisit(t_tree);

#endif //UNTITLED_BREADTH_FIRST_H
