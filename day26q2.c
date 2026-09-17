#include <stdio.h>

int main() {
    int groups[] = {1, 3, 5, 3, 1};
    int numGroups = 5;

    for (int i = 0; i < numGroups; i++) {
        for (int j = 0; j < groups[i]; j++) {
            printf("*\n");
        }
        if (i < numGroups - 1) {
            printf("\n");
        }
    }

    return 0;
}