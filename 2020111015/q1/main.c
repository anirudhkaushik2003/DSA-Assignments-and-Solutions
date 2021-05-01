#include "../hash.h"
#include <time.h>

int main()
{
    int temo;
    float starttime = clock() / (float)CLOCKS_PER_SEC;
    unsigned int key;

    char function[20];
    char oper;
    int N, Q;

    /*printf("table size = %d\n", H->TableSize);

    while (N != 0)
    {
        scanf("%d", &key);
        Insert_QP(key, H);
        N--;
    }
    PrintList_LP(H);
    printf("position = %d\n", FindPos_QP(5, H));*/

    scanf("%s", function);
    if (strcmp(function, "linear-probing") == 0)
    {

        scanf("%d", &N);
        scanf("%d", &Q);
        hashtbl_LP *H;
        H = InitializeTable_LinearProbing(N);
        for (int i = 0; i < Q; i++)
        {
            getchar();
            scanf("%c %d", &oper, &key);
            if (oper == '+')
                Insert_LP(key, H);
            else
            {
                if (oper == '?')
                    printf("%d\n", FindPos_LP(key, H));
            }
        }
        //PrintList_LP(H);
    }
    if (strcmp(function, "separate-chaining") == 0)
    {

        scanf("%d", &N);
        scanf("%d", &Q);
        hashtbl *H;
        H = InitializeTable_separatechaining(N);
        for (int i = 0; i < Q; i++)
        {
            getchar();
            scanf("%c %d", &oper, &key);
            if (oper == '+')
                Insert_separatechaining(key, H);
            else
            {
                if (oper == '?')
                    printf("%d\n", Find_separatechainingPos(key, H));
            }
            /*if (i == Q - 1)
                printf("average number of probes = %f\n", );*/
        }
        //PrintList_separatechaining(H);
    }
    if (strcmp(function, "quadratic-probing") == 0)
    {

        scanf("%d", &N);
        scanf("%d", &Q);
        hashtbl_LP *H;
       /* if (((float)Q / (float)N) >= 0.5)
        {
            float var = (float)Q / (float)N;
            printf("value of alpha = %lf\n", var);

            N = 2 * N;
            printf("Table size = %d\n", N);
        }*/

        H = InitializeTable_QuadProbing(N);
        for (int i = 0; i < Q; i++)
        {
            getchar();
            scanf("%c %d", &oper, &key);
            if (oper == '+')
                Insert_QP(key, H);
            else
            {
                if (oper == '?')
                    printf("%d\n", FindPos_QP(key, H));
            }
        }
        //PrintList_QP(H);
    }
    float endtime = clock() / (float)CLOCKS_PER_SEC;
    /*printf("run time = %f\n", endtime - starttime);
    printf("average number of probes = %f\n", analyser(0, 1));*/
}
