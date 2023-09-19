/*
Implemented both shallow copy and deep copy.

Consider the below to be your llist.
  1->2->3->4->5
Now, just point the first node to a differnt
pointer. This is called shallow copy.
  p...>1->2->3->4->5
p->next.data will give us 2. making changes 
to p will make changes to head as well.

In Deep copy, we allocate memory each time 
we see a data and then link it in a linkedlist.
This way two individual llists will be created.
head -> 1->2->3->4->5
deepcopy -> 1->2->3->4->5

Author - @8-bit-owl
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node* next;
}node;

int main(void)
{
    // First we create the linked list
    node *head = (node*)malloc(sizeof(node));

    /* this is shallow copy*/
    node *shallow_copy = head;    
    node *another_copy = head;
    int data[5] = {1, 2, 3, 4, 5};
    for (int i = 0;i < 5;i++)
    {
         head->data = data[i];
         head->next = (node*)malloc(sizeof(node));
         head->next->next = NULL;
         head = head->next;
    }
    

    /* 
    '*shallow_copy = head' is a shallow copy because 
    chaning contents of shallow_copy will change 
    contents of head, its just that you are pointing
    to head itself using a different name called 'shallow_copy' 
    */
    #if 0 //enable this to see shallow copy
    printf("Shallow copy\n");
    while (shallow_copy!=NULL)
    {
        printf("%d \n",shallow_copy->data);
        shallow_copy = shallow_copy->next;
    }
    #endif
    /*
    Implementing deep copy
    In deep copy all pointer should be different. Meaning
    If we change data of one pointer, it shouldnt 
    affect the original contents.
    Lets Begin!
    */
    node *deepcopy = (node*)malloc(sizeof(node));
    node *deepcopy_return = deepcopy;
    while (another_copy->next!=NULL)
    {
        
        deepcopy->data = another_copy->data;
        deepcopy->next = (node*)malloc(sizeof(node));
        deepcopy = deepcopy->next;
        another_copy = another_copy->next;


    }
    printf("Deep copy\n");
    while(deepcopy_return != NULL)
    {
        
        printf("%d \n",deepcopy_return->data);
        deepcopy_return = deepcopy_return->next;
    }

    return 0;
}