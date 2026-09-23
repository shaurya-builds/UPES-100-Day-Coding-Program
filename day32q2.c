//Q64: Find the digit that occurs the most times in an integer number.

/*
Sample Test Cases:
Input 1:
112233
Output 1:
1

Input 2:
887799
Output 2:
7

*/
#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    if (n < 0) {
        n = -n;
    }

    int freq[10] = {0};

    if (n == 0) {
        freq[0] = 1;
    } else {
        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }
    }

    int maxFreq = -1, resultDigit = 0;
    for (int i = 0; i <= 9; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            resultDigit = i;
        }
    }

    printf("%d\n", resultDigit);
    return 0;
}