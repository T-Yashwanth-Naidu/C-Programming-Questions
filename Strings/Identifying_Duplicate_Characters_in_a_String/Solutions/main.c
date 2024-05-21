/* Problem: Print Duplicate characters from a string.
WTD: Traverse through the given string and identify characters that appear more than once.
e.g.: I/P: "apple", O/P: "p" */

#include<stdio.h>
#include<stdbool.h>

void duplicateChar(char *str){

    int freq[26] = {0}; // to keep count of characters
    bool printed[26] = {false}; // to check if the character is already printed or not

    while(*str != '\0'){    //iterating through the string
        freq[*str-'a']++;   //count of each character

        if(freq[*str-'a']>=2 && !printed[*str-'a']){
            printf("%c ",*str);
            printed[*str-'a'] = true;   
        }
        str++;    
    }
}

int main(){

    char str[100];

    printf("Enter the string: ");
    scanf("%s", str);

    duplicateChar(str);

    return 0;
}