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

void displayCategories(t_tree t)
{
    static char answers[2][4]={"no", "yes"};
    printf("is strict       : %s\n", answers[isStrictTree(t)]);
    printf("is perfect      : %s\n", answers[isPerfectTree(t)]);
    printf("is balanced     : %s\n", answers[isBalancedTree(t)]);
    printf("is degenerated  : %s\n", answers[isDegeneratedTree(t)]);

    return;
}


p_node FTnode(int n)
{
    p_node pn;
    if (n==0)
    {
        pn = createNode(0);
    }
    else if (n==1)
    {
        pn = createNode(1);
        pn->left = createNode(0);
        pn->right = createNode(0);
    }
    else
    {
        pn = createNode(n);
        pn->left = FTnode(n-1);
        pn->right = FTnode(n-2);
    }

    return pn;
}

t_tree fibtreerec(int n)
{
    t_tree t;
    t.root = FTnode(n);
    return t ;
}



t_tree fibtree(int n)
{
    t_tree t;
    p_node father, pcur, pzero, pone;

    pzero = createNode(0);
    pone = createNode(1);
    pone->left = pone->right = pzero;
    pcur = pone;
    if (n==0)
    {
        t.root = pzero;
    }
    else if (n==1)
    {
        t.root = pone;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            father = createNode(i);
            father->left = pcur;
            father->right = pcur->left;
            pcur = father;
        }

        t.root = father;
    }
    return t;

}

int main()
{
    t_tree mytree=createEmptyTree();
    insertBST(&mytree,8);
    insertBST(&mytree,6);
    insertBST(&mytree,13);
    insertBST(&mytree,3);
    insertBST(&mytree,7);
    insertBST(&mytree,10);
    insertBST(&mytree,14);
    insertBST(&mytree,1);
    insertBST(&mytree,4);

    displayTree(mytree);
    printf("is a BST ? %d\n",isBST(mytree));

    t_tree mt2 = strictTree();
    displayTree(mt2);
    printf("is a BST ? %d\n",isBST(mt2));

    t_tree mt3;
    insertBST(&mt3,1);
    insertBST(&mt3,2);
    insertBST(&mt3,3);
    insertBST(&mt3,4);
    displayTree(mt3);
    printf("is a BST ? %d\n",isBST(mt3));

    t_tree mt4 = sampleTree_1();
    displayTree(mt4);
    printf("is a BST ? %d\n",isBST(mt4));



/*    t_tree mytree1 = build1023DegeneratedTree();
    t_tree mytree2 = build1023PerfectTree();
*/
/*    displayTree(mytree=perfectTree());
    updateTreeDepth(mytree);
    displayTreeDepth(mytree);
    //displayTree(mytree);
*/
    /*for (int cpt=0; cpt < 10; cpt++)
    {
        t_tree F = fibtreerec(cpt);
        displayTree(F);
    }*/
   /* int n = 35;
    startTimer();
    t_tree FR = fibtreerec(n);
    stopTimer();
    displayTime();

    startTimer();
    t_tree FI = fibtree(n);
    stopTimer();
    displayTime();
*/

return 0;
}
