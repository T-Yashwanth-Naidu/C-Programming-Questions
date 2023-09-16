/*
Delete alternate nodes of a linked list.

WTD: Traverse the list and remove every alternate node.

(e.g.: I/P: 1->2->3->4; O/P: 1->3)

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

node* deletenode(node*head){
    node* p = head;
    node* temp;
    while(p != NULL && p->ptr != NULL){
        temp = p->ptr;
        p->ptr = p->ptr->ptr;
        free(temp);
        p = p->ptr;
    }
    return head;
}

void print(node* head){
    node* p = head;
    for(;p != NULL; p=p->ptr){
        printf("data is: %d\n", p->data);
    }
}


int main(){
    node* head = NULL;
    int data[] = {1,2,3,4};
    int size = sizeof(data) / sizeof(data[0]);
    head = createlist(head,data,size);
    //print(head);
    head = deletenode(head);
    print(head);

}