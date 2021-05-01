#ifndef __TREE_H_
#define __TREE_H_


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct TreeNode tree;
typedef tree Node;

struct TreeNode
{
    int data;
    tree *left;
    tree *right;
};


tree *Insert(int x, tree *T);
void Print(tree *T,int depth);
void copy(tree *T, int array[], int *index);
void inRange(tree *T,int k1,int k2);
#endif
