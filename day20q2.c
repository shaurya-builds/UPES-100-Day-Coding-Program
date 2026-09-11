//Q40: Write a program to find the 1’s complement of a binary number and print it.

/*
Sample Test Cases:
Input 1:
1010
Output 1:
0101

Input 2:
1111
Output 2:
0000

*/
#include <stdio.h>

int main() {
    long long bin, place = 1;
    int digits = 0;
    scanf("%lld", &bin);

    long long temp = bin;
    if (temp == 0) {
        digits = 1;
    } else {
        while (temp > 0) {
            digits++;
            temp /= 10;
        }
    }

    // Extract from most significant bit to preserve leading zeros
    long long div = 1;
    for (int i = 1; i < digits; i++) {
        div *= 10;
    }

    for (int i = 0; i < digits; i++) {
        int bit = (bin / div) % 10;
        printf("%d", bit == 0 ? 1 : 0);
        div /= 10;
    }
    printf("\n");

    return 0;
}