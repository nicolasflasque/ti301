//
// Created by flasque on 28/09/2022.
//

#ifndef UNTITLED_CHAR_NODE_H
#define UNTITLED_CHAR_NODE_H

struct s_char_node
{
    char value;
    struct s_char_node   *left, *right;
    int depth;
};

typedef struct s_char_node t_char_node, *p_char_node;

/***
 * @brief
 * @param
 * @return
 */
p_char_node createCharNode(char);

/***
 * @brief
 * @param
 * @return
 */
void displayNode(t_char_node);

#endif //UNTITLED_CHAR_NODE_H
