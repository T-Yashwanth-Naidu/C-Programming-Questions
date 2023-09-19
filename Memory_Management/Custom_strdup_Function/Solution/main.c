/*
Custom strdup Function:

Implement a custom strdup function that copies a string into dynamically allocated memory.

(e.g.: I/P: "hello"; O/P: Address of new string "hello")

author : Vaaarad07
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_SIZE        20

char* new_addr(char arr[],int size){
    char* ptr = (char*)malloc(sizeof(size));
    strcpy(ptr,arr);
    return ptr;
}

int main(){
    char arr[MAX_STR_SIZE];
    printf("Enter string: ");
    scanf("%s",arr);
    char * new_ptr = new_addr(arr,strlen(arr)+1);
    printf("returned str is %s\n\n",new_ptr);
    //printf("You entered %s & length is %d\n\n",arr,strlen(arr));
}