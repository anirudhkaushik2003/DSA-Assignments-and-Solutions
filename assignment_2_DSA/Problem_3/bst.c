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
int height(tree *T)
{
    printf("%d ", height1(T));
}
int height1(tree *T)
{
    int left_height;
    int right_height;
    if (T != NULL)
    {
        left_height = height1(T->left);
        right_height = height1(T->right);
        if (left_height < right_height)
        {
            return right_height + 1;
        }
        else
        {
            return left_height + 1;
        }
    }
    else
        return -1;
}

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
    first->left = bt;
    bt = malloc(sizeof(tree));
    bt->data = 7;
    first->right = bt;
    first = bt_1;
    /*bt_1 = malloc(sizeof(tree));
    bt_1->data = 8;
    first->left = bt_1;*/

    return T;
}

/*void sort(int array[])
{
    for ()
}*/
