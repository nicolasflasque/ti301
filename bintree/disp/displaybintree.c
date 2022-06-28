//
// Created by flasque on 28/06/2022.
//

#include <stdio.h>
#include "displaybintree.h"

/***
 * @authors user1571409 Nicolas Flasque
 * @copyright https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console
 *
 */

int _print_t(p_node root, int is_left, int offset, int depth, char s[20][LINE_SIZE])
{
    char b[20];
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
#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else

    for (int i = 0; i < width; i++)
        s[3 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[3 * depth - 2][offset + left + width/2 + i] = '-';

        s[3 * depth - 2][offset + left + width/2] = '+';
        s[3 * depth - 1][offset + left + width/2] = '|';
        s[3 * depth - 2][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

            for (int i = 0; i < left + width; i++)
                s[3 * depth - 2][offset - width/2 + i] = '-';

            s[3 * depth - 2][offset + left + width/2] = '+';
            s[3 * depth - 1][offset + left + width/2] = '|';
            s[3 * depth - 2][offset - width/2 - 1] = '+';
        }
#endif

    return left + width + right;
}

void print_t(p_node root)
{
    char s[20][LINE_SIZE];

    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%1023s", " ");

    _print_t(root, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}

void displayTree(t_tree t)
{
    print_t(t.root);
}