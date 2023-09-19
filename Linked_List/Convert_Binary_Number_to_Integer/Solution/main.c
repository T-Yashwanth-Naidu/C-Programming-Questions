/*
The idea is to traverse through llist, 
and push the data into the hex value.

We start with 0x0, we shift by 1 bit to the left
everytime we traverse through llist and | it with
the data of the node.

1->0->1

step 1:
0x0 | 1 = 0x1

step 2:
0x1 << 1 | 0= 0x2

step 3:
0x2 << 1 | 1 = 0x5

So the final hex value is 0x5

author: @8-bit-owl
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
    node *reference = head;
    unsigned int return_value = 0x0;
    int data[] = {1, 0, 1};
    int size = sizeof(data)/sizeof(data[0]);
    for (int i = 0;i < size;i++)
    {
         head->data = data[i];
         head->next = (node*)malloc(sizeof(node));
         head->next->next = NULL;
         head = head->next;
    }
    
    // Here we traverse through the linked list
    // and push the data into the hex value from the left
    while(reference!=NULL)
    {
        return_value = return_value << 1 | reference->data;
        reference = reference->next;
    }
    return_value = return_value >> 1;
    printf(" Hex     - 0x%x\n",return_value);
    printf(" Decimal - %d\n",return_value);
    return 0;
}