/*
 * =====================================================================================
 *
 *       Filename:  DeleteAllDuplicateElememnt.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/18/2020 11:26:13 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct __Node
{
    int data;
    struct __Node *next;
};

typedef struct __Node Node;

void createLinkedList(Node **head, int *arr, int size)
{
    int i = 0;

    Node *curr = NULL;

    while(i < size)
    {
        Node *temp = (Node *)malloc(sizeof(Node));

        if(i == 0)
        {
            *head = temp;
            temp->data = arr[i];
            curr = temp;
        }
        else
        {
            temp->data = arr[i];
            temp->next = NULL;
            curr->next = temp;
            curr = curr->next;
        }

        ++i;
    }

    if(curr)
    {
        curr->next = NULL;
    }
}

void printLinkedList(Node **head)
{
    printf("[ ");

    Node *temp = *head;

    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("]\n");
}

Node *deleteAllDuplicateElement(Node **head, int del)
{
    Node *temp = *head;
    Node *prev = NULL;

    while(temp)
    {
        if(temp->data != del)
        {
            break;
        }

        Node *ndel = temp;
        temp = temp->next;
        free(ndel);
    }

    *head = temp;

    while(temp)
    {
        if(temp->data == del)
        {
            Node *ndel = temp;
            prev->next = temp->next;
            temp = prev->next;
            free(ndel);
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
}

void freeLinkedList(Node **head)
{
    while(*head)
    {
        Node *ndel = *head;
        *head = (*head)->next;
        free(ndel);
    }
}

void testRemoveDuplicate(int *arr, int size, int elm_del)
{
    Node *head = NULL;

    createLinkedList(&head, arr, size);

    printf("Original Linked list - ");
    printLinkedList(&head);

    deleteAllDuplicateElement(&head, elm_del);

    printf("After removing duplicate  - ");
    printLinkedList(&head);

    freeLinkedList(&head);

    head = NULL;
}

int main(int argc, char **argv)
{
    // Case 1
    int arr[10] = {1, 1, 2, 1, 1, 5, 6, 7, 1, 1};
    testRemoveDuplicate(arr, 10, 1);

    // Case 2
    int arr1[0];
    testRemoveDuplicate(arr1, 0, -1);

    // Case 3
    int arr2[15] = {1, -1, -1, 3, 4, 7, 8, 9, -1, 10, -1, -1, 9, 8, -1};
    testRemoveDuplicate(arr2, 15, -1);

    return 0;
}

