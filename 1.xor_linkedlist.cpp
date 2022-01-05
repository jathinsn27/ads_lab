#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#include <cinttypes>

using namespace std;

class Node{
    public:
    int data;
    Node* npx;
};

Node* XOR (Node *a, Node *b)
{
    return reinterpret_cast<Node *>(
      reinterpret_cast<uintptr_t>(a) ^
      reinterpret_cast<uintptr_t>(b));
}

void insert(Node **head_ref, int data)
{
    Node *new_node = new Node();
    new_node->data = data;

    new_node->npx = *head_ref;

    if (*head_ref != NULL)
    {
        (*head_ref)->npx = XOR(new_node, (*head_ref)->npx);
    }

    *head_ref = new_node;
}

void printList(Node *head){
    Node *cur = head;
    Node *prev = NULL;
    Node *next;
    
    cout<< "Following are the nodes of the linked list: \n";
    
    while(cur != NULL){
        cout<<cur->data<<" ";
        next = XOR(prev, cur->npx);
        prev = cur;
        cur = next;
    }
}

Node* delete_front(Node** head){
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
    }
    return *head;
}


int main ()
{
    Node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
 
    printList (head);
 
    return (0);
}
