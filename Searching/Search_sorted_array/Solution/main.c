/*
Search for an element in a sorted array.

WTD: Implement a function that performs binary search to find a target element in a sorted array. You'll need to start by comparing the target with the middle element and adjust your search range accordingly. Divide and conquer by halving the array.

Algorithm: Binary search divides the array into halves and compares the middle element to the target.

(e.g.: I/P: [1, 2, 3, 4, 5], 4 ; O/P: 3)

author : Vaaarad07
*/

#include <stdio.h>

int binsearch(int arr[], int left, int right, int key, int size){
    
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            right = mid - 1;
        }
        else if(arr[mid] < key){
            left = mid+1;
        }
    }
    return -1;
}

int main(){

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 4;
    printf("Key exists at index %d\n\n",binsearch(arr,0,size-1,key,size));
}