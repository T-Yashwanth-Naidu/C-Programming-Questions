/*
Find the length of a singly linked list.

WTD: Traverse the list from head to tail, incrementing a counter to find its length.

(e.g.: I/P: 1->2->3->4; O/P: 4)

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

int getlength(node* head){
    int i = 0;
    for(node* p=head;p!=NULL;p=p->ptr){
        i++;
    }
    return i;

}


int main(){
    node* head = NULL;
    int data[] = {1,2,3,4};
    int size = sizeof(data) / sizeof(data[0]);
    head = createlist(head,data,size);
    //print(head);
    printf("length of list is %d\n\n",getlength(head));

}