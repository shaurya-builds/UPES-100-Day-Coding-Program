//Q93: Check if two strings are anagrams of each other.

/*
Sample Test Cases:
Input 1:
listen
silent
Output 1:
Anagrams

Input 2:
hello
world
Output 2:
Not anagrams

*/
#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int count[26] = {0};

    scanf("%s", str1);
    scanf("%s", str2);

    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            count[str1[i] - 'a']++;
        } else if (str1[i] >= 'A' && str1[i] <= 'Z') {
            count[str1[i] - 'A']++;
        }
    }

    for (int i = 0; str2[i] != '\0'; i++) {
        if (str2[i] >= 'a' && str2[i] <= 'z') {
            count[str2[i] - 'a']--;
        } else if (str2[i] >= 'A' && str2[i] <= 'Z') {
            count[str2[i] - 'A']--;
        }
    }

    int isAnagram = 1;
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            isAnagram = 0;
            break;
        }
    }

    if (isAnagram) {
        printf("Anagrams\n");
    } else {
        printf("Not anagrams\n");
    }

    return 0;
}