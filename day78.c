// Q128: Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters.

/*
Sample Test Cases:
Input 1:
File: text.txt (Content: Welcome to C language)
Output 1:
Vowels: 8
Consonants: 10

*/

#include <stdio.h>

int main() {
      FILE *fp;
    char ch;
    int vowels = 0, consonants = 0;

    fp = fopen("text.txt", "r");

    if (fp == NULL) {
        printf("File could not be opened.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        // Capital letter ko small letter bana lete hain check karne ke liye
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32;
        }

        // Sirf alphabets check karenge (digits aur special characters ignore honge)
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    fclose(fp);

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}