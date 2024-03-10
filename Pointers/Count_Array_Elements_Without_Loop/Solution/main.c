/*Create a function that uses pointer arithmetic to count the number of elements in an array without utilizing loop constructs.

WTD: Subtract the pointer to the first element from the pointer just past the last element.

(e.g.: I/P: int arr[] = {1,2,3,4,5} ,O/P: 5 ) */

#include<stdio.h>

int count_elements(int *start, int *end){
    
    return end-start;
}
int main(){
    
    int arr[] = {1,2,3,4,5};
    
    printf("%d",count_elements(arr, arr + sizeof(arr) / sizeof(arr[0])));
    printf("%ls",arr);

    return 0; 
}