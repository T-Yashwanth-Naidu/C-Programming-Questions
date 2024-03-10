/*Create a program that checks if a string is a palindrome using pointers.

WTD: Use two pointers, one at the start and the other at the end. Traverse inward, comparing characters.

(e.g.: I/P: "radar" ,O/P: True)*/

#include<stdio.h>
#include<string.h>

int checkPalindrome(char *str) {
    char *first = str;
    char *last = str + (strlen(str) - 1);
    
    while(first<last){
        if(*first != *last){
            return 0;
        }
        first++;
        last--;
    }
    return 1;
}

int main(){
    
    char str[] = "radar";
    
    if(checkPalindrome(str)){
        printf("True");
    }else{
        printf("False");
    }    
    return 0;
}