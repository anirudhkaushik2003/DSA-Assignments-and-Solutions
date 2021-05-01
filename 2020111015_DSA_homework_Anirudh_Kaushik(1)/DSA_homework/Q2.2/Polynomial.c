/*NOTE: This is what our data structure looks like

[]-> []-> []->[]   ====> sequence of header nodes that contain the poly name and pointer to body
|    |    |    |
v    v    v    v
[]   []   []   [] =====> sequence of body nodes that contain the body of the polynomial
|    |    |    |
v    v    v    v
[]   []   []   []

1)For this sir's code was used to initialize the body of the polynomial(the vertical rows in the grid) and AddTerm function is also from sir's code.
2)the functions had to be modified to be compatible with the driver code(main.c).
3)i made a slight modification to the InitPoly function to be able to hold the name of the polynomial and the number of terms by initializing another linked lists of header nodes
4)Changes were made to the names of the variables as it became difficult to keep track of them.
5)Also i replaced the (P->next->expo > expo) in sir's code to cur->expo < new_term->expo to print the list in descending order
6)For the DeleteTerm function i replaced the while loop with a for loop and kept all the if conditions inside to make it more readable and easy to modify for me 
also i had to use gdb to debug so i had to change the way sir had used the loops, like the &&  and || operators were removed so i could verify each condition separately and debug
7)in some places the free() function had to be removed as it gives a double free error with some corner cases.
8)2D linked list was used over an array of pointers to struct variable as it saves space.
9)In my program if you Add polynomials A B and C then the program will initialize the polynomial for you and also name it for you, like you can name it anything like u b w x y z etc.
10)instead of passing a pointer to the polynomial we're passing it's name as the polynomial names are stored in a linked list instead of an indexed array, which allows you to name your polynomial
   whatever you want(to allow this feature we must pass the polynomial name as pointer to polynomial means the polynomial would already have to have a name). this makes the code easier to use.
*/
//

#include "Polynomial.h"

head *first_head = NULL;
body *first_body = NULL;

Poly *InitPoly(Polynomial PolyName, int exponent, double coefficient)
{
    head *head_i;
    head_i = (head *)malloc(sizeof(head));
    assert(head_i != NULL);

    body *body_i;
    body_i = (body *)malloc(sizeof(body));
    assert(body_i != NULL);

    head_i->name = PolyName; //names the polynomial
    head_i->next = first_head;
    first_head = head_i;

    body_i->coeff = coefficient;
    body_i->expo = exponent;
    body_i->next = NULL;
    first_body = body_i;

    head_i->Bodnext = body_i; //links the header node with the body node
    head_i->Num_terms = 1;
}

void PrintPoly(Polynomial PolyName)
{
    head *cur_head;
    body *cur_body = NULL;
    char name = 'b';
    for (cur_head = first_head; cur_head != NULL; cur_head = cur_head->next)
    {
        if (cur_head->name == PolyName)
        {
            num_term();
            if (cur_head->Num_terms != 0)
            {
                name = 'a';
                printf("Poly %c=> ", cur_head->name);
                for (cur_body = cur_head->Bodnext; cur_body != NULL; cur_body = cur_body->next)
                {
                    /* if (cur_body->expo == 0 && cur_body->expo != 0)
                {
                    printf("%.2lf ", cur_body->coeff);
                    return;
                }*/
                    /*else
                {
                    if (cur_body->coeff == 0)
                    {
                        cur_body = cur_body->next;
                        if (cur_body == NULL)
                        {
                            return;
                        }
                    }
                }*/
                    //else
                    if (cur_body->coeff == 0)
                    {
                        continue;
                    }
                    else
                    {
                        printf("%.2lfx^%d ", cur_body->coeff, cur_body->expo);

                        if (cur_body->next != NULL && (cur_body->next)->coeff != 0)
                            printf("+ ");
                    }
                }
                printf("\n");
            }
            else
            {
                name = 'a';
                printf("0\n");
            }
        }
        //printf("Number of terms: %d\n", cur_head->Num_terms); //debugging tool
    }
    if (name == 'b')
    {
        printf("Polynomial doesn't exist\n");
    }
    free(cur_head);
}

void AddTerm(Polynomial PolyName, int exponent, double coefficient)
{
    head *cur_head;
    body *cur_body;
    body *prev_body;
    char name = 'b';
    body *new_term;
    new_term = malloc(sizeof(body));
    assert(new_term != NULL);
    new_term->coeff = coefficient;
    new_term->expo = exponent;

    for (cur_head = first_head; cur_head != NULL; cur_head = cur_head->next)
    {
        if (cur_head->name == PolyName)
        {
            name = 'a';
            cur_head->Num_terms++;
            for (cur_body = cur_head->Bodnext, prev_body = NULL; cur_body != NULL; prev_body = cur_body, cur_body = cur_body->next)
            {
                if (new_term->expo > cur_body->expo)
                {

                    if (prev_body != NULL)
                        prev_body->next = new_term;
                    if (prev_body == NULL)
                        cur_head->Bodnext = new_term;
                    new_term->next = cur_body;
                    //cur_body->next = new_term;

                    return;
                }
                else
                {
                    if (new_term->expo == cur_body->expo)
                    {
                        cur_body->coeff += new_term->coeff;
                        cur_head->Num_terms--;
                    }
                    else
                    {
                        if (cur_body->next == NULL)
                        {
                            cur_body->next = new_term;
                            new_term->next = NULL;
                            return;
                        }
                    }
                }
            }
            PrintPoly(PolyName);
        }
        else
            continue;
    }
    if (name == 'b')
    {
        InitPoly(PolyName, exponent, coefficient);
    }
    num_term();
    free(new_term);
    if (name == 'a')
        free(cur_body);
    free(cur_head);
}

