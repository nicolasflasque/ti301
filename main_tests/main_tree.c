//
// Created by flasque on 27/06/2022.
//

#include <stdio.h>
#include <stdlib.h>

#include "../bintree/tree.h"
#include "../utils/intpow.h"
#include "../bintree/disp/displaybintree.h"


int main()
{
    p_node *nodes;

    t_tree t = createEmptyTree();
    t.root = createNode(18);
    p_node tmp;
    tmp = t.root;

    for (int cpt=1; cpt <=5;cpt++)
    {
        tmp->right = createNode(cpt*4);
        tmp = tmp->right;
    }
    displayTree(t);


    return 0;
}