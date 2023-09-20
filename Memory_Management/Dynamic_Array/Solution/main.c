/*
Dynamic Array:

Implement a dynamic array with the ability to resize itself.

When adding an element, check if the array is full. If so, resize it.

When removing an element, consider resizing down if the array is less than half full.

author : Vaaarad07
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE        20

typedef struct myarr {
    int* data;
    int size;
    int fill;
}myarr;

myarr create(int size){
    myarr myarr;
    myarr.data = (int*)malloc(size+1);
    myarr.size = size;
    myarr.fill = 0;
    return myarr;
}

myarr add(myarr* a, int val){
    if(a->fill==a->size){
        int i=0;
        printf("Array size upgraded to %d elements!\n\n",a->size+1);
        a->data = (int*)realloc(a->data,a->size+1);
        a->size++;
    }
    int i = 0;
    for(i=0;i<a->fill;i++);
    a->data[i] = val;
    a->fill++;
    return *a;
}

myarr remove_arr(myarr* a){
    a->data[a->size-1] = 0;
    a->fill--;
    if(a->fill<a->size/2){
        a->data = (int*)realloc(a->data,a->size/2);
        a->size = a->size/2;
        printf("Array size reduced to %d elements!\n\n",a->size);
    }
    return *a;
}

int main(){
    myarr arr = create(3);
    int data[] = {1,2,3,4};
    for(int i=0;i<4;i++){                           //add elements from the array
        arr = add(&arr,data[i]);
    }
    for(int i=0;i<arr.fill;i++){                   //print dynamic array after adding elements
        printf("arr data is %d\n",arr.data[i]);
    }
    printf("\n\n");
    int j = 3;
    for(int x=0;x<j;x++){                          // remove j elements
        arr = remove_arr(&arr);
    }
    for(int i=0;i<arr.fill;i++){                   //print array after removl of elements
        printf("arr data is %d\n",arr.data[i]);
    }
     
}