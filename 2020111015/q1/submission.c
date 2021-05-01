#ifndef __HASH_T__
#define __HASH_T__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int Index;
typedef struct HashTable_SC hashtbl;
typedef struct ListNode list;
typedef list *Position;

typedef struct HashTable_LP hashtbl_LP;

struct ListNode
{
    unsigned int Element;
    bool occupied;
    list *next;
};

struct HashTable_SC
{
    unsigned int TableSize;
    list **TheLists;
};

struct HashTable_LP
{
    unsigned int TableSize;
    list *array;
};

list *Find_separatechaining(unsigned int key, hashtbl *H);
hashtbl *InitializeTable_separatechaining(int N);
void Insert_separatechaining(unsigned int key, hashtbl *H);
void PrintList_separatechaining(hashtbl *H);
Index Hash(const unsigned int Key, int TableSize);
int Find_separatechainingPos(unsigned int key, hashtbl *H);

void PrintList_LP(hashtbl_LP *H);
void Insert_LP(unsigned int key, hashtbl_LP *H);
hashtbl_LP *InitializeTable_LinearProbing(int N);
int FindPos_LP(unsigned int key, hashtbl_LP *H);

void PrintList_QP(hashtbl_LP *H);
void Insert_QP(unsigned int key, hashtbl_LP *H);
hashtbl_LP *InitializeTable_QuadProbing(int N);
int FindPos_QP(unsigned int key, hashtbl_LP *H);

#endif

Index Hash(const unsigned int Key, int TableSize)
{

    return Key % TableSize;
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

list *Find_separatechaining(unsigned int key, hashtbl *H)
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

int Find_separatechainingPos(unsigned int key, hashtbl *H)
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

    if (P == NULL)
        return -1;
    else
        return i;
}

void Insert_separatechaining(unsigned int key, hashtbl *H)
{
    Position Pos, NewCell;
    list *L, *P;

    //Pos = Find_separatechaining(key, H);

    NewCell = malloc(sizeof(list));
    assert(NewCell != NULL);

    L = H->TheLists[Hash(key, H->TableSize)];
    P = L->next;
    NewCell->Element = key;
    while (P != NULL && P->next != NULL)
    {
        P = P->next;
    }
    if (P != NULL)
        NewCell->next = P->next;
    else
    {
        NewCell->next = P;
    }

    if (P != NULL)
        P->next = NewCell;
    else
    {
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

void Insert_LP(unsigned int key, hashtbl_LP *H)
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

void Insert_QP(unsigned int key, hashtbl_LP *H)
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

int FindPos_QP(unsigned int key, hashtbl_LP *H)
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

int FindPos_LP(unsigned int key, hashtbl_LP *H)
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

int main()
{
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
        }
        //PrintList_separatechaining(H);
    }
    if (strcmp(function, "quadratic-probing") == 0)
    {

        scanf("%d", &N);
        scanf("%d", &Q);

        /*if ((float)Q / (float)N >= 0.5)
        {
            //float var = (float)Q / (float)N;
            //printf("value = %lf\n", var);
            N = 2 * N;
            
        }*/

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
        //PrintList_QP(H);
    }
}