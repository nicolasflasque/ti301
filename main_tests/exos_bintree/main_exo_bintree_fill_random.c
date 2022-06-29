//
// Created by flasque on 29/06/2022.
//

#include <stdlib.h>
#include "../../bintree/tree.h"
#include "../../exos_bintree/fill_bin_tree_random.h"
#include "../../bintree/disp/displaybintree.h"

int main()
{
    srand(64738);
    t_tree t;
    t= createEmptyTree();

    for (int v=1;v <= 10; v++)
    {
        addRandomElt(&t,v);
    }
    displayTree(t);
    return 0;
}