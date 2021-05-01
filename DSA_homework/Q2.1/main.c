#include "linkedlists.h"

int main()
{
    int i = 0;
    int element;
    char ch = 'y';
    char command[20];
    node *Pointer;
    node *head;
    head = returnFirstNode();

    while (ch != 'n')
    {
        scanf("%d", &element);
        InsertNode(element);
        printf("continue inserting nodes?(y/n): ");
        getchar();
        ch = getchar();
    }
    while (1)
    {
        printf("Enter a command :");
        scanf("%s", command);
        if (strcmp(command, "DeleteAll") == 0)
        {
            printf("Enter an element:");
            scanf("%d", &element);
            DeleteAll(element);
            PrintList();
        }
        if (strcmp(command, "FindLast") == 0)
        {
            printf("Enter an element:");
            scanf("%d", &element);
            printf("last occurence of %d is %d\n", element, FindLast(element));
            PrintList();
        }
        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        if (strcmp(command, "DeleteNode") == 0)
        {
            DeleteNode(head);
            PrintList();
        }
        if (strcmp(command, "print") == 0)
        {
            PrintList();
        }
    }
    //PrintList();
}