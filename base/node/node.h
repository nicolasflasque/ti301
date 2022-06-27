//
// Created by flasque on 26/06/2022.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

struct s_node
{
    int value;
    struct s_node   *left, *right;
};

typedef struct s_node t_node, *p_node;

p_node createNode(int);

void displayNode(t_node);

#endif //UNTITLED_NODE_H
