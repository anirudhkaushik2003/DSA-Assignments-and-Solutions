#include "bst.h"

int main()
{
    int conti = 1, index = 0;
    int x, num_elements = 0;
    tree *T = NULL;
    tree *P = malloc(sizeof(tree));
    assert(P != NULL);

    P->data = 1;

    /*while (1)
    {
        printf("Enter numbers: ");
        scanf("%d", &x);
        if (T == NULL)
            T = Insert(x, T);
        else
            Insert(x, T);
        num_elements++;
        printf("continue(0/1)?: ");
        scanf("%d", &conti);
        if (conti == 0)
        {
            break;
        }
    }*/
    T = binarytree();
    //int array[num_elements];
    Print(T, 0);
    printf("\n");
    printf("NOTE: DEPTH OF ROOT IS 0, -1 means node doesn't exist\n");
    printf("P = %d\n", P->data);
    finddepth(T, P);
    //printf("num of elements: %d\n", num_elements);
    //bstSort(T, 0);
    //printf("\n");

    /*copy(T,array,&index);
    for(int i=0;i<num_elements;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");*/
}
