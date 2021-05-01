#include "my_stack.h"

stack *first = NULL;
//first = NULL; //points to the first element in the stack, top element

void push(double data, double data1)
{
    stack *new_node;
    new_node = (stack *)malloc(sizeof(stack));
    assert(new_node != NULL);

    new_node->data = data;
    new_node->data1 = data1;

    new_node->next = first;
    first = new_node;
}

void PrintStack()
{
    stack *cur;
    printf("==+++STACK+++==\n");
    for (cur = first; cur != NULL; cur = cur->next)
    {

        printf("===============\n");
        printf("|(%.2lf , %.2lf)|\n", cur->data, cur->data1);
    }
    printf("===============\n");
    free(cur);
}

void pop()
{
    if (IsEmpty() == 1)
    {
        printf("Stack Is Empty\n");
    }
    else
    {
        stack *tobedeleted;
        tobedeleted = first;

        first = first->next;
        tobedeleted->next = NULL;

        free(tobedeleted);
    }
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
