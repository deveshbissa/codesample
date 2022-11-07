/**
 *  Linked List
 */

#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
typedef struct  node{
    int data;          
    struct node *next;  
}node;


/* 
 * Functions to create and display list
 */
node *createList(int n);



int main()
{
    int n;
    node *listHead ;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    listHead = createList(n);

    printf("\nData in the list \n");
    if (listHead == NULL)
    {
        printf("List is empty.");
        return 0;
    }
     
    while (listHead != NULL)
    {
        printf("Entry = %d\n", listHead->data); // Print data of current node
        listHead = listHead->next;     
    }

    return 0;
}

node *createList(int n)
{
    node *newNode, *temp,*head;
    int data, i;

    head = (node *)malloc(sizeof(node));

    // Terminate if memory not allocated
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }


    // Input data of node from the user
    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data; // Link data field with data
    head->next = NULL; // Link address field to NULL


    // Create n - 1 nodes and add to list
    temp = head;
    for(i=2; i<=n; i++)
    {
        newNode = (node *)malloc(sizeof(node));

        /* If memory is not allocated for newNode */
        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; // Link data field of newNode
        newNode->next = NULL; // Make sure new node points to NULL 

        temp->next = newNode; // Link previous node with newNode
        temp = temp->next;    // Make current node as previous node
    }

    return head;
}
