/* Design a program to concatenate two strings without using standard library functions, only pointers.

WTD: Traverse the first string till the end and then copy the second string from that point.

(e.g.: I/P: char *str1 = "Good ", *str2 = "Morning" ,O/P: "Good Morning" )*/

#include<stdio.h>

void concatenate_strs(char *str1, char *str2){
    while(*str1 != '\0'){
        str1++;
    }

    while(*str2 != '\0'){
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

int main() {
    
    char str1[] = "Good ";
    char str2[] = "Morning";

    concatenate_strs(str1, str2);

    printf("%s",str1);

    return 0;
}