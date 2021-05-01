#include "hash.h"

Index Hash(const char *key, const int TableSize)
{
    unsigned int HashVal = 0;
    while (*key != '\0')
    {
        HashVal = (HashVal << 5) ^ *key++;
    }
    return (HashVal % TableSize);
}

hashtbl *InitializeTable(int N)
{
    //N is Table size
    hashtbl *H;
    int i;

    H = malloc(sizeof(hashtbl));
    assert(H != NULL);

    H->TableSize = N;

    H->TheLists = malloc(sizeof(list *) * H->TableSize);
    assert(H->TheLists != NULL);

    for (i = 0; i < H->TableSize; i++)
    {
        H->TheLists[i] = malloc(sizeof(list));
        assert(H->TheLists[i] != NULL);
        H->TheLists[i]->next = NULL;
        H->TheLists[i]->occupied = false;
        H->TheLists[i]->common = false;
    }

    return H;
}
list *Find_separatechaining(char *key, const hashtbl *H)
{
    list *P, *L;
    int i = 0;
    L = H->TheLists[Hash(key, H->TableSize)];
    P = L->next;
    while (P != NULL && strcmp(P->word, key) != 0)
    {
        P = P->next;
        i++;
    }
    return P;
}

void Insert(char *key, hashtbl *H)
{
    Position Pos, NewCell;
    list *L;
    int aux;

    Pos = Find_separatechaining(key, H);
    if (Pos == NULL)
    {
        NewCell = malloc(sizeof(list));
        assert(NewCell != NULL);
        aux = Hash(key, H->TableSize);
        L = H->TheLists[aux];
        //H->TheLists[aux]->occupied = true;
        L->occupied = true;
        NewCell->next = L->next;
        strcpy(NewCell->word, key);
        L->next = NewCell;
        NewCell->occupied = true;
        NewCell->occupied = false;
    }
}
void PrintList(hashtbl *H)
{

    //printf("=============\n");
    Position B, F;
    int i = 0;
    for (B = H->TheLists[i]; B != NULL; B = H->TheLists[++i])
    {
        for (F = B->next; F != NULL; F = F->next)
        {
            if (B->occupied == true && F->occupied == true && F->word[0] != '\0')
                printf("%s\n", F->word);
        }
        //printf("\n");
    }
    //printf("=============\n");
}

void checker(char *string, int length, hashtbl *H)
{
    int i, j, k, condition = 0, temp, count;
    for (k = 0; k < length + 1; k++)
    {
        count = 0;
        for (i = 0; i < (length / (k + 1)); i++)
        {
            //count++;
            for (j = 0; j <= k && (((i * (k + 1)) + j) < length); j++)
            {
                if (length % (k + 1) == 0)
                {
                    count = ((i * (k + 1))) + j;
                    if (string[((i * (k + 1))) + j] == string[j])
                    {
                        condition = 1;
                    }
                    else
                    {
                        condition = 0;
                        break;
                    }
                }
                else
                    condition = 0;
            }
            if (condition == 0)
                break;
        }
        if (condition == 1)
        {

            char key[k + 2];

            key[k + 1] = '\0';

            for (temp = 0; temp < k + 1; temp++)
            {
                key[temp] = string[temp];
            }
            //printf("k = %d\n", k);
            Insert(key, H);
        }
    }
}

void checker2(char *string, int length, hashtbl *H)
{
    int i, j, k, condition = 0, temp, count;
    for (k = 0; k < length + 1; k++)
    {
        count = 0;
        for (i = 0; i < (length / (k + 1)); i++)
        {
            //count++;
            for (j = 0; j <= k && (((i * (k + 1)) + j) < length); j++)
            {
                if (length % (k + 1) == 0)
                {
                    count = ((i * (k + 1))) + j;
                    if (string[((i * (k + 1))) + j] == string[j])
                    {
                        condition = 1;
                    }
                    else
                    {
                        condition = 0;
                        break;
                    }
                }
                else
                    condition = 0;
            }
            if (condition == 0)
                break;
        }
        if (condition == 1)
        {

            char key[k + 2];

            key[k + 1] = '\0';

            for (temp = 0; temp < k + 1; temp++)
            {
                key[temp] = string[temp];
            }
            //printf("k = %d\n", k);
            Insert2(key, H);
        }
    }
}
void Insert2(char *key, hashtbl *H)
{
    Position Pos, NewCell;
    list *L;
    int aux;

    Pos = Find_separatechaining(key, H);
    if (Pos != NULL)
    {
        Pos->common = true;
    }
}
void PrintListCommon(hashtbl *H)
{

    //printf("=============\n");
    Position B, F;
    int i = 0;
    int count = 0;
    for (B = H->TheLists[i]; B != NULL; B = H->TheLists[++i])
    {
        for (F = B->next; F != NULL; F = F->next)
        {
            if (B->occupied == true && F->common == true && F->word[0] != '\0')
                count++;
        }
        //printf("\n");
    }
    printf("%d\n", count);
    //printf("=============\n");
}
