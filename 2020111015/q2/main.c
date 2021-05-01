#include "../hash.h"
#include <time.h>

int main()
{
    float starttime = clock() / (float)CLOCKS_PER_SEC;
    int N, count = 0;
    char key[33];
    int i = 0;
    scanf("%d", &N);
    //printf("number of elements entered = %d\n", N);
    hashtbl_dictionary *H;
    int L;
    H = InitializeTable_dictionary(N);
    while (N != 0)
    {
        getchar();
        scanf("%s", key);
        Insert_dictionary(key, H);
        N--;
    }
    float endtime = clock() / (float)CLOCKS_PER_SEC;
    /*printf("Run time = %f\n", endtime - starttime);
    printf("number of collisions = %f\n", analyser(0, 1) );*/
    //PrintList_dictionary(H);
    getchar();
    scanf("%d", &N);
    char array1[N][33];
    while (N != 0)
    {

        getchar();
        scanf("%s", key);

        L = Find_dictionary(key, H);
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
