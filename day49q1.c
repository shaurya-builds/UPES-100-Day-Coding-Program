//Q97: Print the initials of a name.

/*
Sample Test Cases:
Input 1:
John Doe
Output 1:
J.D.

*/
#include <stdio.h>

int main() {
    char name[100];
    fgets(name, sizeof(name), stdin);

    for (int i = 0; name[i] != '\0' && name[i] != '\n'; i++) {
        if (i == 0 && name[i] != ' ') {
            printf("%c.", name[i]);
        } else if (name[i] == ' ' && name[i + 1] != ' ' && name[i + 1] != '\0' && name[i + 1] != '\n') {
            printf("%c.", name[i + 1]);
        }
    }
    printf("\n");

    return 0;
}