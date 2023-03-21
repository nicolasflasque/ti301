//
// Created by flasque on 27/06/2022.
//
#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"
#include "../utils/intpow/intpow.h"

#define max(a,b) ((a)>(b)?(a):(b))

int nodeCount(p_node);


t_tree createEmptyTree()
{
    t_tree tree;

    tree.root = NULL;

    return tree;
}


int getNodeDepth(p_node p_n)
{
    int depth;

    if (p_n ==NULL)
    {
        depth = 0;
    }
    else
    {
        int leftheight = getNodeDepth(p_n->left);
        int rightheight = getNodeDepth(p_n->right);
        depth = 1+max(leftheight,rightheight);
    }

    return depth;
}

int getDepth(t_tree t)
{
    return getNodeDepth(t.root);
}

t_tree createTree(p_node p_n)
{
    t_tree t;
    t.root = p_n;
    
    return t;
}

int treeNodeCount(t_tree t)
{
    return nodeCount(t.root);
}

int nodeCount(p_node p_n)
{
    int count;
    if (p_n == NULL)
    {
        count = 0;
    }
    else
    {
        count = 1+nodeCount(p_n->left)+nodeCount(p_n->right);
    }
    return count;
}

p_node seekValue(p_node pn, int val)
{

    p_node pleft, pright;
    if (pn==NULL) return NULL;
    if (pn->value == val) return pn;
    pleft = seekValue(pn->left,val);
    if (pleft!=NULL) return pleft;
    pright = seekValue(pn->right, val);
    if (pright != NULL) return pright;
    return NULL;
}

void insertBST(t_tree *pt, int value)
{
    p_node pn = createNode(value);
    p_node cur, father;

    if (pt->root == NULL)
    {
        pt->root = pn;
    }
    else
    {
        cur = pt->root;
        while (cur != NULL)
        {
            father = cur;
            if (pn->value > cur->value)
            {
                cur = cur->right;
            }
            else
            {
                cur = cur->left;
            }
        }
        if (pn->value > father->value)
        {
            father->right = pn;
        }
        else
        {
            father->left = pn;
        }
    }
    return;
}

t_tree createBSTfromArray(int *values, int size)
{
    t_tree t;

    for (int cpt=0; cpt < size; cpt++)
    {
        insertBST(&t, values[cpt]);
    }

    return t;
}

p_node buildNodeFromArray(int *values, int size, int idx)
{
    p_node res;
    if ((idx >= size) || (values[idx] == -1))
    {
        return NULL;
    }

    res = createNode(values[idx]);
    res->left=buildNodeFromArray(values,size,2*idx+1);
    res->right=buildNodeFromArray(values,size, 2*idx+2);
    return res;
}

t_tree createTreeFromArray(int *values,int size)
{
    t_tree t;
    t.root = buildNodeFromArray(values,size,0);
    return t;
}


int nodeHeight(p_node pn)
{
    if (pn==NULL)
        return -1;

    int leftheight = nodeHeight(pn->left);
    int rightheight = nodeHeight(pn->right);
    return 1+max(leftheight,rightheight);
}

int treeHeight(t_tree t)
{
    return nodeHeight(t.root);
}

void updateNodeDepth(p_node pn, int d)
{
    if (pn != NULL)
    {
        pn->depth = d;
        updateNodeDepth(pn->left,d+1);
        updateNodeDepth(pn->right, d+1);
    }
    return;
}

void updateTreeDepth(t_tree t)
{
    updateNodeDepth(t.root, 0);
}

int isPerfectTree(t_tree t)
{
    int N = treeNodeCount(t);
    int H = treeHeight(t);

    return (N==intpow(2,H+1)-1);
}

int isDegeneratedTree(t_tree t)
{
    int N = treeNodeCount(t);
    int H = treeHeight(t);
    return (N==H+1);
}

int isStrictNode(p_node pn)
{
    if (pn==NULL)
    {
        return 1;
    }
    if ((pn->left == NULL) != (pn->right == NULL))
    {
        return 0;
    }

    int strictleft = isStrictNode(pn->left);
    int strictright = isStrictNode(pn->right);

    return (strictleft && strictright);
}

int isStrictTree(t_tree t)
{
    if (isPerfectTree(t)==1)
    {
        return 1;
    }
    if ((isDegeneratedTree(t)==1) && (treeNodeCount(t)>2))
    {
        return 0;
    }

    return isStrictNode(t.root);
}

int isBalancedNode(p_node pn)
{
    if (pn==NULL)
    {
        return 1;
    }

    int diffHeight = nodeHeight(pn->left)-nodeHeight(pn->right);

    if (abs(diffHeight) > 1)
    {
        return 0;
    }

    return ((isBalancedNode(pn->left)) && (isBalancedNode(pn->right)));
}
//
int isBalancedTree(t_tree t)
{
    return isBalancedNode(t.root);
}

p_node rightRot(p_node root)
{
    p_node pivot = root->left;
    root->left = pivot->right;
    pivot->right = root;
    return pivot;
}

p_node leftRot(p_node root)
{
    p_node pivot = root->right;
    root->right = pivot->left;
    pivot->left = root;
    return pivot;
}
p_node doubleRightrot(p_node root)
{
    root->left = leftRot(root->left);
    return rightRot(root);
}
p_node doubleLeftRot(p_node root)
{
    root->right = rightRot(root->right);
    return leftRot(root);
}

int isNodeBST(p_node pn)
{
    if (pn == NULL)
    {
        return 1;
    }
    if (pn->left != NULL)
    {
        if (pn->value < pn->left->value)
        {
            return 0;
        }
    }
    if (pn->right != NULL)
    {
        if (pn->value > pn->right->value)
        {
            return 0;
        }
    }

    return isNodeBST(pn->left) && isNodeBST(pn->right);

}

int isBST(t_tree t)
{
    return isNodeBST(t.root);
}

int segfaultFunc(p_node pn)
{

  int valLeft  = pn->left->value;
  int valRight = pn->right->value;

  return pn->value + valLeft + valRight;
};

int someFunc(p_node pn1, p_node pn2)
{
    if (pn1 == pn2)
    {
        return 1;
    }
    if ((pn1==NULL) != (pn2==NULL))
    {
        return 0;
    }

    if (pn1->value != pn2->value)
    {
        return 0;
    }

    return someFunc(pn1->left, pn2->left) && someFunc(pn1->right,pn2->right);

}

int equal(t_tree t1, t_tree t2)
{
    return nodeEqual(t1.root, t2.root);
}

p_node searchBST(t_tree t, int val)
{
    p_node cur;
    cur = t.root;
    while ((cur != NULL) && (cur->value !=val))
    {
        if (val > cur->value)
        {
            cur = cur->right;
        }
        else
        {
            cur = cur->left;
        }
    }
    return cur;
}