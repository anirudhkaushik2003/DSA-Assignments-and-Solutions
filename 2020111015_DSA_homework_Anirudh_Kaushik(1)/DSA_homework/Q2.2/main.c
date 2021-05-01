#include "Polynomial.h"

char name;
int expo;
double coeff;

char name1;
char name2;
int expo1;
double coeff1;

Poly *checker;
head *Poly_C;

int main()
{
    int ch = 1;
    char function[20];

    //scanf("%c %d %lf", &name, &expo, &coeff);
    //getchar();
    //InitPoly(name, expo, coeff);
    //PrintPoly(name);
    printf("Type a function to begin:\n");
    printf("no polynomials have been initialized yet so type InitPoly or AddTerm to initialize a polynomials\n");
    while (ch == 1)
    {
        scanf("%s", function);
        if (strcmp(function, "AddTerm") == 0)
        {
            getchar();
            scanf("%c %d %lf", &name, &expo, &coeff);
            AddTerm(name, expo, coeff);
        }
        if (strcmp(function, "InitPoly") == 0)
        {
            getchar();
            scanf("%c %d %lf", &name, &expo, &coeff);
            InitPoly(name, expo, coeff);
        }
        if (strcmp(function, "AddPolynomials") == 0)
        {
            getchar();
            scanf("%c %c %c", &name, &name1, &name2);
            //InitPoly(C,0,0);
            AddPoly(name, name1, name2);
        }
        if (strcmp(function, "SubstractPolynomials") == 0)
        {
            getchar();
            scanf("%c %c %c", &name, &name1, &name2);
            //InitPoly(C,0,0);
            SubPoly(name, name1, name2);
        }
        if (strcmp(function, "PrintPoly") == 0)
        {
            getchar();
            scanf("%c", &name);
            PrintPoly(name);
        }
        if (strcmp(function, "GetMiddle") == 0)
        {
            getchar();
            scanf("%c", &name);
            checker = GetMiddle(name);
            printf("%.2lfx^%d\n", checker->coeff, checker->expo);
        }
        if (strcmp(function, "DeleteAllTerms") == 0)
        {
            getchar();
            scanf("%c", &name);
            DeleteAllTerms(name);
        }
        if (strcmp(function, "DeleteTermByExponent") == 0)
        {
            getchar();
            scanf("%c %d", &name, &expo);
            DeleteTermByExponent(name, expo);
        }
        if (strcmp(function, "DeletePoly") == 0)
        {
            getchar();
            scanf("%c", &name);
            DeletePoly(name);
        }
        //getchar();
        printf("continue?(1/0):");
        scanf("%d", &ch);
    }

    //PrintPoly('A');
    //PrintPoly('B');
    //PrintPoly('C');
}
