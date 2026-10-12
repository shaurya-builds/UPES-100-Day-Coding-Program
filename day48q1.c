//Q95: Check if one string is a rotation of another.

/*
Sample Test Cases:
Input 1:
abcde
deabc
Output 1:
Rotation

Input 2:
abc
acb
Output 2:
Not rotation

*/

#include <stdio.h>

int main() {
    char str1[100], str2[100];
    scanf("%s", str1);
    scanf("%s", str2);

    int len1 = 0, len2 = 0;
    while (str1[len1] != '\0') len1++;
    while (str2[len2] != '\0') len2++;

    if (len1 != len2) {
        printf("Not rotation\n");
        return 0;
    }

    int isRotation = 0;
    for (int shift = 0; shift < len1; shift++) {
        int match = 1;
        for (int i = 0; i < len1; i++) {
            if (str1[(shift + i) % len1] != str2[i]) {
                match = 0;
                break;
            }
        }
        if (match) {
            isRotation = 1;
            break;
        }
    }

    if (isRotation) {
        printf("Rotation\n");
    } else {
        printf("Not rotation\n");
    }

    return 0;
}
