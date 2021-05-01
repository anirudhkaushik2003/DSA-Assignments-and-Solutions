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
    int Element;
    bool occupied;
    list *next;
};

struct HashTable_SC
{
    int TableSize;
    list **TheLists;
};

struct HashTable_LP
{
    int TableSize;
    list *array;
};

list *Find_separatechaining(int key, hashtbl *H);
hashtbl *InitializeTable_separatechaining(int N);
void Insert_separatechaining(int key, hashtbl *H);
void PrintList_separatechaining(hashtbl *H);
Index Hash(const int Key, int TableSize);
int Find_separatechainingPos(int key, hashtbl *H);

void PrintList_LP(hashtbl_LP *H);
void Insert_LP(int key, hashtbl_LP *H);
hashtbl_LP *InitializeTable_LinearProbing(int N);
int FindPos_LP(int key, hashtbl_LP *H);

void PrintList_QP(hashtbl_LP *H);
void Insert_QP(int key, hashtbl_LP *H);
hashtbl_LP *InitializeTable_QuadProbing(int N);
int FindPos_QP(int key, hashtbl_LP *H);

#endif