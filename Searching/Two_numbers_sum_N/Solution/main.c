/*
In a sorted array, find two numbers that add up to a specific target sum "N".

WTD: Create a function that, in a sorted array, finds two numbers that add up to a specific target sum "N". Use a two-pointer technique or binary search for an efficient solution.

Algorithm: Use two-pointer technique or binary search.

(e.g.: I/P: [1, 2, 3, 4, 5], N = 9; O/P: (4, 5))

author : Vaaarad07
*/

#include <stdio.h>

int* twosum(int arr[], int sum, int size){
    int* ptr1;
    int* ptr2;
    static int result[3] = {-1,-1,0};
    for(int i=0;i<size;i++){
        ptr1 = &arr[i];
        for(int j=0;j<size;j++){
            ptr2 = &arr[j];
            if((*ptr1 + *ptr2) == sum){
                result[0] = *ptr1;
                result[1] = *ptr2;
                result[2] = 1;;
            }
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
    if(result[2]){
        printf("Result is %d & %d\n\n",result[0],result[1]);
    }
    else{
        printf("no element found\n\n"); //no suitable pair found
    }

}