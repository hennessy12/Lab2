#include <stdio.h>

// Define the Student struct
struct Student {
    char name[50];
    int grades[3]; // Homework, Quiz, Exam
    float weighted_average;
};

// Function to calculate the weighted average
void calculate_weighted_average(struct Student *student, float weights[]) {
    float weighted_sum = 0.0;
    for (int i = 0; i < 3; i++) {
        weighted_sum += student->grades[i] * weights[i];
    }
    student->weighted_average = weighted_sum;
}

// Find the student with the highest average
struct Student* find_top_student(struct Student students[], int num_students) {
    struct Student* top = &students[0];
    for (int i = 1; i < num_students; i++) {
        if (students[i].weighted_average > top->weighted_average) {
            top = &students[i];
        }
    }
    return top;
}

int main() {
    int num_students = 3;
    struct Student students[num_students] = {
        {"Andy", {85, 90, 78}, 0.0},
        {"Randy", {88, 76, 92}, 0.0},
        {"Sandy", {70, 80, 75}, 0.0}
    };

    // Define grade weights
    float weights[] = {0.4, 0.3, 0.3}; // Homework: 40%, Quiz: 30%, Exam: 30%

    // Calculate weighted averages for each student
    for (int i = 0; i < num_students; i++) {
        calculate_weighted_average(&students[i], weights);
    }

    // Find the student with the highest average
    struct Student* top_student = find_top_student(students, num_students);

    // Print student details
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Grades: %d, %d, %d\n", students[i].grades[0], students[i].grades[1], students[i].grades[2]);
        printf("Weighted Average: %.2f\n\n", students[i].weighted_average);
    }

    printf("Top Student: %s\n", top_student->name);

    return 0;
}
