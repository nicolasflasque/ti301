//
// Created by flasque on 27/06/2022.
//
#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"
#include "../utils/intpow/intpow.h"

#define max(a,b) ((a)>(b)?(a):(b))

int nodeCount(p_node);


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
        depth = 1+max(getNodeDepth(p_n->left), getNodeDepth(p_n->right));
    }

    return depth;
}

int getDepth(t_tree t)
{
    return getNodeDepth(t.root);
}

t_tree createTree(p_node p_n)
{
    t_tree t;
    t.root = p_n;
    
    return t;
}

int treeNodeCount(t_tree t)
{
    return nodeCount(t.root);
}

int nodeCount(p_node p_n)
{
    int count;
    if (p_n == NULL)
    {
        count = 0;
    }
    else
    {
        count = 1+nodeCount(p_n->left)+nodeCount(p_n->right);
    }
    return count;
}

p_node seekValue(p_node pn, int val)
{
    p_node pleft, pright;
    if (pn==NULL) return NULL;
    if (pn->value == val) return pn;
    pleft = seekValue(pn->left,val);
    if (pleft!=NULL) return pleft;
    pright = seekValue(pn->right, val);
    if (pright != NULL) return pright;
    return NULL;
}
