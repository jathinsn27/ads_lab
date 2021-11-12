#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct Node{
    int data;
    struct Node *npx;
};

struct Node* XOR (struct Node *a, struct Node *b){
    return (struct Node *) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

void insert(struct Node **head_ref, int data){
    struct Node *new_node = (struct Node*)malloc (sizeof (struct Node));
    new_node->data = data;
    
    new_node->npx = *head_ref;
    
    if(*head_ref != NULL){
        (*head_ref)->npx = XOR(new_node, (*head_ref)->npx);
    }
    
    *head_ref = new_node;
}

struct Node* delete_front(struct Node** head){
    if(*head = NULL){
        printf("List is empty");
    }
    else{
        struct Node *temp = *head;
        
        *head = XOR(NULL, temp->npx);
        
        if(*head != NULL){
            (*head)->npx =  XOR(NULL, XOR(temp,(*head)->npx));
        }
    
    free(temp);
    
    return *head;
    }
}

void printList(struct Node *head){
    struct Node *cur = head;
    struct Node *prev = NULL;
    struct Node *next;
    
    printf("The nodes of linked list are:\n");
    
    while(cur != NULL){
        next = XOR(prev, cur->npx);
        printf("%d\n", cur->data);
        
        prev = cur;
        cur = next;
    }
}

int main()
{
    struct Node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    printList(head);
    delete_front(&head);
    printList(head);
    
    return 0;
}
