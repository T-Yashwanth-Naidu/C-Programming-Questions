/**
 * Author : Shivaram Nikhil Yella (YeLLaNikHiL99)
 * Search for an element in a matrix where rows and columns are sorted.
 * WTD: Develop a function to search for an element in a matrix where the rows and columns are sorted. Start from the top-right or bottom-left corner and incrementally move toward the target.
 * Algorithm: Start from the top-right or bottom-left corner and move towards the target.
 * (e.g.: I/P: Matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], Search Element = 5; O/P: (1, 1))
*/

#include<stdio.h>
#include<stdlib.h>

int *searchInMatrix(int matrix[][3], int n, int value){
    int row = 0, col = n-1;
    int *out = (int*)malloc(2*sizeof(int));
    out[0] = out[1] = -1;
    while(row < n && col >= 0){
        if(matrix[row][col] == value){
            out[0] = row;
            out[1] = col;
            return out;
        }
        else if(matrix[row][col] < value){
            row++;
        }
        else{
            col--;
        }
    }
    return out;
}

int main(){
    int matrix[][3] = {{1,2,3},
                        {4,5,6},
                        {7, 8, 9}
                        };
    int value = 4;
    int *index = searchInMatrix(matrix, 3, value);
    if(index[0] == -1 || index[1]==-1){
        printf("The value is not present in matrix\n");
    }
    else{
        printf("The value is present in the matrix at row %d, col %d\n", index[0], index[1]);
    }
}