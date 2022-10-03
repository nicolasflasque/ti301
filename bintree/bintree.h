//
// Created by flasque on 27/06/2022.
//

#ifndef UNTITLED_BINTREE_H
#define UNTITLED_BINTREE_H

#include "../base/node/node.h"

typedef struct s_tree
{
    p_node root;
} t_tree, *p_tree;


int treeNodeCount(t_tree);
t_tree createEmptyTree();
int getDepth(t_tree);
t_tree createTree(p_node);
p_node seekValue(p_node, int);
#endif //UNTITLED_BINTREE_H
