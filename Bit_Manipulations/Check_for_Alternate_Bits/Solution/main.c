/* Check for Alternate Bits. Write a function to check if bits in a given number are in alternate pattern.

WTD: Given an integer, check if the bits in its binary representation alternate between 0 and 1. Use bitwise operations to traverse the bits and perform the check.

(e.g.: I/P:  0b10101010; O/P: True) */

#include <stdio.h>
#include <stdbool.h>

bool checkAltBits(int a)
{
    //eg - 10101010 & (01010101) = 0 
    // returns !(0) , i.e 1 (True)
    return !(a & (a>>1)); 
}

int main()
{
    int a; 
    scanf("%u",&a); //inputting unsigned integer
    
    if(checkAltBits(a))
        printf("True");
    else 
        printf("False");

    return 0;
}