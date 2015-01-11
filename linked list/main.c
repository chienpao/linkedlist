//
//  main.c
//  linked list
//
//  Created by Chien-Pao Chueh on 1/10/15.
//  Copyright (c) 2015 Chien-Pao Chueh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;


node *head = NULL;

void add(node * head, int data) {
    node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    /* now we can add a new variable */
    current->next = malloc(sizeof(node));
    current->next->data = data;
    current->next->next = NULL;
}

void push(node ** head, int data) {
    node * new_node;
    new_node = malloc(sizeof(node));
    
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

int pop(node ** head) {
    int retval = -1;
    node * next_node = NULL;
    
    if (*head == NULL) {
        return -1;
    }
    
    next_node = (*head)->next;
    retval = (*head)->data;
    free(*head);
    *head = next_node;
    
    return retval;
}

int remove_last(node * head) {
    
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        printf("test");
        head->data = 0;
        free(head);
        head = NULL;
        return retval;
    }

    node * current = head;
    
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    current->next = NULL;
    
    return 0;
}

int remove_by_index(node ** head, int n) {
    //int i = 0;
    int retval = -1;
    node * current = *head;
    node * temp_node = NULL;
    
    if (n == 0) {
        return pop(head);
    }
    
    for (int i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }
    
    temp_node = current->next;
    retval = temp_node->data;
    current->next = temp_node->next;
    free(temp_node);
    
    return retval;
    
}

//reverse need three pointers

void print_list(void)
{
    node *ptr = head;
    
    printf("\n -------Printing list Start------- \n");
    while(ptr != NULL)
    {
        printf("[%d]",ptr->data);
        ptr = ptr->next;
    }
    printf("\n -------Printing list End------- \n");
    
    return;
}

int main(int argc, const char * argv[]) {

    head = (node*)malloc(sizeof(node));
    if (head == NULL) {
        return 1;
    }
    
    head->data = 1;
    head->next = NULL;
    
    add(head, 2);
    push(&head, 3);
    //pop(&head);
    //pop(&head);
    //remove_last(head);
    //remove_last(head);
    //remove_last(head);
    remove_by_index(&head, 1);
    
    print_list();
    
    
    
    return 0;
}
