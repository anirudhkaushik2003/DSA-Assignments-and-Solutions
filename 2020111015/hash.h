#ifndef __HASH_T__
#define __HASH_T__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

float analyser(int numofprobes, int cond);

typedef unsigned int Index;
typedef struct HashTable_SC hashtbl;
typedef struct ListNode list;
typedef list *Position;

typedef struct HashTable_LP hashtbl_LP;

struct ListNode
{
    int Element;
    //int a[1000000];
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

typedef unsigned int Index;
typedef struct HashTable_dictionary hashtbl_dictionary;
typedef struct ListNode_1 list_1;
typedef list_1 *Position_1;

struct ListNode_1
{
    char word[33];
    list_1 *next;
    bool occupied;
};

struct HashTable_dictionary
{
    int TableSize;
    list_1 **TheLists;
};

typedef struct ListNode_2 list_2;
typedef struct HashTable_string hashtbl_string;
typedef list_2 *Position_2;

struct ListNode_2
{

    char *word;
    //word = malloc(sizeof(char) * 100001);

    //assert(word != NULL);

    list_2 *next;
    bool occupied;
    bool common;
};

struct HashTable_string
{
    int TableSize;
    list_2 **TheLists;
};

int Find_string(char *key, const hashtbl_string *H);
hashtbl_string *InitializeTable_string(int N);
void Insert_string(char *key, hashtbl_string *H);
void PrintList_string(hashtbl_string *H);
Index Hash_string(const char *Key, int TableSize);
void checker_string(char *string, int length, hashtbl_string *H);
void checker2_string(char *string, int length, hashtbl_string *H);
void Insert2_string(char *key, hashtbl_string *H);
void PrintListCommon_string(hashtbl_string *H);
list_2 *Find_separatechaining_string(char *key, const hashtbl_string *H);

int Find_dictionary(char *key, const hashtbl_dictionary *H);
hashtbl_dictionary *InitializeTable_dictionary(int N);
list_1 *Find_separatechaining_dictionary(char *key, const hashtbl_dictionary *H);
void Insert_dictionary(char *key, hashtbl_dictionary *H);
void PrintList_dictionary(hashtbl_dictionary *H);
Index Hash_dictionary(const char *Key, int TableSize);

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