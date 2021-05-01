//Header file was made on my own so that i can name the functions as per my convinience


#ifndef __LINKED_LISTS__
#define __LINKED_LISTS__

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node node;

struct Node
{
    int element;
    node *next;
};



node *CreateNode(int x);
node *InsertNode(int x);

void PrintList();
void DeleteAll(int x);
int FindLast(int x);
void DeleteNode(node *P);
node *returnFirstNode();

#endif