#include <stdio.h>

// 1. Define the structure (the blueprint) for a student
struct Student {
    int roll_no;
    char name[100]; // A string is a character array
    float marks;
    char grade;
};

int main() {
    // Create an array of Student structures. 
    // We can store up to 100 students.
    struct Student s[100]; 
    
    int n, i;
    int found = 0; // A flag to check if we find any matching students

    // --- Input Section ---

    printf("Enter the number of students (n): ");
    scanf("%d", &n);

    // Check for a valid number
    if (n <= 0 || n > 100) {
        printf("Invalid number of students. Please enter a value between 1 and 100.\n");
        return 1; // Exit the program
    }

    printf("\n--- Enter Details for %d Students ---\n", n);
    for (i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);

        printf("  Enter Roll No: ");
        scanf("%d", &s[i].roll_no);

        printf("  Enter Name (one word): ");
        scanf("%s", s[i].name); // Note: scanf("%s") only reads a single word

        printf("  Enter Marks: ");
        scanf("%f", &s[i].marks);

        printf("  Enter Grade (A, B, C...): ");
        // Note the space before %c. This is important!
        // It tells scanf to skip any leftover newline/whitespace
        // from the previous 'scanf' (for marks).
        scanf(" %c", &s[i].grade); 
        
        printf("\n"); // Add a blank line for readability
    }
    
    // --- Output Section ---
    printf("--------------------------------------\n");
    printf("Students with Marks >= 70:\n");
    printf("--------------------------------------\n");
    // Loop through the array again to check the marks
    for (i = 0; i < n; i++) {
        // Check if the current student's marks are 70 or higher
        if (s[i].marks >= 70.0) {
            printf("%s\n", s[i].name);
            found = 1; // We found at least one student
        }
    }
    // If no students were found, print a message
    if (found == 0) {
        printf("No students found with marks 70 or above.\n");
    }
    return 0;
}