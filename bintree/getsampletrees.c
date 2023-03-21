//
// Created by flasque on 09/10/2022.
//
#include "getsampletrees.h"
#include <stdio.h>

t_tree oneNodeTree()
{
    int values[1] = {42};
    return createTreeFromArray(values, 1);
}

t_tree twoNodesTree_1()
{
    int values[3] = {6, -1, 2};
    return createTreeFromArray(values, 3);
}

t_tree twoNodesTree_2()
{
    int values[3] = {9, 9, -1};
    return createTreeFromArray(values, 3);
}

t_tree sampleTree_1()
{
    int values[7] = {4, 6, 7, 9, -1, 2, -1};
    return createTreeFromArray(values, 7);
}

t_tree strictTree()
{
    int values[15] = {15, 68, 2, 35, 3, -1, -1, -1, -1, 17, 6, -1, -1, -1, -1};
    return createTreeFromArray(values, 15);
}

t_tree completeTree()
{
    int values[15] = {15, 68, 2, 35, 3, 23, 42, 11, 4, 17, -1, -1, -1, -1, -1};
    return createTreeFromArray(values, 15);
}

t_tree perfectTree()
{
    int values[7] = {1, 2, 3, 4, 5, 6, 7};
    return createTreeFromArray(values, 7);
}

t_tree degeneratedLeftTree()
{
    int values[4] = {9, 6, 5, 1};
    t_tree t = createEmptyTree();
    t.root = createNode(values[0]);
    p_node cur = t.root;
    for (int cpt = 1; cpt < 4; cpt++)
    {
        cur->left = createNode(values[cpt]);
        cur = cur->left;
    }

    return t;
}

t_tree degeneratedRightTree()
{
    int values[4] = {3, 7, 5, 18};
    t_tree t = createEmptyTree();
    t.root = createNode(values[0]);
    p_node cur = t.root;
    for (int cpt = 1; cpt < 4; cpt++)
    {
        cur->right = createNode(values[cpt]);
        cur = cur->right;
    }

    return t;
}

#define SIZE 1023

t_tree build1023DegeneratedTree()
{
    t_tree t = createEmptyTree();
    int values[SIZE];
    for (int cpt = 0; cpt < SIZE; cpt++)
    {
        values[cpt] = cpt;
    }
    t.root = createNode(values[0]);
    p_node cur = t.root;
    for (int cpt = 1; cpt < SIZE; cpt++)
    {
        cur->right = createNode(values[cpt]);
        cur = cur->right;
    }

    return t;

}

t_tree build1023PerfectTree()
{
    t_tree t;
    int values[1023];
    for (int cpt = 0; cpt < 1023; cpt++)
    {
        values[cpt] = cpt;
    }
    t = createTreeFromArray(values, 1023);

    return t;
}