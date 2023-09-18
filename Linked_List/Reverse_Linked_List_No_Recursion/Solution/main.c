/*
Reverse a singly linked list without recursion.

WTD: Use iterative method to reverse the next pointers of each node.

(e.g.: I/P: 1->2->3; O/P: 3->2->1)

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
 
node* reverse(node* head){
    node* p = head;
    node* q = p->ptr;
    node* temp;
    
    while(q!=NULL){
        temp = q->ptr;
        q->ptr = p;
        p=q;
        q=temp;    
    }
    head->ptr = NULL;
    return p;
}


int main(){
    node* head = NULL;
    int data[] = {1,2,3};                      
    int size = sizeof(data) / sizeof(data[0]);
    head = createlist(head,data,size);
    print(reverse(head));

}