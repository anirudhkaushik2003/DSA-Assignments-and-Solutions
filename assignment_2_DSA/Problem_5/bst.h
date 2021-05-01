#ifndef __TREE_H_
#define __TREE_H_

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct TreeNode tree;
typedef tree Node;

struct TreeNode
{
    int data;
    tree *left;
    tree *right;
};

tree *randombst(int N);
void avgdepth();
void _avgdepth(float m);
int height(tree *T);

tree *Insert(int x, tree *T);
void Print(tree *T, int depth);

#endif