//
// Created by flasque on 27/06/2022.
//


#include "../../bintree/bintree.h"
#include "../../exercises/bintrees/fill_bin_tree_left_to_right.h"
#include "../../bintree/disp/displaybintree.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    t_tree t;
    t = createEmptyTree();

    fillCompleteTree(&t, 3);

    displayTree(t);

    for (int cpt = 0; cpt < 11; cpt++)
    {
        p_node seek = seekValue(t.root, cpt);
        if (seek == NULL)
        {
            printf("value %d not found : seek=%p\n", cpt, seek);
        } else
        {
            printf("value %d found at node %p\n", seek->value, seek);
        }
    }

    return 0;
}