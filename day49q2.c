// Q98: Print initials of a name with the surname displayed in full.

/*
Sample Test Cases:
Input 1:
John David Doe
Output 1:
J.D. Doe

*/

#include <stdio.h>

int main() {
    char name[100];
    fgets(name, sizeof(name), stdin);

    int lastSpace = -1;
    for (int i = 0; name[i] != '\0' && name[i] != '\n'; i++) {
        if (name[i] == ' ') {
            lastSpace = i;
        }
    }

    for (int i = 0; i < lastSpace; i++) {
        if (i == 0 && name[i] != ' ') {
            printf("%c.", name[i]);
        } else if (name[i] == ' ' && name[i + 1] != ' ') {
            printf("%c.", name[i + 1]);
        }
    }

    if (lastSpace != -1) {
        printf(" ");
        for (int i = lastSpace + 1; name[i] != '\0' && name[i] != '\n'; i++) {
            printf("%c", name[i]);
        }
    } else {
        for (int i = 0; name[i] != '\0' && name[i] != '\n'; i++) {
            printf("%c", name[i]);
        }
    }
    printf("\n");

    return 0;
}
