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
    char word[1000001];
    list *next;
    bool occupied;
    bool common;
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
void checker(char *string, int length, hashtbl *H);
void checker2(char *string, int length, hashtbl *H);
void Insert2(char *key, hashtbl *H);
void PrintListCommon(hashtbl *H);
#endif
