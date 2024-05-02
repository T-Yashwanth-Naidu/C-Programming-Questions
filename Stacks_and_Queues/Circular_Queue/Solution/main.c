/*Develop a circular queue that overwrites the oldest elements when the queue reaches its capacity. 
Implement wrap-around functionality to make sure that new elements are inserted at the start of the 
array when the end is reached.  

(e.g: I/P: Enqueue 1, 2, 3, 4 (Size=3) ; O/P: 2, 3, 4)*/

#include <stdio.h>
#include <stdlib.h> // Needed for dynamic memory allocation

int size;
int* q; // Pointer to int for dynamic memory allocation
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    q[rear] = x;
}

int main() {
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the queue based on input size
    q = (int*)malloc(size * sizeof(int));

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    
    printf("Queue elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", q[i]);
    }
    
    printf("\n");
    
    // Free dynamically allocated memory
    free(q);

    return 0;
}
