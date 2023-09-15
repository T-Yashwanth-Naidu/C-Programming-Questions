/*
Count the number of times a sorted array is rotated.

WTD: Write a function that counts the number of times a sorted array is rotated. Use binary search to identify the pivot element, which indicates the rotation count.

Algorithm: Use binary search to find the pivot element.

(e.g.: I/P: [15, 18, 2, 3, 6, 12]; O/P: 2)

author : Vaaarad07
*/
 
//  2 , 3, , 6, 12, 15, 18
//  3, 6, 12, 15, 18, 2
//  18, 2, 3, 6, 12, 15

#include <stdio.h>

int getRotations(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        
        if (arr[left] <= arr[right]) {  //array sorted
            return left;
        }
        int mid = left + (right - left) / 2;
        int next = (mid + 1) % size;
        int prev = (mid + size - 1) % size;
         
        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {       //if mid is pivot
            return mid;
        }

       
        if (arr[mid] <= arr[right]) {                               //right part is sorted
            right = mid - 1;
        } else if (arr[mid] >= arr[left]) {                         //left part is sorted
            left = mid + 1;
        }
    }
 
}

int main() {
    int arr[] = {15, 18, 2, 3, 6, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("The array is rotated %d times\n\n",getRotations(arr, size));

}
