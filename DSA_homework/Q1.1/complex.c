#include "complex.h"

complex *ADD(complex a, complex b, int dimension)
{
    int i;
    complex *result; // this is the complex number to be returned;
    // we have declared another complex no. to prevent
    //changing the value of the complex a and complex b
    result = malloc(sizeof(complex));
    for (i = 0; i < dimension; i++)
    {
        result->a[i] = a.a[i] + b.a[i]; //adds the 2 complex nos. by adding the arrays element-wise
    }
    return result;
}
complex *SUB(complex a, complex b, int dimension)
{
    int i;
    complex *result; // this is the complex number to be returned;
    // we have declared another complex no. to prevent
    //changing the value of the complex a and complex b
    result = malloc(sizeof(complex));
    for (i = 0; i < dimension; i++)
    {
        result->a[i] = a.a[i] - b.a[i]; //adds the 2 complex nos. by adding the arrays element-wise
    }
    return result;
}
float MOD(complex a, int dimension)
{
    float result = 0;
    int i;
    for (i = 0; i < dimension; i++)
    {
        result += pow(a.a[i], 2);
    }
    result = sqrt(result);
    return result;
}
int DOT(complex a, complex b, int dimension)
{
    int result = 0;
    int i;
    for (i = 0; i < dimension; i++)
    {
        result += a.a[i] * b.a[i]; //adds the 2 complex nos. by adding the arrays element-wise
    }
    return result;
}