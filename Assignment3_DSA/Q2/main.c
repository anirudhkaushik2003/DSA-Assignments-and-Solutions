#include "hash.h"

int main()
{
    int N, count = 0;
    char key[33];
    int i = 0;
    scanf("%d", &N);

    hashtbl *H;
    int L;
    H = InitializeTable(N);
    while (N != 0)
    {
        getchar();
        scanf("%s", key);
        Insert(key, H);
        N--;
    }
    //PrintList(H);
    getchar();
    scanf("%d", &N);
    char array1[N][33];
    while (N != 0)
    {

        getchar();
        scanf("%s", key);

        L = Find(key, H);
        if (L == 0)
        {
            strcpy(array1[i], key);
            // printf("table size = %d\n", H->TableSize);
            count++;
            i++;
            //printf("table size = %d\n", H->TableSize);
        }
        N--;
    }
    printf("%d\n", count);

    for (i = 0; i < count; i++)
    {
        printf("%s\n", (array1[i]));
    }
}