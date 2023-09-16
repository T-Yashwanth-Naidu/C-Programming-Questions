/*
Find Middle element of a singly linked list in one pass.

WTD: Use two pointers, one moving twice as fast as the other, to find the middle element in a single pass.

(e.g.: I/P: 1->2->3->4->5; O/P: 3)

author : Vaaarad07
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
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

int findmid(node* head){
    node* p = head;                         //moves normally
    node* q = head;                        //moves twice as fast as p
    while(q != NULL && q->ptr != NULL){
        p = p->ptr;
        q = q->ptr->ptr;
    }
    return p->data;
}

int main(){

    node* head = NULL;
    int data[] = {1,2,3,4,5};
    int size = sizeof(data) / sizeof(data[0]);
    head = createlist(head, data, size);
    //print(head);
    int middle = findmid(head);
    printf("Middle element is %d\n\n",middle);
}