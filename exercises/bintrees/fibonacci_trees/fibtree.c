//
// Created by flasque on 11/10/2022.
//
t_tree fibtree(int n)
{
    t_tree t;
    p_node father, pcur, pzero, pone;

    pzero = createNode(0);
    pone = createNode(1);
    pone->left = pone->right = pzero;
    pcur = pone;
    if (n == 0)
    {
        t.root = pzero;
    } else
    {
        if (n == 1)
        {
            t.root = pone;
        } else
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
    }
    return t;

}
