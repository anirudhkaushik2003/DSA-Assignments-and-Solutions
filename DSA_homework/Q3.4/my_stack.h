#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//#include <time.h>

typedef struct my_Stack stack;

struct my_Stack
{
    double data; // data to be enetered in comma separated form
    double data1;
    stack *next;
};

void push(double data, double data1); //pushes element to the top of the stack
void pop();                         //pops the top element
void PrintStack();
int IsEmpty();

#endif