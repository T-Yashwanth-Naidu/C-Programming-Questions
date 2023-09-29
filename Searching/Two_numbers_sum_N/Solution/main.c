/*
In a sorted array, find two numbers that add up to a specific target sum "N".

WTD: Create a function that, in a sorted array, finds two numbers that add up to a specific target sum "N". Use a two-pointer technique or binary search for an efficient solution.

Algorithm: Use two-pointer technique or binary search.

(e.g.: I/P: [1, 2, 3, 4, 5], N = 9; O/P: (4, 5))

author : Vaaarad07
*/

#include <stdio.h>

int* twosum(int arr[], int sum, int size){
   int *result = (int*) malloc(2*sizeof(int));
    result[0] = result[1] = -1;
    int leftIndex = 0, rightIndex = size-1;
    while(leftIndex < rightIndex){
        int elemSum = arr[leftIndex] + arr[rightIndex];
        if(elemSum == sum){
            result[0] = arr[leftIndex];
            result[1] = arr[rightIndex];
            break;
        }
        else if(elemSum > sum){
            rightIndex--;
        }
        else{
            leftIndex++;
        }
    }
    return result;
}

int main(){

    int arr[] = {1, 2, 3, 4, 5};
    int sum = 9;
    int size = sizeof(arr) / sizeof(arr[0]);
    int* result;
    result = twosum(arr, sum, size);
    if(result[0] != -1){
        printf("Result is %d & %d\n\n",result[0],result[1]);
    }
    else{
        printf("no element found\n\n"); //no suitable pair found
    }

}