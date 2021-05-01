#include "deque.h"

deque *first = NULL;
deque *last = NULL;
deque *linker = NULL;

void push(double data, double data1)
{
    deque *new_node;
    new_node = (deque *)malloc(sizeof(deque));
    assert(new_node != NULL);

    new_node->data = data;
    new_node->data1 = data1;

    new_node->prev = NULL;

    new_node->next = first;
    if (first != NULL)
        first->prev = new_node;
    first = new_node;

    if (new_node->next == NULL)
    {
        last = new_node;
    }
    if (last == NULL)
    {
        last = new_node;
    }

    PrintPoly();
}

deque *pop()
{
    if (IsEmpty() == 1)
    {
        printf("The Deque is Empty!\n");
    }
    else
    {
        deque *cur;
        cur = first;
        first = first->next;
        cur->next = NULL;
        PrintPoly();
        return cur;
        free(cur);
    }
}

void PrintPoly()
{
    deque *cur;
    printf("==+++STACK+++==\n");
    for (cur = first; cur != NULL; cur = cur->next)
    {

        printf("===============\n");
        printf("|(%.2lf , %.2lf)|\n", cur->data, cur->data1);
    }
    printf("===============\n");
    free(cur);
}

int IsEmpty()
{
    if (first == NULL)
    {
        return 1;
    }
    else
        return 0;
}

void inject(double data, double data1)
{
    deque *new_node;
    new_node = (deque *)malloc(sizeof(deque));
    assert(new_node != NULL);
    new_node->data1 = data1;
    new_node->data = data;

    //deque *cur;
    //cur = last;
    if (last == NULL)
    {
        last = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
    }

    else
    {
        new_node->next = NULL;
        new_node->prev = last;
        last->next = new_node;
        last = new_node;
    }

    if (first == NULL)
    {
        first = new_node;
        first->prev = NULL;
        first->next = NULL;
    }
    PrintPoly();
}

deque *eject()
{
    deque *cur;
    cur = last;
    if (last == NULL)
    {
        first = NULL;
        printf("The Deque Is Empty\n");
    }
    else
    {
        //cur = last;
        last = last->prev;
        if (last != NULL)
            last->next = NULL;
        else
            first = NULL;
        free(cur);
        PrintPoly();
    }
}