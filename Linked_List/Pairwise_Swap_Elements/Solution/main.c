/*
Pairwise swap elements of a linked list.

WTD: Swap every two adjacent nodes by adjusting their pointers.

(e.g.: I/P: 1->2->3->4; O/P: 2->1->4->3)

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

node* swap_two(node* head){
    node* p = head;         //trailing ptr
    node* q = p->ptr;       //leading ptr
    int data;               //  
    
    do{
        data = p->data;
        p->data = q->data;
        q->data = data;
        if(q->ptr == NULL){
            return head;
        }
        else{
            p=p->ptr->ptr;
            q=q->ptr->ptr;
        }

    }while(p!=NULL);
    return head;
}

int main(){
    node* head = NULL;
    int data[] = {1,2,3,4,5,6};                     //considering the no of elements is even
    int size = sizeof(data) / sizeof(data[0]);
    head = createlist(head,data,size);
    print(swap_two(head));

}