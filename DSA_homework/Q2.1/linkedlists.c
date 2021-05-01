/*
1)Used sir's code but in my code elements are added to the end of the list like a stack, if elements are to be added to the top then jest change the variable in InsertNode to
2)new_node->next = NULL; 
3)if(first != NULL)
{
  first->next = new_node;
}
else
  first = new_node;
This should add elements to the bottom instead of the top, but i think we're supposed to add at the bottom coz this is a linked lists.
4)sir's code had 2 functions MakeNode to initialize the node and void InsertAtFront_v2(List PP); i merged botht these functions to create an insert node function as it's easier and more understandable
5)i changed the variable names everywhere to make the code more readable like using new_node instead of P and first instead of PP coz it's difficult to use such names as they don't tell me anything
  about the variable
6) removed a couple of typedefs as i need to use the * to know i'm using a pointer.

*/

#include "linkedlists.h"

node *first = NULL;

node *InsertNode(int x)
{
    node *new_node;
    new_node = (node *)malloc(sizeof(node));

    if (new_node == NULL)
    {
        printf("MALLOC FAILED!\n");
        return 0;
    }

    new_node->element = x;
    new_node->next = first;
    first = new_node;
    //list = new_node;

    return new_node;
}

void DeleteAll(int x)
{
    //printf("DeleteAll accessed!\n");

    node *cur, *prev;

    for (cur = first, prev = NULL; cur != NULL; prev = cur, cur = cur->next)
    {

        if (cur->element == x)
        {
            //PrintList();
            if (cur == first)
            {
                first = cur->next;
            }
            else
            {
                prev->next = cur->next;
                free(cur);
                if ((prev->next) == NULL || (prev->next)->next == NULL)
                {
                    return;
                }
                //printf("accessing second deleteall\n");
                DeleteAll(x); //recursive call as i wasn't able to delete adjacent nodes earlier
            }
        }
    }
}

int FindLast(int x)
{
    int count = 0;
    int last_count = -1;
    node *cur;
    for (cur = first; cur != NULL; cur = cur->next)
    {
        if (cur->element == x)
            last_count = count;
        count++;
    }
    return last_count;
}

void PrintList()
{
    node *cur;
    if (first == NULL)
    {
        printf("LIST IS EMPTY!");
    }
    for (cur = first; cur != NULL; cur = cur->next)
    {
        if (first == NULL)
        {
            printf("LIST IS EMPTY!");
        }

        printf("%d ", cur->element);
    }
    printf("\n");
}

void DeleteNode(node *P)
{
    if (!P)
    {

        first = NULL;

        free(first);
    }
}

node *returnFirstNode()
{
    return first;
}
/* sir din't implement so i also left it;
// Delete first occurrence of X in list L
void FindAndDelete(List L,ElementType X)
{
    L = L->Next;
    while(L)
    {
        PtrToNode NextNode = L->Next;
        PtrToNode Tmp;
        if(NextNode && AreEqualElems(NextNode->Element,X)) // Found X !
        {
            Tmp = NextNode;
            L->Next = Tmp->Next;
            DeleteNode(Tmp);
            return;
        }
        else 
        {
            L = L->Next;
        }   
    }
}
*/

void EmptyList(node *LP) //slightly modified to make it compatible with my header file
{
    node *L = *LP;
    L = L->Next;
    node *Curr;
    while (L != NULL)
    {
        Curr = L;
        L = L->Next;
        DeleteNode(Curr);
    }
    (*LP)->Next = NULL;
}

void DeleteList(List* LP) // sir left this unused 
{
    EmptyList(LP);
    free(*LP);    
}
