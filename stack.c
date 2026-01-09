#include <stdio.h>
#include <stdlib.h> // Required for the exit() function

 // Define the maximum size of the stack
#define MAX_SIZE 100

// --- Global Variables ---
// We declare the stack and 'top' variable globally so all functions can access them.
int stack[MAX_SIZE];
int top = -1; // -1 signifies that the stack is currently empty

// --- Function Prototypes ---
// Declare the functions before main() so it knows they exist.
void push();
void pop();
void display();

/*
 * The main function provides the menu-driven interface.
 * It runs in an infinite loop until the user chooses to exit.
 */
int main() {
    int choice;

    // The while(1) creates an infinite loop for the menu.
    // The loop only breaks when the user selects '4. Exit'.
    while (1) {
        // Print the menu
        printf("\n--- STACK OPERATIONS MENU ---\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Display Stack Contents\n");
        printf("4. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Use a switch-case to perform the action based on user's choice
        switch (choice) {
            case 1:
                push();     // Call the push function
                break;
            case 2:
                pop();      // Call the pop function
                break;
            case 3:
                display();  // Call the display function
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);    // Terminate the program
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}

/**
 * @brief Pushes an element onto the top of the stack.
 * Checks for Stack Overflow condition.
 */
void push() {
    int element;

    // Check if the stack is full (Stack Overflow)
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow! Cannot push element.\n");
    } else {
        // If not full, get the element from the user
        printf("Enter the element to push: ");
        scanf("%d", &element);
        
        // 1. Increment the 'top' pointer
        top = top + 1;
        // 2. Store the element at the new 'top' position
        stack[top] = element;
        
        printf("%d pushed to stack.\n", element);
    }
}

/**
 * @brief Pops (removes) an element from the top of the stack.
 * Checks for Stack Underflow condition.
 */
void pop() {
    // Check if the stack is empty (Stack Underflow)
    if (top == -1) {
        printf("Stack Underflow! The stack is empty.\n");
    } else {
        // 1. Get the element that is about to be popped (for display)
        int poppedElement = stack[top];
        
        // 2. Decrement the 'top' pointer
        top = top - 1;
        
        printf("Popped element is %d.\n", poppedElement);
    }
}

/**
 * @brief Displays all the elements currently in the stack
 * from top to bottom (LIFO order).
 * Checks if the stack is empty.
 */
void display() {
    int i; // Loop variable

    // Check if the stack is empty
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Elements in the stack (from top to bottom):\n");
        // Loop from the top element down to the bottom (index 0)
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
/*#include <stdio.h>
#include <stdlib.h> // Required for malloc, free, and exit

// --- Global Variables ---
// <<< CHANGED
int *stack = NULL;  // Pointer to hold the base address of our stack
int max_size;       // Will hold the user-defined size
int top = -1;       // -1 signifies that the stack is currently empty

// --- Function Prototypes ---
// <<< CHANGED: Added create()
void create();
void push();
void pop();
void display();


void create() {
    printf("Enter the desired size of the stack: ");
    scanf("%d", &max_size);

    // Validate the input
    if (max_size <= 0) {
        printf("Invalid size. Program will exit.\n");
        exit(1);
    }
    
    // Allocate memory using malloc
    // We use (int*) to cast the void* pointer returned by malloc
    stack = (int*)malloc(max_size * sizeof(int));

    // Check if memory allocation failed
    if (stack == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    printf("Stack of size %d created successfully.\n", max_size);
}


int main() {
    int choice;

    // <<< CHANGED: Call create() once before the menu loop starts
    create();

    // The while(1) creates an infinite loop for the menu.
    while (1) {
        // Print the menu
        printf("\n--- STACK OPERATIONS MENU ---\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Display Stack Contents\n");
        printf("4. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        
        // Add error checking for scanf
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue; // Skip the rest of the loop
        }

        // Use a switch-case to perform the action
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                // <<< CHANGED: Free the allocated memory before exiting
                if (stack != NULL) { // Good practice to check
                    free(stack);
                }
                exit(0); // Terminate the program
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0; // This line is technically unreachable due to exit(0)
}


void push() {
    int element;

    // <<< CHANGED: Check against the 'max_size' variable
    if (top == max_size - 1) {
        printf("Stack Overflow! Cannot push element.\n");
    } else {
        printf("Enter the element to push: ");
        
        // <<< ADDED: Error check for the element input
        if (scanf("%d", &element) != 1) {
             printf("Invalid input. Please enter a number.\n");
             while (getchar() != '\n'); // Clear the input buffer
             return; // Go back to menu
        }

        top = top + 1;
        stack[top] = element;
        
        printf("%d pushed to stack.\n", element);
    }
}


void pop() {
    // <<< NO CHANGE NEEDED: This logic is perfect.
    if (top == -1) {
        printf("Stack Underflow! The stack is empty.\n");
    } else {
        int poppedElement = stack[top];
        top = top - 1;
        printf("Popped element is %d.\n", poppedElement);
    }
}


void display() {
    int i; 

    // <<< NO CHANGE NEEDED: This logic is perfect.
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Elements in the stack (from top to bottom):\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}*/