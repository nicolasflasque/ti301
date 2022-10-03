//
// Created by flasque on 28/09/2022.
//

#include <stdlib.h>
#include <stdio.h>

#include "rec_visit.h"

// prototype des fonctions locales
void nodePrefixVisit(p_node);
void nodeInfixVisit(p_node);
void nodePostfixVisit(p_node);


// definition des fonctions locales

void nodePrefixVisit(p_node p_n)
{
    if (p_n != NULL) printf(" %d ", p_n->value);
    if (p_n->left != NULL) nodePrefixVisit(p_n->left);
    if (p_n->right != NULL) nodePrefixVisit(p_n->right);
    return;
}

void nodeInfixVisit(p_node p_n)
{
    if (p_n->left != NULL) nodeInfixVisit(p_n->left);
    if (p_n != NULL) printf(" %d ", p_n->value);
    if (p_n->right != NULL) nodeInfixVisit(p_n->right);
    return;
}

void nodePostfixVisit(p_node p_n)
{
    if (p_n->left != NULL) nodePostfixVisit(p_n->left);
    if (p_n->right != NULL) nodePostfixVisit(p_n->right);
    if (p_n != NULL) printf(" %d ", p_n->value);
    return;
}
// definition des fonctions exportées

void prefixVisit(t_tree t)
{
    nodePrefixVisit(t.root);
    return;
}

void infixVisit(t_tree t)
{
    nodeInfixVisit(t.root);
    return;
}

void postfixVisit(t_tree t)
{
    nodePostfixVisit(t.root);
    return;
}