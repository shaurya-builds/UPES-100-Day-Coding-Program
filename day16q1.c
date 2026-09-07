//Q31: Write a program to take a number as input and print its equivalent binary representation.

/*
Sample Test Cases:
Input 1:
10
Output 1:
1010

Input 2:
7
Output 2:
111

*/
#include <stdio.h>

int main() {
    int n;
    long long binary = 0, place = 1;
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    while (n > 0) {
        int rem = n % 2;
        binary += rem * place;
        n /= 2;
        place *= 10;
    }

    printf("%lld\n", binary);
    return 0;
}