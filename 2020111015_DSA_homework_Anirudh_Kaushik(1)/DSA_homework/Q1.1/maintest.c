#include "complex.h"

int main()
{
    struct complex* new_node;
    new_node = malloc(sizeof(complex));
    for(int i = 0;i<1000000;i++)
    {
        new_node->a[i] = 0;
    }
    printf("%ld\n",sizeof(*new_node));
}