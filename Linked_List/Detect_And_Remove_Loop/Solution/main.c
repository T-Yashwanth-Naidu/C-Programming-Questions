/*
Floyd's Cycle-Finding Algorithm

1. We use two pointers, slow_p and fast_p.
2. Both start pointing to the head of the list.
3. We move slow_p by one node and fast_p by two nodes.
4. If the two pointers meet, then there is a loop.
5. If the two pointers do not meet, then there is no loop.

But there is a better way.

We modify the data structure we use for the linked list.
We add a new field called visited to the node structure.
Everytime we visit a node, we set visited to 1.
so next time we visit and see that visited is 1, we know that
there is a loop.


author: @8-bit-owl
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    int visited;
}node;


int main(void)
{
    // First we create the linked list
    node *head = (node*)malloc(sizeof(node));
    node *reference = head;
    int data[] = {1, 2, 3};
    int size = sizeof(data)/sizeof(data[0]);
    for (int i = 0;i < size;i++)
    {
         head->data = data[i];
         head->next = (node*)malloc(sizeof(node));
         head->visited = 0;
         head = head->next;
    }
    // This is the loop
    head->next = head;


    //loop detection
    while(reference!=NULL)
    {
        if (reference->visited == 1)
        {
            printf("Loop detected\n");
            //breakt the loop
            reference->next = NULL;
            break;
        }
        reference->visited = 1;
        reference = reference->next;
    }
    return 0;
}