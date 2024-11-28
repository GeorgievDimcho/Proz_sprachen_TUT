#include <stdio.h>
#include <stdlib.h>
// declaring structure with name str1
struct node
{
    int i;
    struct node *next;
};
typedef struct node N;

void printFunc(N *printVar)
{
    while (printVar != NULL)
    {
        printf("%d ", printVar->i);
        printVar = printVar->next;
    }
    printf("\n");
}

void freeHead(N *freeing)
{
    N *clear;
    while (freeing != NULL)
    {
        clear = freeing;
        freeing = freeing->next;
        free(clear);
        printFunc(freeing);
    }
}
/*
struct node *addAt(int index, int value, struct node *head)
{
    if (index == 0)
        return addFirst(value, head);

    int counter = 0;
    struct node *temp = head;
    struct node *beforeTemp = NULL;
    while (temp != NULL)
    {
        if (index == counter)
        {
            struct node *newNode = createNode(value);
            newNode->next = temp;
            beforeTemp->next = newNode;
            return head;
        }
        beforeTemp = temp;
        temp = temp->next;
        ++counter;
    }

    if (index == counter)
    {
        struct node *newNode = createNode(value);
        newNode->next = temp;
        beforeTemp->next = newNode;
    }

    return head;
}
*/

N* addFirst(N* newHead, int i)
{
    
    //head0 = (N *)malloc(sizeof(N)); // freie field in memory reservieren
    N* head0 = (N *)malloc(sizeof(struct node));
    head0->i = i;
    head0->next = newHead;
    return head0;
}
int main()
{
    int i;
    N *head = NULL;

    while (1)
    {

        scanf(" %d", &i);

        if (i == 0)
        {
            break;
        }
        // speichern

        head = addFirst(head, i);
    }
    // ausgeben
    printf("PRINTING:\n");
    printFunc(head);
    // printf("Test: head0: %d", head->i);
    freeHead(head);

    // speicher frei

    return 0;
}