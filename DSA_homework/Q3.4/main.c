#include "my_stack.h"

int main()
{
    char function[20];
    double data;
    double data1;
    int ch = 1;
    while (1)
    {
        scanf("%s", function);
        if (strcmp(function, "push") == 0)
        {
            //printf("Enter 2 numbers(comma separated): ");
            scanf("%lf %lf", &data, &data1);
            push(data, data1);
            PrintStack();
        }
        if (strcmp(function, "pop") == 0)
        {
            pop();
            PrintStack();
        }
        if (strcmp(function, "print") == 0)
        {
            PrintStack();
        }
        if (strcmp(function,"exit") == 0)
        {
            break;
        }
        /*if (strcmp(function,"pop_mf") == 0)
        {
            printf("Watch you language bruh\nnot cool\nim leaving\n");
            return 0;
        }*/

        //printf("continue?(1/0):");
        //scanf("%d", &ch);
    }
}