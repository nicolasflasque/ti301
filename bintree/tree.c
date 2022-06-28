//
// Created by flasque on 27/06/2022.
//
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "../utils/intpow.h"

#define max(a,b) ((a)>(b)?(a):(b))


t_tree createEmptyTree()
{
    t_tree tree;

    tree.root = NULL;

    return tree;
}


int getNodeDepth(p_node p_n)
{
    int depth;

    if (p_n ==NULL)
    {
        depth = 0;
    }
    else
    {
        depth = max(1+getNodeDepth(p_n->left), 1+getNodeDepth(p_n->right));
    }

    return depth;
}

int getDepth(t_tree t)
{
    return getNodeDepth(t.root);
}
