//
// Created by flasque on 27/06/2022.
//

#include <stdio.h>
#include <stdlib.h>

#include "../bintree/bintree.h"
#include "../bintree/disp/displaybintree.h"
#include "../bintree/getsampletrees.h"
#include "../utils/timer/timer.h"
static int tree1[1] ={-1};
static int tree2[3] = {4,8,-1};
static int tree3[3] = {4,-1,8};
static int tree4[7] = {5,1,2,-1,6,2,9};

void displayCharacteristics(t_tree t)
{
    int N,H;
    startTimer();
    H = treeHeight(t);
    stopTimer();
    displayTime();
    startTimer();
    N = treeNodeCount(t);
    stopTimer();
    displayTime();

    printf("height :  %2d  - nodes : %4d\n",H,N);
    return;
}


int main()
{
    t_tree mybst=createEmptyTree();
    int vals[7]={15,12,30,9,13,1,10};

    for (int cpt=0; cpt < 7; cpt++)
    {
        insertBST(&mybst,vals[cpt]);
    }
    displayTree(mybst);
    mybst.root=rightRot(mybst.root);
    displayTree(mybst);
    mybst.root=leftRot(mybst.root);
    displayTree(mybst);
    return 0;
}
