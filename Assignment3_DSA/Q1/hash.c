#include "hash.h"

Index Hash(const int Key, int TableSize)
{
    unsigned int HashVal = 0;
    HashVal += Key % TableSize;
    return HashVal % TableSize;
}

hashtbl *InitializeTable_separatechaining(int N)
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
    }

    return H;
}

list *Find_separatechaining(int key, hashtbl *H)
{
    list *P, *L;
    int i = 0;
    L = H->TheLists[Hash(key, H->TableSize)];
    P = L->next;
    while (P != NULL && P->Element != key)
    {
        P = P->next;
        i++;
    }
    return P;
}

int Find_separatechainingPos(int key, hashtbl *H)
{
    list *P, *L;
    int i = 0;
    L = H->TheLists[Hash(key, H->TableSize)];
    P = L->next;
    while (P != NULL && P->Element != key)
    {
        P = P->next;
        i++;
    }
    if (P != NULL && P->Element == key)
        return i;
    else
        return -1;
}

void Insert_separatechaining(int key, hashtbl *H)
{
    Position Pos, NewCell;
    list *L;

    Pos = Find_separatechaining(key, H);
    if (Pos == NULL)
    {
        NewCell = malloc(sizeof(list));
        assert(NewCell != NULL);

        L = H->TheLists[Hash(key, H->TableSize)];
        NewCell->next = L->next;
        NewCell->Element = key;
        L->next = NewCell;
    }
}

void PrintList_separatechaining(hashtbl *H)
{
    Position B, F;
    int i = 0;
    for (B = H->TheLists[i]; B != NULL; B = H->TheLists[++i])
    {
        for (F = B->next; F != NULL; F = F->next)
        {
            printf("%d-->", F->Element);
        }
        printf("\n");
    }
}

hashtbl_LP *InitializeTable_LinearProbing(int N)
{
    //N is table size
    hashtbl_LP *H;
    H = malloc(sizeof(hashtbl_LP)); //pointer to dynamically allocated array
    assert(H != NULL);
    H->TableSize = N;

    H->array = malloc(sizeof(list) * H->TableSize);
    assert(H->array != NULL);
    int i;
    for (i = 0; i < H->TableSize; i++)
    {
        H->array[i].occupied = false;
    }
    return H;
}

void Insert_LP(int key, hashtbl_LP *H)
{
    int i, aux;
    for (i = 0; i < H->TableSize; i++)
    {
        aux = (Hash(key, H->TableSize) + i) % H->TableSize;
        if (H->array[aux].occupied == false)
        {
            H->array[aux].Element = key;
            H->array[aux].occupied = true;
            return;
        }
    }
}

void PrintList_LP(hashtbl_LP *H)
{
    int i;
    printf("=============\n");
    for (i = 0; i < H->TableSize; i++)
    {
        printf("%d\n", H->array[i].Element);
    }
    printf("=============\n");
}

hashtbl_LP *InitializeTable_QuadProbing(int N)
{
    //N is table size
    hashtbl_LP *H;
    H = malloc(sizeof(hashtbl_LP)); //pointer to dynamically allocated array
    assert(H != NULL);
    H->TableSize = N;

    H->array = malloc(sizeof(list) * H->TableSize);
    assert(H->array != NULL);
    int i;
    for (i = 0; i < H->TableSize; i++)
    {
        H->array[i].occupied = false;
    }
    return H;
}

void Insert_QP(int key, hashtbl_LP *H)
{
    int i, aux;
    for (i = 0; i < H->TableSize; i++)
    {
        aux = (Hash(key, H->TableSize) + (i * i)) % H->TableSize;
        if (H->array[aux].occupied == false)
        {
            H->array[aux].Element = key;
            H->array[aux].occupied = true;
            //printf("position = %d\n", (Hash(key, H->TableSize) + (i * i)) % H->TableSize);
            return;
        }
    }
}

void PrintList_QP(hashtbl_LP *H)
{
    int i;
    printf("=============\n");
    for (i = 0; i < H->TableSize; i++)
    {
        printf("%d\n", H->array[i].Element);
    }
    printf("=============\n");
}

int FindPos_QP(int key, hashtbl_LP *H)
{
    int i, aux;
    for (i = 0; i < H->TableSize; i++)
    {
        aux = (Hash(key, H->TableSize) + (i * i)) % H->TableSize;
        if (H->array[aux].Element == key)
        {

            return aux;
        }
    }
    return -1;
}

int FindPos_LP(int key, hashtbl_LP *H)
{
    int i, aux;
    for (i = 0; i < H->TableSize; i++)
    {
        aux = (Hash(key, H->TableSize) + i) % H->TableSize;
        if (H->array[aux].Element == key)
        {

            return aux;
        }
    }
    return -1;
}