Poly *GetMiddle(Polynomial PolyName)
{
    int x = 1;
    int number;

    head *cur_head;
    body *cur_body;
    //body *prev_body;
    num_term();
    for (cur_head = first_head; cur_head != NULL; cur_head = cur_head->next)
    {
        if (cur_head->name == PolyName)
        {
            //printf("number of terms in A = %d\n", cur_head->Num_terms);
            number = ((cur_head->Num_terms) % 2);
            if (number == 0)
            {
                //printf("number = %d\n", number);
                number = (((cur_head->Num_terms) / 2));
                //printf("number1 = %d\n", number);
                x = 0;
            }
            else
            {
                if (number == 1)
                {
                    //printf("number = %d\n", number);
                    number = (1 + ((cur_head->Num_terms) / 2));
                    //printf("number1 = %d\n", number);
                }
            }
            for (cur_body = cur_head->Bodnext; cur_body != NULL; cur_body = cur_body->next)
            {
                if (x == number)
                {
                    return cur_body;
                }
                x++;
            }
        }
    }
    free(cur_body);
    free(cur_head);
}

head *AddPoly(Polynomial name, Polynomial name1, Polynomial name2)
{
    head *cur_head;
    head *cur_head1;
    body *cur_body;
    body *cur_body1;

    head *Poly_C;
    Poly_C = malloc(sizeof(head));
    assert(Poly_C != NULL);

    body *Poly_C_body;
    Poly_C_body = malloc(sizeof(head));
    assert(Poly_C_body != NULL);

    Poly_C->name = name2;
    Poly_C->next = first_head;
    first_head = Poly_C;

    Poly_C_body->next = NULL;
    first_body = Poly_C_body;
    Poly_C->Bodnext = first_body;
    Poly_C->Num_terms = 1;

    double coeff;
    int expo;

    for (cur_head = first_head; cur_head != NULL; cur_head = cur_head->next)
    {

        if (cur_head->name == name)
        {
            for (cur_head1 = first_head; cur_head1 != NULL; cur_head1 = cur_head1->next)
            {
                if (cur_head1->name == name1)
                {
                    break;
                }
            }
            break;
        }
    }
    for (cur_body = cur_head->Bodnext, cur_body1 = cur_head1->Bodnext;;)
    {
        if (cur_body1 == NULL && cur_body == NULL)
        {
            return Poly_C;
        }
        else
        {
            if (cur_body->expo == cur_body1->expo)
            {
                coeff = cur_body1->coeff + cur_body->coeff;
                expo = cur_body1->expo;
                AddTerm(name2, expo, coeff);
                //if(cur_body1->next != NULL && cur_body->next != NULL )

                cur_body = cur_body->next;
                cur_body1 = cur_body1->next;
                if (cur_body == NULL)
                {
                    for (; cur_body1 != NULL; cur_body1 = cur_body1->next)
                    {
                        AddTerm(name2, cur_body1->expo, cur_body1->coeff);
                    }
                }
                if (cur_body1 == NULL)
                {
                    for (; cur_body != NULL; cur_body = cur_body->next)
                    {
                        AddTerm(name2, cur_body->expo, cur_body->coeff);
                    }
                }
            }
            else
            {
                if (cur_body->expo > cur_body1->expo)
                {
                    AddTerm(name2, cur_body->expo, cur_body->coeff);
                    //if (cur_body1->next != NULL)
                    cur_body = cur_body->next;
                    if (cur_body == NULL)
                    {
                        for (; cur_body1 != NULL; cur_body1 = cur_body1->next)
                        {
                            AddTerm(name2, cur_body1->expo, cur_body1->coeff);
                        }
                    }
                }
                else
                {
                    if (cur_body1->expo > cur_body->expo)
                    {
                        AddTerm(name2, cur_body1->expo, cur_body1->coeff);
                        //if (cur_body1->next != NULL)
                        cur_body1 = cur_body1->next;

                        if (cur_body1 == NULL)
                        {
                            for (; cur_body != NULL; cur_body = cur_body->next)
                            {
                                AddTerm(name2, cur_body->expo, cur_body->coeff);
                            }
                        }
                    }
                }
            }
        }
    }
    num_term();
}

