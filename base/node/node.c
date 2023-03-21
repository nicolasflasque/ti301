//
// Created by flasque on 26/06/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include "node.h"

p_node createNode(int val)
{
    p_node nouv;

    nouv = (p_node) malloc(sizeof(t_node));
    nouv->value = val;
    nouv->left = nouv->right = NULL;

    return nouv;
}

void displayNode(t_node n)
{
    char fmt1[] = "[ %d | left @ | right @-]-->\n";
    char fmt2[] = "            |\n";
    char fmt3[] = "            v\n";

    printf(fmt1, n.value);
    printf(fmt2);
    printf(fmt2);
    printf(fmt3);

    return;
}

