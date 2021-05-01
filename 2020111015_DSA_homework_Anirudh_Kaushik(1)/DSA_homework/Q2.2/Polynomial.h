#ifndef __POLY__
#define __POLY__

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//#include <math.h>

typedef struct Head head;
typedef struct PolyTerm body;
typedef body Poly;
typedef char Polynomial;

struct Head //contains names of the polynomial, acts as a header node to a polynomial
{
    char name;
    head *next;    //links the header node to the next header node
    body *Bodnext; //links the header node with the body node
    int Num_terms;
};

struct PolyTerm //forms the body of the polynomial
{
    int expo;
    double coeff;
    body *next;
};

Poly *InitPoly(Polynomial PolyName, int exponent, double coefficient);
void PrintPoly(Polynomial PolyName);
void AddTerm(Polynomial PolyName, int exponent, double coefficient);
Poly *GetMiddle(Polynomial PolyName);
head *AddPoly(Polynomial A, Polynomial B, Polynomial C);
void SubPoly(Polynomial name, Polynomial name1, Polynomial name2);
void DeleteAllTerms(Polynomial PolyName);
void DeleteTermByExponent(Polynomial name, int expo);
void DeletePoly(Polynomial PolyName);
void num_term();
//void DeleteTerm(Polynomial PolyName);

#endif