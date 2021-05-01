#include "complex.h"

/*NOTE: 
As math.h library has been used, to compile the program use 
gcc main.c -lm
*/
int main()
{
    char operation[4];
    int n;
    int i;

    scanf("%s %d", operation, &n);

    /*for (i = 0; i < n; i++)
    {
        printf("%d ", number.a[i]);
    }*/
    if ((strcmp(operation, "ADD") == 0))
    {
        complex *number; //here 2 complex numbers of same bimension are declared
        number = malloc(sizeof(complex));
        complex *number2;
        number2 = malloc(sizeof(complex));
        complex *result;
        result = malloc(sizeof(complex));
        for (i = 0; i < n; i++)
        {
            scanf("%d", &number->a[i]);
        }
        for (i = 0; i < n; i++)
        {
            scanf("%d", &number2->a[i]);
        }
        result = ADD(*number, *number2, n);
        for (i = 0; i < n; i++)
        {
            printf("%d ", result->a[i]);
        }
        printf("\n");
    }
    if ((strcmp(operation, "SUB") == 0))
    {
        complex *number; //here 2 complex numbers of same bimension are declared
        number = malloc(sizeof(complex));
        complex *number2;
        number2 = malloc(sizeof(complex));
        complex *result;
        result = malloc(sizeof(complex));
        for (i = 0; i < n; i++)
        {
            scanf("%d", &number->a[i]);
        }
        for (i = 0; i < n; i++)
        {
            scanf("%d", &number2->a[i]);
        }
        result = SUB(*number, *number2, n);
        for (i = 0; i < n; i++)
        {
            printf("%d ", result->a[i]);
        }
        printf("\n");
    }
    if ((strcmp(operation, "MOD") == 0))
    {
        complex *number; //here 2 complex numbers of same bimension are declared
        number = malloc(sizeof(complex));
        float result;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &number->a[i]);
        }
        result = MOD(*number, n);
        printf("%.2f\n", result);
    }
    if ((strcmp(operation, "DOT") == 0))
    {
        complex *number; //here 2 complex numbers of same bimension are declared
        number = malloc(sizeof(complex));
        complex *number2;
        number2 = malloc(sizeof(complex));
        int result;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &number->a[i]);
        }
        for (i = 0; i < n; i++)
        {
            scanf("%d", &number2->a[i]);
        }
        result = DOT(*number, *number2, n);

        printf("%d\n", result);
    }
}
