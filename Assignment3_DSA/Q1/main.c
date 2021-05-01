#include "hash.h"

int main()
{
    int key;

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

    while (1)
    {
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
            }
            //PrintList_separatechaining(H);
        }
        if (strcmp(function, "quadratic-probing") == 0)
        {

            scanf("%d", &N);
            scanf("%d", &Q);
            hashtbl_LP *H;
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
            //PrintList_LP(H);
        }
    }
}