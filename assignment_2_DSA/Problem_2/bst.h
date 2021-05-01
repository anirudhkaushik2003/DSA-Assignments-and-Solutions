#ifndef __TREE_H__
#define __TREE_H__


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
    int depth;
};

tree *Insert(int x, tree *T);
void Print(tree *T,int depth);
//void copy(tree *T, int array[], int *index);/
//void bstSort(tree *T, int depth);
//int _finddepth(tree *T, tree *P,int depth);
int finddepth(tree *T, tree *P);
int finddepth1(tree *T, tree *P);
tree *binarytree();

#endif