void SubPoly(Polynomial name, Polynomial name1, Polynomial name2)
{
    head *cur_head;
    head *cur_head1;
    body *cur_body;
    body *cur_body1;

    head *Poly_C;
    Poly_C = malloc(sizeof(head));
    assert(Poly_C != NULL);

    body *Poly_C_body;
    Poly_C_body = malloc(sizeof(head));
    assert(Poly_C_body != NULL);

    Poly_C->name = name2;
    Poly_C->next = first_head;
    first_head = Poly_C;

    Poly_C_body->next = NULL;
    first_body = Poly_C_body;
    Poly_C->Bodnext = first_body;

    double coeff;
    int expo;

    for (cur_head = first_head; cur_head != NULL; cur_head = cur_head->next)
    {

        if (cur_head->name == name)
        {
            for (cur_head1 = first_head; cur_head1 != NULL; cur_head1 = cur_head1->next)
            {
                if (cur_head1->name == name1)
                {
                    break;
                }
            }
            break;
        }
    }
    for (cur_body = cur_head->Bodnext, cur_body1 = cur_head1->Bodnext;;)
    {
        if (cur_body1 == NULL && cur_body == NULL)
        {
            return;
        }
        else
        {
            if (cur_body->expo == cur_body1->expo)
            {
                coeff = cur_body->coeff - cur_body1->coeff;
                expo = cur_body1->expo;
                AddTerm(name2, expo, coeff);
                //if(cur_body1->next != NULL && cur_body->next != NULL )

                cur_body = cur_body->next;
                cur_body1 = cur_body1->next;
                if (cur_body == NULL)
                {
                    for (; cur_body1 != NULL; cur_body1 = cur_body1->next)
                    {
                        AddTerm(name2, cur_body1->expo, cur_body1->coeff);
                    }
                }
                if (cur_body1 == NULL)
                {
                    for (; cur_body != NULL; cur_body = cur_body->next)
                    {
                        AddTerm(name2, cur_body->expo, cur_body->coeff);
                    }
                }
            }
            else
            {
                if (cur_body->expo > cur_body1->expo)
                {
                    AddTerm(name2, cur_body->expo, cur_body->coeff);
                    //if (cur_body1->next != NULL)
                    cur_body = cur_body->next;
                    if (cur_body == NULL)
                    {
                        for (; cur_body1 != NULL; cur_body1 = cur_body1->next)
                        {
                            AddTerm(name2, (cur_body1->expo), (-cur_body1->coeff));
                        }
                    }
                }
                else
                {
                    if (cur_body1->expo > cur_body->expo)
                    {
                        AddTerm(name2, cur_body1->expo, (-cur_body1->coeff));
                        //if (cur_body1->next != NULL)
                        cur_body1 = cur_body1->next;

                        if (cur_body1 == NULL)
                        {
                            for (; cur_body != NULL; cur_body = cur_body->next)
                            {
                                AddTerm(name2, cur_body->expo, cur_body->coeff);
                            }
                        }
                    }
                }
            }
        }
    }
    num_term();
}

void DeleteAllTerms(Polynomial PolyName)
{
    head *cur_head;
    body *cur_body;

    for (cur_head = first_head; cur_head != NULL; cur_head = cur_head->next)
    {
        if (cur_head->name == PolyName)
        {
            for (cur_body = cur_head->Bodnext; cur_body != NULL; cur_body = cur_body->next)
            {
                cur_body->coeff = 0;
            }
        }
    }
    num_term();
}

void DeleteTermByExponent(Polynomial PolyName, int expo)
{
    head *cur_head;
    body *cur_body;
    body *prev_body;

    for (cur_head = first_head; cur_head != NULL; cur_head = cur_head->next)
    {
        if (cur_head->name == PolyName)
        {
            for (cur_body = cur_head->Bodnext, prev_body = NULL; cur_body != NULL; prev_body = cur_body, cur_body = cur_body->next)
            {
                if (cur_body->expo == expo)
                {
                    if (prev_body == NULL)
                    {
                        cur_head->Bodnext = cur_body->next;
                        free(cur_body);
                    }
                    else
                    {
                        prev_body->next = cur_body->next;
                        free(cur_body);
                    }
                }
            }
        }
    }
}

void DeletePoly(Polynomial PolyName)
{
    head *cur_head;
    head *prev_head;

    for (cur_head = first_head, prev_head = NULL; cur_head != NULL; prev_head = cur_head, cur_head = cur_head->next)
    {
        if (cur_head->name == PolyName)
        {
            if (prev_head == NULL)
            {
                first_head = cur_head->next;
                free(cur_head);
            }
            else
            {
                prev_head->next = cur_head->next;
                free(cur_head);
            }
        }
    }
}
/*void DeleteTerm(Polynomial PolyName)
{}*/

void num_term()
{
    head *cur_head;
    body *cur_body;

    for (cur_head = first_head; cur_head != NULL; cur_head = cur_head->next)
    {
        cur_head->Num_terms = 0;
        for (cur_body = cur_head->Bodnext; cur_body != NULL; cur_body = cur_body->next)
        {
            if (cur_body->coeff == 0)
            {
                continue;
            }
            else
            {
                cur_head->Num_terms += 1;
            }
        }
    }
}