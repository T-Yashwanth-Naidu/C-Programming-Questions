/*
Partition a linked list around a given value.

WTD: Traverse the linked list, creating two separate lists - one for values less than the partition value and another for values greater than or equal to the partition value. Finally, merge these lists.

(e.g.: I/P: 1->4->3->2->5->2, Partition Value: 3; O/P: 1->2->2->4->3->5)

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
 
node* partition(node* head, int val){
    node* p = NULL;             //ptr to traverse list 1
    node* head1 = NULL;         //head of list w values less than
    node* q = NULL;             //ptr to traverse second list
    node* head2 = NULL;         //head of list with values greater than or equal to
    node* result;

    for(node* temp = head;temp != NULL;temp=temp->ptr){
      
        if(temp->data >= val){       //add to list 2 -> q
            if(q==NULL){
                q = head2 = (node*)malloc(sizeof(node));
                q->ptr = NULL;
                q->data = temp->data;
            }
            else{
                q->ptr = (node*)malloc(sizeof(node));
                q->ptr->data = temp->data;
                q=q->ptr;
                q->ptr = NULL;
            }
        }   
        else if(temp->data < val){
             if(p==NULL){
                p = head1 = (node*)malloc(sizeof(node));
                p->ptr = NULL;
                p->data = temp->data;
            }
            else{
                p->ptr = (node*)malloc(sizeof(node));
                p->ptr->data = temp->data;
                p=p->ptr;
                p->ptr = NULL;
            }
        }

    }
    if(p==NULL){
        return head2;
    }
    else if(q==NULL){
        return head1;
    }
    result = head1;
    for(p=head1;p->ptr!=NULL;p=p->ptr);
    p->ptr = head2;
    return result;
}


int main(){
    node* head = NULL;
    int data[] = {1,4,3,2,5,2};                      
    int val = 3;
    int size = sizeof(data) / sizeof(data[0]);
    head = createlist(head,data,size);
    print(partition(head,val));

}