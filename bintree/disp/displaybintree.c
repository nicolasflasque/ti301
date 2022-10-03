//
// Created by flasque on 28/06/2022.
//

#include <stdio.h>
#include "displaybintree.h"

#define INIT_LINES 3
#define NB_LINES 4

/***
 * @authors user1571409 & Nicolas Flasque
 * @copyright https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console
 *
 */

int _print_t(p_node root, int is_left, int offset, int depth, char s[MAX_NB_LINES][LINE_SIZE])
{
    char b[20];
    char init[]= "[root@]";
    int width = 5;
    int left, right;

    if (root == NULL)
    {
        sprintf(b, "NULL ");
        left = right = 0;
       //return 0;
    }
    else
    {
        sprintf(b, "[%03d])", root->value);
        left = _print_t(root->left, 1, offset, depth + 1, s);
        right = _print_t(root->right, 0, offset + left + width, depth + 1, s);
    }

    if (!depth)
    {
        for (int i = 0; i < width+2; i++)
            s[0][offset + left + i - 3] = init[i];
        s[1][offset + left + width-3] = '|';
        s[2][offset + left + width-3] = 'v';
    }

    for (int i = 0; i < width; i++)
        s[INIT_LINES+NB_LINES * depth][offset + left + i] = b[i];
    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[INIT_LINES+NB_LINES * depth - 3][offset + left + width/2 + i] = '-';

        s[INIT_LINES+NB_LINES * depth - 3][offset + left + width/2-2] = '[';
        s[INIT_LINES+NB_LINES * depth - 3][offset + left + width/2-1] = 'L';
        s[INIT_LINES+NB_LINES * depth - 3][offset + left + width/2] = '@';
        s[INIT_LINES+NB_LINES * depth - 3][offset + left + width/2+1] = ']';


        s[INIT_LINES+NB_LINES * depth - 2][offset + left + width/2] = '|';

        s[INIT_LINES+NB_LINES * depth - 1][offset + left + width/2] = 'v';

        s[INIT_LINES+NB_LINES * depth - 3][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

            for (int i = 0; i < left + width; i++)
                s[INIT_LINES+NB_LINES * depth - 3][offset - width/2 + i] = '-';

            s[INIT_LINES+NB_LINES * depth - 3][offset + left + width/2-2] = '[';
            s[INIT_LINES+NB_LINES * depth - 3][offset + left + width/2-1] = 'R';
            s[INIT_LINES+NB_LINES * depth - 3][offset + left + width/2] = '@';
            s[INIT_LINES+NB_LINES * depth - 3][offset + left + width/2 +1] = ']';

            s[INIT_LINES+NB_LINES * depth - 2][offset + left + width/2] = '|';
            s[INIT_LINES+NB_LINES * depth - 1][offset + left + width/2] = 'v';

            s[INIT_LINES+NB_LINES * depth - 3][offset - width/2 - 1] = '+';
        }


    return left + width + right;
}

void print_t(p_node root)
{
    char s[MAX_NB_LINES][LINE_SIZE];

    for (int i = 0; i < MAX_NB_LINES; i++)
        sprintf(s[i], "%1023s", " ");

    _print_t(root, 0, 4, 0, s);

    for (int i = 0; i < MAX_NB_LINES; i++)
        printf("%s\n", s[i]);
}

void displayTree(t_tree t)
{
    print_t(t.root);
}