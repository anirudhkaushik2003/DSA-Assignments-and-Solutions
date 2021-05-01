#include "deque.h"

int main()
{
    char function[20];
    double data, data1;
    printf("Enter a function after the prompt(type exit to exit):\n");
    printf("Enter:");

    while (1)
    {
        scanf("%s", function);
        if (strcmp(function, "push") == 0)
        {
            scanf("%lf %lf", &data, &data1);
            push(data, data1);
            
        }
        if (strcmp(function, "pop") == 0)
        {
            pop();
            
        }
        if (strcmp(function, "exit") == 0)
        {
            break;
        }
        if (strcmp(function, "inject") == 0)
        {
            scanf("%lf %lf", &data, &data1);
            inject(data, data1);
        }
        if (strcmp(function, "eject") == 0)
        {
            
            eject();
        }
    }
}