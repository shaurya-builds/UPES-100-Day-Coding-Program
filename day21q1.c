//Q41: Write a program to swap the first and last digit of a number.

/*
Sample Test Cases:
Input 1:
1234
Output 1:
4231

Input 2:
1001
Output 2:
1001

*/
#include <stdio.h>

int main() {
    int n, firstDigit, lastDigit, digits = 0, powerOf10 = 1;
    scanf("%d", &n);

    if (n < 10) {
        printf("%d\n", n);
        return 0;
    }

    lastDigit = n % 10;

    int temp = n;
    while (temp >= 10) {
        temp /= 10;
        powerOf10 *= 10;
    }
    firstDigit = temp;

    int middlePart = (n % powerOf10) / 10;
    int swapped = (lastDigit * powerOf10) + (middlePart * 10) + firstDigit;

    printf("%d\n", swapped);
    return 0;
}