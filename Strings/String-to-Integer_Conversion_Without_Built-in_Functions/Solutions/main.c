/* Problem: Convert a string to its integer representation without using any built-in functions.
WTD: Transform a given string of numeric characters into its corresponding integer representation without relying on built-in methods.
e.g.: I/P: "1234", O/P: 1234 */

#include<stdio.h>

//function to convert string to integer
int strToInt(char *str, int num){
    while(*str != '\0'){
        num = num * 10 + (*str - 48);   // convertint each string character to int and storing it in num
        str++;
    }
    return num; // returning the int value
}

int main(){

    char *str = "1234";
    int res = 0, num = 0;

    res = strToInt(str,num);

    printf("The converted result is: %d",res);

    return 0;
}