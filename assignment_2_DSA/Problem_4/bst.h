#ifndef __TREE_H_
#define __TREE_H_

#include <limits.h>
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

int minValue(tree *T);
int maxValue(tree *T);
tree *Insert(int x, tree *T);
void Print(tree *T,int depth);
tree *binarytree();
int isbst(tree *T);
int isbst1(tree *T);
#endif
