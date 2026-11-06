// Q136: Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.

/*
Sample Test Cases:
Input 1:
ADD 10 20
Output 1:
30

*/
#include <stdio.h>
#include <string.h>

enum Menu {
    ADD,
    SUBTRACT,
    MULTIPLY
};

int main() {
    char choiceStr[20];
    int a, b;
    enum Menu choice;

    scanf("%s", choiceStr);
    scanf("%d %d", &a, &b);

    if (strcmp(choiceStr, "ADD") == 0) {
        choice = ADD;
    } else if (strcmp(choiceStr, "SUBTRACT") == 0) {
        choice = SUBTRACT;
    } else if (strcmp(choiceStr, "MULTIPLY") == 0) {
        choice = MULTIPLY;
    } else {
        printf("Invalid choice\n");
        return 1;
    }

    switch (choice) {
        case ADD:
            printf("%d\n", a + b);
            break;
        case SUBTRACT:
            printf("%d\n", a - b);
            break;
        case MULTIPLY:
            printf("%d\n", a * b);
            break;
    }

    return 0;
}
