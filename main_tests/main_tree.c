//
// Created by flasque on 27/06/2022.
//

#include <stdio.h>
#include <stdlib.h>

#include "../bintree/bintree.h"
#include "../bintree/disp/displaybintree.h"


int main()
{
    p_node *nodes;

    t_tree t = createEmptyTree();
    t_tree sub_tree;
    t.root = createNode(18);
    p_node tmp;
    tmp = t.root;

    for (int cpt=1; cpt <=5;cpt++)
    {
        tmp->right = createNode(cpt*4);
        tmp = tmp->right;
    }
    displayTree(t);
    sub_tree = createTree(t.root->right->right);
    displayTree(sub_tree);

    p_node seek = seekValue(t.root,8);
    printf("%d\n",seek);
    if (seek != NULL) printf("%d\n",seek->value);

    return 0;
}