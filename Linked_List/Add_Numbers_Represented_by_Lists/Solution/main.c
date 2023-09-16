/*
Add two numbers represented by linked lists.

WTD: Traverse both lists, sum the corresponding nodes, and manage the carry.

(e.g.: I/P: 2->4 & 5->6 (24 + 56); O/P: 8->0)

author : Vaaarad07
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node* ptr;
}node;

node* createlist(int nodes, int data[]){                        //function to create linked list
    //nodes is no of nodes to be created
    //data is array containing data for each node resp.
    node* head = NULL;
    node* p;
    for(int i=0;i<nodes;i++){
        if(head ==NULL){
            p = head = (node*)malloc(sizeof(node));
            p->data = data[0];
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

 

void print(node* head){                                 //function to print linked list
    node* tr;
    for(tr=head;tr != NULL; tr=tr->ptr){
        printf("data is: %d\n", tr->data);
    }
    printf("\n\n");

}

int addlist(node* head){                                //function to get a number from a list
    node* tr;
    int sum = 0;
    int i = 1;
    for(tr=head; tr != NULL; tr = tr->ptr){
        sum = (sum*i) + tr->data;
        i = i*10;
    }
    return sum;
}

node* fin_list(int num){                                //function to get final list having final result

    node* p = NULL;
    node* q;
    
    int i = 0;
    for(;num>0;){
        if(p == NULL){
            p = (node*)malloc(sizeof(node));
            p->data = num % 10;
            num = num / 10;
        }
        else{
            q = (node*)malloc(sizeof(node));
            q->ptr = p;
            q->data = num % 10;
            p = q;
            num = num / 10;
        }
    
        
    }
    return p;
}

int main(){

    node* head1, *head2;
    int data1[2] = {2,4};                           //array containn data for list 1 (number 1) 
    int data2 [2] = {5,6};                          //array containn data for list 2 (number 2)  
    head1 = createlist(2,data1);                    //create list 1 with repective digit as node
    head2 = createlist(2,data2);                    //create list 2 with repective digit as node
    //int num1 = addlist(head1);
    //int num2 = addlist(head2);
    int result = addlist(head1) + addlist(head2);   //getting result of additiion of two nums from two lists
    printf("Result is %d\n\n", result);         
    print(fin_list(result));                        //printing final linked list having result as data nodes
    //print(head1);
    //print(head2);
}
