#ifndef __DICTIONARY__
#define __DICTIONARY__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int Index;
typedef struct HashTable hashtbl;
typedef struct ListNode list;
typedef list *Position;

struct ListNode
{
    char word[32 + 1];
    list *next;
    bool occupied;
};

struct HashTable
{
    int TableSize;
    list **TheLists;
};

int Find(char *key, const hashtbl *H);
hashtbl *InitializeTable(int N);
void Insert(char *key, hashtbl *H);
void PrintList(hashtbl *H);
Index Hash(const char *Key, int TableSize);

#endif
//#include "hash.h"

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

    Pos = Find_separatechaining(key, H);
    if (Pos == NULL)
    {
        NewCell = malloc(sizeof(list));
        assert(NewCell != NULL);

        L = H->TheLists[Hash(key, H->TableSize)];
        NewCell->next = L->next;
        strcpy(NewCell->word, key);
        L->next = NewCell;
    }
}
void PrintList(hashtbl *H)
{

    printf("=============\n");
    Position B, F;
    int i = 0;
    for (B = H->TheLists[i]; B != NULL; B = H->TheLists[++i])
    {
        for (F = B->next; F != NULL; F = F->next)
        {
            printf("%s-->", F->word);
        }
        printf("\n");
    }
    printf("=============\n");
}

int Find(char *key, const hashtbl *H)
{

    //int tempint = H->TableSize;

    int i, aux;
    list *P;
    P = Find_separatechaining(key, H);
    // aux = ((Hash(key, tempint)) % tempint);

    if (P != NULL && strcmp(P->word, key) == 0)
    {

        return 1;
    }

    else
        return 0;
}
//#include "hash.h"

int main()
{
    int N, count = 0;
    char key[40] = {'\0'};
    int i = 0;
    scanf("%d", &N);

    hashtbl *H;
    int L;
    H = InitializeTable(N);
    while (N != 0)
    {
        getchar();
        scanf("%s", key);
        /* for (i = 0; i < 40 && key[i] != '\0'; i++)
        {
            if (key[i] != '\0' && key[i] <= 'Z' && key[i] >= 'A')
            {
                key[i] = key[i] - 'A' + 'a';
            }
        }*/
        Insert(key, H);
        N--;
    }
    //PrintList(H);
    getchar();
    scanf("%d", &N);
    char array1[N][40];
    int j = 0;
    while (N != 0)
    {

        getchar();
        scanf("%s", key);
        /*for (i = 0; i < 40 && key[i] != '\0'; i++)
        {
            if (key[i] != '\0' && key[i] <= 'Z' && key[i] >= 'A')
            {
                key[i] = key[i] - 'A' + 'a';
            }
        }*/

        L = Find(key, H);

        if (L == 0)
        {
            strcpy(array1[j], key);
            // printf("table size = %d\n", H->TableSize);
            count++;
            j++;
            //printf("table size = %d\n", H->TableSize);
        }
        N--;
    }
    //PrintList(H);
    printf("%d\n", count);

    for (i = 0; i < count; i++)
    {
        printf("%s\n", (array1[i]));
    }
}