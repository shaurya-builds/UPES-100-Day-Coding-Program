//Q94: Find the longest word in a sentence.

/*
Sample Test Cases:
Input 1:
I love programming
Output 1:
programming

*/

#include <stdio.h>

int main() {
    char str[200];
    fgets(str, sizeof(str), stdin);

    int maxLen = 0, currLen = 0;
    int maxStart = 0, currStart = 0;

    for (int i = 0; ; i++) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\0') {
            if (currLen == 0) {
                currStart = i;
            }
            currLen++;
        } else {
            if (currLen > maxLen) {
                maxLen = currLen;
                maxStart = currStart;
            }
            currLen = 0;
            if (str[i] == '\0' || str[i] == '\n') {
                break;
            }
        }
    }

    for (int i = 0; i < maxLen; i++) {
        printf("%c", str[maxStart + i]);
    }
    printf("\n");

    return 0;
}