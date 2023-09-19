/*
Move last element to the front of a given linked list.

WTD: Find the last node and its previous node, change their pointers to move the last node to the front.

(e.g.: I/P: 1->2->3->4; O/P: 4->1->2->3)

author : Vaaarad07
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* ptr; 
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

node* movelast(node* head){
    node* p=head;
    node* temp;
    if(head->ptr == NULL){
        return head;
    }
    for(;p->ptr->ptr != NULL;p=p->ptr);
    temp = p->ptr;
    p->ptr = NULL;
    temp->ptr = head;
    return temp;
}


int main(){
    node* head = NULL;
    int data[] = {1,2,3,4};
    int size = sizeof(data) / sizeof(data[0]);
    head = createlist(head,data,size);
    print(movelast(head));

}