#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int enrolmentNumber;
    char name[50];
    float marks;
    int rank;
};

// Sorting comparator for marks
int compareByMarks(const void *a, const void *b) {
    return ((struct Student *)b)->marks - ((struct Student *)a)->marks;
}

// Sorting comparator for ranks
int compareByRank(const void *a, const void *b) {
    return ((struct Student *)a)->rank - ((struct Student *)b)->rank;
}

// Function to assign ranks
void assignRanks(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0 && students[i].marks == students[i - 1].marks) {
            students[i].rank = students[i - 1].rank; // Same rank for equal marks
        } else {
            students[i].rank = i + 1; // Assign rank based on position
        }
    }
}

// Function to display the students' details
void displayStudents(struct Student students[], int n) {
    printf("\nEnrolment Number\tName\t\tMarks\t\tRank\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t\t%-15s\t%.2f\t\t%d\n",
               students[i].enrolmentNumber, students[i].name, students[i].marks, students[i].rank);
    }
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enrolment Number: ");
        scanf("%d", &students[i].enrolmentNumber);
        printf("Name: ");
        scanf(" %[^\n]%*c", students[i].name); // Read string with spaces
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Sort by marks and assign ranks
    qsort(students, n, sizeof(struct Student), compareByMarks);
    assignRanks(students, n);

    // Sort by rank and display students
    qsort(students, n, sizeof(struct Student), compareByRank);
    displayStudents(students, n);

    free(students);
    return 0;
}
