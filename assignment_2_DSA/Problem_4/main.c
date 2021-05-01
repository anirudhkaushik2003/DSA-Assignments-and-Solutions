#include "bst.h"

int main()
{
    tree *T = NULL;
    /*int conti = 1,index = 0;
    int x, num_elements = 0;
    
    while (1)
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
    }
    int array[num_elements];*/
    T = binarytree();
    Print(T, 0);
    printf("\n");
    /*printf("min in tree: %d\n",minValue(T));
    printf("max in tree: %d\n",maxValue(T));*/
    isbst(T);
   
    printf("\n");
    
   
}
