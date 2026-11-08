// Q140: Define a struct with enum Gender and print person's gender.

/*
Sample Test Cases:
Input 1:
Gender=MALE
Output 1:
Male

*/
#include <stdio.h>
#include <string.h>

enum Gender {
    MALE,
    FEMALE,
    OTHER
};

struct Person {
    enum Gender gender;
};

int main() {
    char input[30];
    struct Person p;

    scanf("%s", input);

    if (strcmp(input, "Gender=MALE") == 0 || strcmp(input, "MALE") == 0) {
        p.gender = MALE;
    } else if (strcmp(input, "Gender=FEMALE") == 0 || strcmp(input, "FEMALE") == 0) {
        p.gender = FEMALE;
    } else if (strcmp(input, "Gender=OTHER") == 0 || strcmp(input, "OTHER") == 0) {
        p.gender = OTHER;
    } else {
        printf("Invalid input\n");
        return 1;
    }

    if (p.gender == MALE) {
        printf("Male\n");
    } else if (p.gender == FEMALE) {
        printf("Female\n");
    } else {
        printf("Other\n");
    }

    return 0;
}
