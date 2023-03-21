//
// Created by flasque on 27/06/2022.
//

#ifndef UNTITLED_BINTREE_H
#define UNTITLED_BINTREE_H

#include "../base/node/node.h"

typedef struct s_tree
{
    p_node root;
} t_tree, *p_tree;


p_node rightRot(p_node);

p_node leftRot(p_node);

p_node doubleRightrot(p_node);

p_node doubleLeftRot(p_node);

int treeNodeCount(t_tree);

t_tree createEmptyTree();

int getDepth(t_tree);

t_tree createTree(p_node);

p_node seekValue(p_node, int);

void insertBST(t_tree *, int);

p_node buildNodeFromArray(int *, int, int);

t_tree createTreeFromArray(int *, int);

int nodeHeight(p_node);

int treeHeight(t_tree);

void updateNodeDepth(p_node, int);

void updateTreeDepth(t_tree);

int isPerfectTree(t_tree);

int isDegeneratedTree(t_tree);

int isStrictNode(p_node);

int isStrictTree(t_tree);

int isBalancedNode(p_node);

int isBalancedTree(t_tree);

int isBST(t_tree);

int isNodeBST(p_node);

p_node searchBST(t_tree, int);

int nodeEqual(p_node, p_node);

int equal(t_tree, t_tree);

#endif //UNTITLED_BINTREE_H
