//
// Created by flasque on 26/06/2022.
//

#ifndef UNTITLED_N_NODE_H
#define UNTITLED_N_NODE_H

struct s_n_node
{
    int value;
    int nb_sons;
    struct s_n_node **sons;
};

typedef struct s_n_node t_n_node, *p_n_node;

p_n_node createN_Node(int);

#endif //UNTITLED_N_NODE_H
