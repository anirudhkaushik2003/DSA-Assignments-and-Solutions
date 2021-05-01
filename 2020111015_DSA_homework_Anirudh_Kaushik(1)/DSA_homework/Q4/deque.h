#ifndef __DEQUE_H__
#define __DEQUE_H__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct Deque deque;

struct Deque
{
    double data;
    double data1;

    deque *next;
    deque *prev;
};

void push(double data, double data1);
deque *pop();
void inject(double data, double data1);
deque *eject();
void PrintPoly();
int IsEmpty();

#endif