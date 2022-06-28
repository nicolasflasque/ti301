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
    //displayTree(t);
    p_node  pnew = createNode(4);
    t.root = pnew;
    //displayTree(t);
    t.root->right=createNode(5);
    t.root->right->left=createNode(42);
    //t.root->left=createNode(-2);
    displayTree(t);


    return 0;
}