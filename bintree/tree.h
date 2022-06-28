//
// Created by flasque on 27/06/2022.
//

#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H

#include "../base/node/node.h"

struct s_tree
{
    p_node root;
};


typedef  struct s_tree t_tree, *p_tree;

t_tree createEmptyTree();
int getDepth(t_tree);

#endif //UNTITLED_TREE_H
