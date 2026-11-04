// Q130: Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.

/*
Sample Test Cases:
Input 1:
Student 1 → Name: Asha, Roll: 101, Marks: 85; Student 2 → Name: Ravi, Roll: 102, Marks: 92
Output 1:
Name: Asha | Roll: 101 | Marks: 85
Name: Ravi | Roll: 102 | Marks: 92

*/

#include <stdio.h>

int main() {
      FILE *fp;
    int n, roll, marks;
    char name[50];

    // Step 1: Write student records to file
    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("File could not be opened.\n");
        return 1;
    }

    scanf("%d", &n); // Kitne students ka data dalna hai

    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        scanf("%d", &roll);
        scanf("%d", &marks);

        fprintf(fp, "%s %d %d\n", name, roll, marks);
    }

    fclose(fp);

    // Step 2: Read student records from file and print
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("File could not be opened.\n");
        return 1;
    }

    while (fscanf(fp, "%s %d %d", name, &roll, &marks) == 3) {
        printf("Name: %s | Roll: %d | Marks: %d\n", name, roll, marks);
    }

    fclose(fp);

    return 0;
}