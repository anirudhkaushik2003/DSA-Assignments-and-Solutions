#include "bst.h"

tree *Insert(int x, tree *T)
{
    if (T == NULL)
    {
        T = malloc(sizeof(tree));
        assert(T != NULL);

        T->data = x;
        T->left = NULL;
        T->right = NULL;
    }
    else
    {
        if (x < T->data)
        {
            T->left = Insert(x, T->left);
        }
        else
        {
            if (x > T->data)
            {
                T->right = Insert(x, T->right);
            }
        }
    }

    return T;
}

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
int isbst(tree *T)
{
    printf("%d ", isbst1(T));
}
int isbst1(tree *T)
{

    if (T != NULL)
    {
        if (T->left != NULL && T->data < maxValue(T->left))
        {
            return 0;
        }
        if (T->right != NULL && T->data > minValue(T->right))
        {
            return 0;
        }
        if (isbst1(T->left) == 0 || isbst1(T->right) == 0)
        {
            return 0;
        }
        return 1;
    }
    else
        return 1;
}

int minValue(tree *T)
{
    int min;
    int rmin;
    int lmin;
    if (T != NULL)
    {
        min = T->data;
        lmin = minValue(T->left);
        rmin = minValue(T->right);
        if (min > lmin)
        {
            min = lmin;
        }

        if (rmin < min)
        {
            min = rmin;
        }

        return min;
    }
    else
        return INT_MAX;
}

int maxValue(tree *T)
{
    int max;
    int rmax;
    int lmax;
    if (T != NULL)
    {
        max = T->data;
        lmax = maxValue(T->left);
        rmax = maxValue(T->right);
        if (max < lmax)
        {
            max = lmax;
        }

        if (rmax > max)
        {
            max = rmax;
        }

        return max;
    }
    else
        return INT_MIN;
}

tree *binarytree()
{
    tree *bt, *first, *T;
    bt = malloc(sizeof(tree));
    bt->data = 6;
    first = bt;
    T = first;

    bt = malloc(sizeof(tree));
    bt->data = 2;
    first->left = bt;
    bt = malloc(sizeof(tree));
    bt->data = 8;
    first->right = bt;
    first = first->left;
    tree *bt_1;
    bt_1 = malloc(sizeof(tree));
    bt_1->data = 1;
    first->left = bt_1;
    bt_1 = malloc(sizeof(tree));
    bt_1->data = 4;
    first->right = bt_1;
    first = bt;
    bt = malloc(sizeof(tree));
    bt->data = 7;
    first->left = bt;
    bt = malloc(sizeof(tree));
    bt->data = 9;
    first->right = bt;
    first = bt_1;
    bt_1 = malloc(sizeof(tree));
    bt_1->data = 3;
    first->left = bt_1;
    bt_1 = malloc(sizeof(tree));
    bt_1->data = 5;
    first->right = bt_1;

    return T;
}
