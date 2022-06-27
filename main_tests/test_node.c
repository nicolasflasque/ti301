//
// Created by flasque on 26/06/2022.
//

#include "..\base\node\node.h"

int main()
{
    p_node p_n;
    p_n = createNode(12);
    displayNode(*p_n);
    return 0;
}