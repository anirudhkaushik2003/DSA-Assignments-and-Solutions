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

void bstSort(tree *T)
{
   
    if (T != NULL)
    {

        //printf("%d\n", cur->data);
        //printf("|");
        bstSort(T->left);
        //depth = dep;
        printf("%d ", T->data);
        bstSort(T->right);
    }
}

void copy(tree *T, int array[], int *index)
{
    tree *first;
    first = T;

    if (T != NULL)
    {
        array[(*index)] = T->data;
        if (T->left != NULL)
        {
            (*index)++;
            copy(T->left, array, index);
        }
        if (T->right != NULL)
        {
            (*index)++;
            copy(T->right, array, index);
        }
    }
}

/*void sort(int array[])
{
    for ()
}*/
