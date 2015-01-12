//
//  main.c
//  linked list
//
//  Created by Chien-Pao Chueh on 1/10/15.
//  Copyright (c) 2015 Chien-Pao Chueh. All rights reserved.
//
//搜尋的時間複雜度是 O(N) 。知道記憶體位址，插入與刪除的時間複雜度是 O(1) ，否則必須先搜尋。無索引值，故不支援二分搜尋。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    int min;
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
    free(current->next);
    current->next = NULL;
    
    return 0;
}

int min(int x, int y){
    if(x>y)
    return y;
    else if(x<y)
    return x;
    else
    return x;
    
}

void push(node ** head, int data) {
    //int min = 0;
    node * new_node;
    new_node = malloc(sizeof(node));
    
    new_node->data = data;
    new_node->next = *head;
    new_node->min = data;
    *head = new_node;
    if(new_node->next != NULL){
        printf("new_node->data=%d, new_node->next->data=%d, min=%d\n", new_node->data, new_node->next->data, min(new_node->data, new_node->next->data));
        new_node->min = min(new_node->data, new_node->next->min);
    }
    
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
void reverse(node** head)
{
    node* prev   = NULL;
    node* current = *head;
    node* next = NULL;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

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

void print_min(void)
{
    node *ptr = head;
    
    printf("\n -------Printing min \n");
    printf("[%d]",ptr->min);
    printf("\n -------Printing min \n");
    
    return;
}

int main(int argc, const char * argv[]) {
    /*
    head = (node*)malloc(sizeof(node));
    if (head == NULL) {
        return 1;
    }
    
    head->data = 1;
    head->next = NULL;
    
    add(head, 2);
    add(head, 2);
    add(head, 5);
    add(head, 3);
     */
    push(&head, 2);
    push(&head, 10);
    push(&head, 6);
    push(&head, 8);
    push(&head, 1);
    push(&head, 1);
    //pop(&head);
    //pop(&head);
    //remove_last(head);
    //remove_last(head);
    //add(head, 1);
    //remove_last(head);
    //remove_by_index(&head, 1);
    //reverse(&head);
    print_list();
    print_min();
    
    
    return 0;
}
