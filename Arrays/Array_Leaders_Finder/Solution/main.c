/* Compute the leaders in an array.

WTD: Traverse the array from right to left, finding numbers that remain the largest compared to all numbers on their right.

(e.g.: I/P: [16,17,4,3,5,2], O/P: [17,5,2]) */

#include <stdio.h>

void find_leaders(int arr[], int length){
    
  int leader = arr[length-1]; // creating var to store the largest number
    printf("%d\t",leader);
    
    //traversing from right to left and comparing 
    for(int i=length-2;i>0;i--){
        if(arr[i]>leader){
            leader = arr[i];
            printf("%d\t",leader);
        }
    }  
}

int main()
{
    //input array
    int arr[] = {16,17,4,3,5,2};
    int length = sizeof(arr)/sizeof(arr[0]); //no. of elements in the array
    
    find_leaders(arr,length);

    return 0;
}