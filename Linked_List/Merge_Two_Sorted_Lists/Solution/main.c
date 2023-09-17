/*
Merge two sorted linked lists.

WTD: Use a temporary dummy node to hold the sorted list, compare each node and attach the smaller one to the dummy.

(e.g.: I/P: 1->3->5 & 2->4->6; O/P: 1->2->3->4->5->6)

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

node* mergelist(node* head1, node* head2, int size1,int size2){
    node* fin = NULL;
    node* p= NULL;
    node* a1 = head1;
    node* a2 = head2;
    for(int i=0;i<size1*2;i++){
        if(fin == NULL){
            fin = p = (node*)malloc(sizeof(node));
            fin->ptr = NULL;
        }
        else{
            p->ptr = (node*)malloc(sizeof(node));
            p=p->ptr;
            p->ptr = NULL;
        }
    }
    p = fin;
    for(int i=0;i<size1;i++){
        if(a1->data < a2->data){
            p->data = a1->data;
            p->ptr->data = a2->data;
            p=p->ptr->ptr;
            a1=a1->ptr;
            a2=a2->ptr;
        }
        else{
            p->data = a2->data;
            p->ptr->data = a1->data;
            p=p->ptr->ptr;
            a1=a1->ptr;
            a2=a2->ptr;
        }
    }
    return fin;
}

int main(){
    int data1[]={1,3,5};
    int size1 = sizeof(data1) / sizeof(data1[0]);
    int data2[]={2,4,6};
    int size2 = sizeof(data2) / sizeof(data2[0]);
    node* head1=NULL;
    node* head2 = NULL;
    head1 = createlist(head1,data1,size1);
    head2 = createlist(head2,data2,size2);
    //print(head2);
    print(mergelist(head1,head2,size1,size2));
}