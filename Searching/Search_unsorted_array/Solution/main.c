/*
Search for an element in an unsorted array.


WTD: Create a function that takes an unsorted array and a target element as input. Your task is to find the index of the target element using linear search. You can accomplish this by looping through the array and comparing each element with the target.

Algorithm: Linear search sequentially checks each element until the desired element is found or the array ends.

(e.g.: I/P: [5, 2, 9, 1, 5, 6], 9 ; O/P: 2)

author : Vaaarad07
*/

#include <stdio.h>

int linsearch(int arr[], int key, int size){
    for(int i = 0; i<size; i++){
        if(arr[i] == key){
            return i;
        }
        
    }
    return -1;
}

int main(){

    int arr[] = {5, 2, 9, 1, 5, 6};
    int key = 9;
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Index of key is %d\n\n", linsearch(arr, key, size));
}