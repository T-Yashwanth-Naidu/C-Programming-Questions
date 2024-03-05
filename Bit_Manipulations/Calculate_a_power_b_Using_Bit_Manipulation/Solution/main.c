/*Write a function to calculate  a^b Using Bit Manipulation :

WTD: Given two integers a and b, calculate a^b using bitwise operations. Avoid using the power operator or any other arithmetic operations.

(e.g.: I/P: 2, 3; O/P: 8)*/

#include<stdio.h>

int main() 
{
    int a, b, result=1;
    
    scanf("%d, %d",&a,&b);
    
    while(b>0){
        if(b&1){
            result *= a;
        }
        a *= a;
        b >>= 1;
    }
    
    printf("%d",result);
    

    return 0;
}