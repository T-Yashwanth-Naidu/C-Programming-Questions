/*
Intersection point of two linked lists.

WTD: Use two pointers, one for each list, and traverse to find the intersection point.

(e.g.: I/P: 1->2->3 & 4->5->3; O/P: 3)

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

int getintersection(node*head1, node* head2){
    node* p = head1;
    node* q = head2;

    while(p!= NULL && q!= NULL){
        if(p->data == q->data){
            return p->data;
        }
        p=p->ptr;
        q=q->ptr;
    }

}


int main(){
    node* head1 = NULL;
    node* head2 = NULL;
    int data1[] = {1,2,3};
    int data2[] = {4,5,3};
    int size1 = sizeof(data1) / sizeof(data1[0]);
    int size2 = sizeof(data2) / sizeof(data2[0]);
    head1 = createlist(head1,data1,size1);
    head2 = createlist(head2,data2,size2);
    printf("intersection point is %d\n\n",getintersection(head1,head2));
    //print(head1);
    //print(head2);

}