#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a[100000];
    srand(time(NULL));
    for (int i = 0; i < 100000; i++)
    {
        a[i] = rand() % 1000007;
    }
    for (int i = 0; i < 100000; i++)
    {
        printf("+ %d\n", a[i]);
    }
    for (int i = 0; i < 1000; i++)
    {
        printf("? %d\n", a[rand() % 100000]);
    }
}