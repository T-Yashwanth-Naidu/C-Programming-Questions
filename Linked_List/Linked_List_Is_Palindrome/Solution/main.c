/*
Determine if a linked list is a palindrome.

WTD: Use a slow and fast pointer to find the middle of the list. Reverse the second half and compare it with the first half to determine if the linked list is a palindrome.

(e.g.: I/P: 1->2->2->1; O/P: True)

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

int ispalindrome(node* head){
    node* p = head;                 //stays at mid
    node* q = head;                 //moves fast -> goes to the end
    node* rev_head = NULL;
    node* temp = NULL;
    node* mid;
    while(q!= NULL && q->ptr != NULL){
        p=p->ptr;
        q=q->ptr->ptr;
    }
    mid = p;
    //p=p->ptr;
    //p is at mid   &&  q is at last node
    for(;p != NULL; p=p->ptr){
        if(p == mid){
            rev_head = (node*)malloc(sizeof(node));
            rev_head->ptr = NULL;
        }
        else{
            rev_head = (node*)malloc(sizeof(node));
            rev_head->ptr = temp;
        }
        rev_head->data = p->data;
        temp = rev_head;
        
    }
    p=head;
    //return rev_head;             //head of second half of list in reverse order
    while(rev_head != NULL){
        if(p->data != rev_head->data){
            return 0;
        }
        p=p->ptr;
        rev_head=rev_head->ptr;
    }
    return 1;

}
 
int main(){
    node* head = NULL;
    int data[] = {1,2,2,2,2,1};
    int size = sizeof(data) / sizeof(data[0]);
    head = createlist(head,data,size);
    if(ispalindrome(head)){
        printf("List is a palindrome!\n\n");
    }
    else{
        printf("List is not a palindrome\n\n");
    }
    //print(ispalindrome(head));     
    //print(ispalindrome(head));

}