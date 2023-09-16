/*
Find nth node from end of a singly linked list.

WTD: Use two pointers, move one n nodes ahead, then move both until the first one reaches the end.

(e.g.: I/P: 1->2->3->4 (n=2); O/P: 3)

author : Vaaarad07
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *ptr;
}node;

node* createlist(node* head, int data[],int n){
    node* p;
    for(int i = 0; i<n;i++){
        if(head == NULL){
            p = head = (node*)malloc(sizeof(node));
            p->data = data[i];
            p->ptr = NULL;
        }
        else{
            p->ptr = (node*)malloc(sizeof(node));
            p->ptr->data = data[i];
            p = p->ptr;
            p->ptr = NULL;
        }
    }
    return head;
}


void print(node* head){
    node* p = head;
    for(;p != NULL; p=p->ptr){
        printf("data is: %d\n", p->data);
    }
}

int findnode(node* head, int x){
    node *p = head;             //stays at the desired value
    node *q = head;             //goes ahead -> end
    for(int i=0;i<x;i++){
        q = q->ptr;
    }
    while(q != NULL){
        p = p->ptr;
        q = q->ptr;
    }
    return p->data;
}

int main(){
    node* head = NULL;
    int data[] = {1,2,3,4};
    int size = sizeof(data) / sizeof(data[0]);
    int x = 2;                                              //node no.
    head = createlist(head,data,size);
    //print(head);
    printf("Nth node data is %d\n\n", findnode(head,x));
}