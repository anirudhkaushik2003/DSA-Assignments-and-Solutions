#ifndef _COMPLEX_H
#define _COMPLEX_H


#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



typedef struct complex complex;
//typedef struct complex* complex*;

struct complex
{
    int a[1000000]; //n dimensional array to hold complex numbers;
};
complex *ADD(complex a, complex b,int dimension);

complex *SUB(complex a, complex b,int dimension);

float MOD(complex a,int dimension);

int DOT(complex a, complex b,int dimension);



#endif