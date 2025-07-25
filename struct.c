#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Define Student structure
struct Student {
    int roll_no;
    char name[50];
    float marks;
};

// Function to add student
void addStudent(struct Student* s, int index) {
    printf("Enter Roll Number: ");
    scanf("%d", &s[index].roll_no);
    getchar();  // clear input buffer

    printf("Enter Name: ");
    fgets(s[index].name, sizeof(s[index].name), stdin);
    s[index].name[strcspn(s[index].name, "\n")] = '\0'; // remove newline

    printf("Enter Marks: ");
    scanf("%f", &s[index].marks);
}

// Function to display all students
void displayStudents(struct Student* s, int count) {
    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll No : %d\n", s[i].roll_no);
        printf("Name    : %s\n", s[i].name);
        printf("Marks   : %.2f\n", s[i].marks);
        printf("---------------------\n");
    }
}

int main() {
    struct Student students[MAX];
    int count = 0, choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= MAX) {
                    printf("Student limit reached.\n");
                } else {
                    addStudent(students, count);
                    count++;
                }
                break;

            case 2:
                if (count == 0) {
                    printf("No student data available.\n");
                } else {
                    displayStudents(students, count);
                }
                break;

            case 3:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
