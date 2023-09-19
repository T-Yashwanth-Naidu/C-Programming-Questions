/*
Segregate even and odd nodes in a linked list.

WTD: Use two pointers to rearrange nodes such that all even and odd elements are together.

(e.g.: I/P: 1->2->3->4; O/P: 2->4->1->3)

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

node* seg(node* head){
    node* p = head;     //ptr to follow even nos
    node* q = head;     //ptr for odd elements
    int temp;
    while(p!=NULL && q!=NULL){
        while(p!=NULL && p->data % 2 != 0 ){     //while p arrives at even element
            p=p->ptr;
        }
        while(q!= NULL && q->data%2 == 0){      //while q arruves at odd element
            q=q->ptr;
        }
        //swap p & q
        if(p!= NULL && q!= NULL){
            temp = p->data;
            p->data = q->data;
            q->data = temp;
            p=p->ptr;
            q=q->ptr;
        }
    }
    return head;

}
 
int main(){
    node* head = NULL;
    int data[] = {1,2,3,4};                      
    int size = sizeof(data) / sizeof(data[0]);
    head = createlist(head,data,size);
    print(seg(head));
     

}