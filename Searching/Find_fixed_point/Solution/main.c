/**
 * Author : Shivaram Nikhil Yella (YeLLaNikHiL99)
 * Find a fixed point (value equal to index) in a given array.
 * WTD: Write a function to find a fixed point (an element equal to its index) in a sorted array. Use binary search to efficiently find a fixed point.
 * Algorithm: Use binary search for a sorted array.
 * (e.g.: I/P: [-10, -5, 2, 4, 7, 9, 12, 17] ; O/P: 3)
*/

#include<stdio.h>

int findTheFixedPoint(int arr[], int n){
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (high - low)/2 + low;
        if(arr[mid] == mid){/*Check if the value is equal to the index*/
            return mid;
        }
        else if(mid < arr[mid]){/*If the value has higher value then proceed to left of the array*/
            high = mid - 1;
        }
        else{/*if the value is lesser than value then proceed to right of the array*/
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {-10, -5, 2, 4, 7, 9, 12, 17};
    int lengthOfTheArray = 8;
    int output = findTheFixedPoint(arr, 8);
    if(output == -1){
        printf("The given doesn't have any fixed point\n");
    }
    else{
        printf("The Fixed Point for the given array is : %d\n", output);
    }
}