//
// Created by flasque on 28/09/2022.
//

#include <stdlib.h>

#include "char_bintree.h"

#define max(a,b) ((a)>(b)?(a):(b))

int charNodeCount(p_char_node );


t_char_tree createEmptyCharTree()
{
    t_char_tree tree;

    tree.root = NULL;

    return tree;
}


int getCharNodeDepth(p_char_node p_n)
{
    int depth;

    if (p_n ==NULL)
    {
        depth = 0;
    }
    else
    {
        depth = 1+max(getCharNodeDepth(p_n->left), getCharNodeDepth(p_n->right));
    }

    return depth;
}

int getCharDepth(t_char_tree t)
{
    return getCharNodeDepth(t.root);
}

t_char_tree createCharTree(p_char_node p_n)
{
    t_char_tree t;
    t.root = p_n;

    return t;
}

int charTreeNodeCount(t_char_tree t)
{
    return charNodeCount(t.root);
}

int charNodeCount(p_char_node p_n)
{
    int count;
    if (p_n == NULL)
    {
        count = 0;
    } else
    {
        count = 1 + charNodeCount(p_n->left) + charNodeCount(p_n->right);
    }
    return count;
}

p_char_node seekValue(p_char_node pn, char val)
{
    p_char_node pleft, pright;
    if (pn==NULL) return NULL;
    if (pn->value == val) return pn;
    pleft = seekValue(pn->left,val);
    if (pleft!=NULL) return pleft;
    pright = seekValue(pn->right, val);
    if (pright != NULL) return pright;
    return NULL;
}
