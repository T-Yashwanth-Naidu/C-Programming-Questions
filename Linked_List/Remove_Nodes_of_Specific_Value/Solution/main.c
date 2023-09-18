/*
Remove all nodes in a linked list that have a specific value.

WTD: Traverse the linked list and remove any node that has a value matching the specified value. Make sure to properly update the next pointers and free any removed nodes.

(e.g.: I/P: 1->2->6->3->4->5->6, Value to Remove: 6; O/P: 1->2->3->4->5)

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

node* remove_node(node* head,int val){
    node* p=head;
    node* q = p->ptr;
    node* temp;
    if(p->data == val){
        temp = head;
        head = temp->ptr;
        free(temp);
        p = head;
        q=p->ptr;
    }
    for(;q!= NULL;q=q->ptr){
        if(q->data == val){
            p->ptr = q->ptr;
            free(q);
            q = p;
        }
        else{
            p=p->ptr;
        }
    }
    return head;
}

int main(){
    node* head = NULL;
    int data[] = {1,2,6,3,4,5,6};                      
    int val = 6;
    int size = sizeof(data) / sizeof(data[0]);
    head = createlist(head,data,size);
    print(remove_node(head,val));

}