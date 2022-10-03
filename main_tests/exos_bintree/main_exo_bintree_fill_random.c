//
// Created by flasque on 29/06/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include "../../bintree/bintree.h"
#include "../../exercises/bintrees/fill_bin_tree_random.h"
#include "../../bintree/disp/displaybintree.h"

int main()
{
    srand(42543);
    t_tree t;
    t= createEmptyTree();

    for (int v=1;v <= 7; v++)
    {
        addRandomElt(&t,rand()%29-14);
    }
    displayTree(t);

    printf("height : %d\n", getDepth(t));
    printf("node count : %d\n",treeNodeCount(t));

    return 0;
}