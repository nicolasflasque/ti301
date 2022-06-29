//
// Created by flasque on 27/06/2022.
//


#include "../../bintree/tree.h"
#include "../../exos_bintree/fill_bin_tree_left_to_right.h"
#include "../../bintree/disp/displaybintree.h"

int main()
{
    t_tree t;
    t = createEmptyTree();

    for (int cpt = 0; cpt < 9; cpt++)
    {
        addElt(&t, cpt+1);
    }

    displayTree(t);
    return 0;
}