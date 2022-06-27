//
// Created by flasque on 26/06/2022.
//

#include <stdlib.h>
#include "n_node.h"

p_n_node createN_Node(int val)
{
    p_n_node nouv;

    nouv = (p_n_node)malloc(sizeof (t_n_node));
    nouv->value =val;
    nouv->nb_sons=0;
    nouv->sons = (p_n_node *)NULL;

    return nouv;
}

