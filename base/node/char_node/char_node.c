//
// Created by flasque on 28/09/2022.
//


#include <stdlib.h>
#include <stdio.h>
#include "char_node.h"

p_char_node createCharNode(char val)
{
    p_char_node nouv;

    nouv = (p_char_node )malloc(sizeof(t_char_node));
    nouv->value = val;
    nouv->left = nouv->right = NULL;

    return nouv;
}

void displayCharNode(t_node n)
{
    char fmt1[]="[ %c | left @ | right @-]-->\n";
    char fmt2[]="            |\n";
    char fmt3[]="            v\n";

    printf(fmt1, n.value);
    printf(fmt2); printf(fmt2); printf(fmt3);

    return;
}

