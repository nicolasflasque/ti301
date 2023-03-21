//
// Created by flasque on 28/09/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include "../bintree/visits/rec_visit.h"
#include "../exercises/bintrees/fill_bin_tree_left_to_right.h"
#include "../bintree/visits/breadth_first.h"

int main(int argc, char *argv[])
{
    t_tree t;

    t = createEmptyTree();
    fillCompleteTree(&t, 3);
    //displayTree(t.root);
    printf("Prefix visit\n");
    prefixVisit(t);
    printf("\nInfix visit\n");
    infixVisit(t);
    printf("\nPostfix visit\n");
    postfixVisit(t);
    printf("\nbreadth-first visit\n");
    breadthFirstVisit(t);


    return EXIT_SUCCESS;
}