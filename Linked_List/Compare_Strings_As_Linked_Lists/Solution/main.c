/*
Compare two strings represented as linked lists.

WTD: Traverse both lists, comparing each node's value. If they are equal throughout, the lists are equal.

(e.g.: I/P: 'a'->'b'->'c' & 'a'->'b'->'c'; O/P: Equal)

author : Vaaarad07
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node* ptr;
}node;

node* createlist(node* head, char data[],int n){
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
        printf("data is: %c\n", p->data);
    }
}

int compare(node* head1, node* head2){
    node* p = head1;
    node* q = head2;
    while(p != NULL && q != NULL){
        if(p->data != q->data){
            return 0;
        }
        p = p->ptr;
        q = q->ptr;
    }
    return 1;
}

int main(){
    node* head1 = NULL;
    node* head2 = NULL;

    char data1[] = {'a', 'b','c'};
    char data2[] = {'a', 'b','c'};
    int size1 = sizeof(data1) / sizeof(data1[0]);
    int size2 = sizeof(data2) / sizeof(data2[0]);
    head1 = createlist(head1, data1, size1);
    head2 = createlist(head2, data2, size2);
     
    if(compare(head1,head2) == 1){
        printf("Strings match\n\n");
    }
    else{
        printf("Strings do not match\n\n");
    }

    //print(createlist(head1,data1,3));
    //print(createlist(head2,data2,3));
}