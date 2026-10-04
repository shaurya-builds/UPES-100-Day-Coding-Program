//Q79: Perform diagonal traversal of a matrix.

/*
Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 9
Output 1:
1 2 4 7 5 3 6 8 9

*/
#include <stdio.h>

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int row = 0, col = 0;
    int goingUp = 1;
    int total = rows * cols;

    for (int count = 0; count < total; count++) {
        printf("%d", matrix[row][col]);
        if (count < total - 1) {
            printf(" ");
        }

        if (goingUp) {
            if (col == cols - 1) {
                row++;
                goingUp = 0;
            } else if (row == 0) {
                col++;
                goingUp = 0;
            } else {
                row--;
                col++;
            }
        } else {
            if (row == rows - 1) {
                col++;
                goingUp = 1;
            } else if (col == 0) {
                row++;
                goingUp = 1;
            } else {
                row++;
                col--;
            }
        }
    }
    printf("\n");

    return 0;
}