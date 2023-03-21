#include <stdlib.h>
#include <stdio.h>

#include "../bintree/char_bintree/char_bintree.h"
#include "../bintree/char_bintree/rec_visit.h"

int main()
{
    t_char_tree mytree;
    p_char_node pcur;
    mytree.root = createCharNode('*');
    mytree.root->left = createCharNode('+');
    pcur = mytree.root->left;
    pcur->left = createCharNode('3');
    pcur->right = createCharNode('1');

    mytree.root->right = createCharNode('/');
    pcur = mytree.root->right;
    pcur->left=createCharNode('7');
    pcur->right=createCharNode('-');
    pcur = pcur->right;
    pcur->left=createCharNode('3');
    pcur->right=createCharNode('2');

    prefixVisit(mytree);
    printf("\n");
    postfixVisit(mytree);
    printf("\n");
    infixVisit(mytree);

    float val = evalTree(mytree);
    printf("value : %f\n",val);

    return EXIT_SUCCESS;
}