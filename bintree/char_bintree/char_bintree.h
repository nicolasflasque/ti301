//
// Created by flasque on 28/09/2022.
//

#ifndef UNTITLED_CHAR_BINTREE_H
#define UNTITLED_CHAR_BINTREE_H

#include "../../base/node/char_node/char_node.h"

struct s_char_tree
{
    p_char_node root;
};

typedef struct s_char_tree t_char_tree, *_char_tree;

int charTreeNodeCount(t_char_tree );
t_char_tree createEmptyCharTree();
int getCharDepth(t_char_tree );
t_char_tree createCharTree(p_char_node );
p_char_node seekValue(p_node, char);

#endif //UNTITLED_CHAR_BINTREE_H
