//
// Created by flasque on 27/06/2022.
//
#include <stdlib.h>
#include "fill_bin_tree_left_to_right.h"
#include "../../utils/intpow/intpow.h"

void addElt(p_tree ptr_t, int val)
{
    p_node ptr_new = createNode(val);

    if (ptr_t->root == NULL)
    {
        ptr_t->root = ptr_new;
    } else
    {
        p_node t_p_nodes[100];
        int cpt = 0;
        int pos = 0;
        int fini = 0;
        t_p_nodes[cpt++] = ptr_t->root;
        p_node father;

        while (!fini)
        {
            father = t_p_nodes[pos];
            if (father->left == NULL)
            {
                father->left = ptr_new;
                fini = 1;
            } else
            {
                t_p_nodes[cpt++] = father->left;
            }
            if ((!fini) && (father->right == NULL))
            {
                father->right = ptr_new;
                fini = 1;
            } else
            {
                t_p_nodes[cpt++] = father->right;
            }

            pos++;
        }

    }

    return;
}

void fillCompleteTree(t_tree *p_tree, int level)
{
    int nbNodes = intpow(2, level) - 1;
    for (int nodenum = 1; nodenum <= nbNodes; nodenum++)
    {
        addElt(p_tree, nodenum);
    }

    return;
}
