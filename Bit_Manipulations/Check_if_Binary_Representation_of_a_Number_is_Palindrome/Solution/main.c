#include <stdio.h>

int reverse(int n){
    int rev = 0;
    while(n > 0){
        rev <<=  1;
        rev |= (n&1);
        n >>= 1;
    }
    return rev;
}

int main(){
    int a;
    scanf("%u", &a);
    int rev = reverse(a);
    if(rev == a){
        printf("The number %u is a palindrome\n", a);
    }
    else{
        printf("The number %u is not a palindrome\n" ,a);
    }
    return 0;
}

