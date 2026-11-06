// Q137: Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.

/*
Sample Test Cases:
Input 1:
GUEST
Output 1:
Welcome Guest!

*/
#include <stdio.h>
#include <string.h>

enum Role {
    ADMIN,
    USER,
    GUEST
};

int main() {
    char input[20];
    enum Role role;

    scanf("%s", input);

    if (strcmp(input, "ADMIN") == 0) {
        role = ADMIN;
    } else if (strcmp(input, "USER") == 0) {
        role = USER;
    } else if (strcmp(input, "GUEST") == 0) {
        role = GUEST;
    } else {
        printf("Invalid role\n");
        return 1;
    }

    if (role == ADMIN) {
        printf("Welcome Admin! Full access granted.\n");
    } else if (role == USER) {
        printf("Welcome User! Standard access granted.\n");
    } else if (role == GUEST) {
        printf("Welcome Guest!\n");
    }

    return 0;
}
