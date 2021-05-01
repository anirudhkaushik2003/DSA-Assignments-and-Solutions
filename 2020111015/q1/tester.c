#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int N = 2000;
    int a[100000], temp;
    srand(time(NULL));
    for (int i = 0; i < 100000;)
    {
        temp = rand() % 1000007;
        if (temp % 2 == 0)
        {
            a[i] = temp;
            i++;
        }
    }
    printf("quadratic-probing\n2000\n%d\n", N);
    for (int i = 0; i < N; i++)
    {
        printf("+ %d\n", a[i]);
    }
    /*for (int i = 0; i < 1000; i++)
    {
        printf("? %d\n", a[rand() % 100000]);
    }*/
}

