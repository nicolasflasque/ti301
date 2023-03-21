//
// Created by flasque on 29/06/2022.
//


#include <stdbool.h>
#include <stdlib.h>

#include "fill_bin_tree_random.h"

void addRandomElt(p_tree p_tr, int val)
{
    p_node nouv;
    p_node father = p_tr->root;
    bool over = false;

    nouv = createNode(val);

    if (p_tr->root == NULL)
    {
        p_tr->root = nouv;
    } else
    {
        while (!over)
        {
            bool seekLeft = (bool) (rand() % 2);

            if (seekLeft)
            {
                if (father->left == NULL)
                {
                    father->left = nouv;
                    over = true;
                } else
                {
                    father = father->left;
                }
            } else
            {
                if (father->right == NULL)
                {
                    father->right = nouv;
                    over = true;
                } else
                {
                    father = father->right;
                }
            }
        }
    }

    return;
}
