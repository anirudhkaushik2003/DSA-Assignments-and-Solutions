#include "bst.h"

void Print(tree *T, int depth)
{
    tree *cur;
    cur = T;
    int dep;
    dep = depth;
    if (T != NULL)
    {

        while (depth > 0)
        {

            printf("_");
            depth--;
            if (depth == 1)
            {
                //printf("|");
            }
        }

        printf("%d\n", cur->data);
        printf("|");
        Print(cur->left, dep + 1);
        depth = dep;

        Print(cur->right, dep + 1);
    }
}
int finddepth(tree *T, tree *P)
{
    printf("%d ", finddepth1(T, P));
}
int finddepth1(tree *T, tree *P)
{

    if (T != NULL)
    {
        int level;
        if (T->left != NULL)
            T->left->depth = T->depth + 1;
        if (T->right != NULL)
            T->right->depth = T->depth + 1;

        if (T->data == P->data)
        {
            return T->depth;
        }
        else
        {
            //depth++;

            level = finddepth1(T->left, P);
            if (level != -1)

                return level;

            level = finddepth1(T->right, P);
            if (level != -1)

                return level;
        }
    }
    else
    {

        return -1;
    }
}
/*int _finddepth(tree *T, tree *P, int depth)
{
    int level;

    if (T != NULL)
    {
        if (T->data == P->data)
        {
            return depth;
        }
        else
        {
            //depth++;

            level = _finddepth(T->left, P, depth + 1);
            if (level != -1)

                return level;
            else
            {
                level = _finddepth(T->right, P, depth + 1);
                if (level != -1)

                    return level;
            }
        }
    }
    else
    {

        return -1;
    }
}*/

tree *binarytree()
{
    tree *bt, *first, *T;
    bt = malloc(sizeof(tree));
    bt->data = 1;
    first = bt;
    T = first;

    bt = malloc(sizeof(tree));
    bt->data = 2;
    first->left = bt;
    bt = malloc(sizeof(tree));
    bt->data = 3;
    first->right = bt;
    first = first->left;
    tree *bt_1;
    bt_1 = malloc(sizeof(tree));
    bt_1->data = 4;
    first->left = bt_1;
    bt_1 = malloc(sizeof(tree));
    bt_1->data = 5;
    first->right = bt_1;
    first = bt;
    bt = malloc(sizeof(tree));
    bt->data = 6;
    bt->right = malloc(sizeof(tree));
    bt->right->data = 9;
    first->left = bt;
    bt = malloc(sizeof(tree));
    bt->data = 7;
    first->right = bt;
    first = bt_1;
    bt_1 = malloc(sizeof(tree));
    bt_1->data = 8;
    first->left = bt_1;

    return T;
}

/*void sort(int array[])
{
    for ()
}*/
