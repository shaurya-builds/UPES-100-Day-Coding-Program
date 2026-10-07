//Q85: Reverse a string.

/*
Sample Test Cases:
Input 1:
abcd
Output 1:
dcba

*/
#include <stdio.h>

int main() {
    char str[100];
    scanf("%s", str);

    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    int start = 0, end = len - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    printf("%s\n", str);

    return 0;
}
