#include <stdio.h>
#include <stdlib.h> // Needed for malloc() and free()
#include <stdbool.h> // Needed for the 'bool' type in display

// --- Structure Definitions ---

// A node represents one term of the polynomial (e.g., 5x^2)
struct node {
    int coef; // The coefficient (e.g., 5)
    int expo; // The exponent (e.g., 2)
    struct node* next;
};

// Use typedef for a cleaner alias
typedef struct node* Node;

// Global 'start' pointer, initialized to NULL (empty polynomial)
Node start = NULL;

// --- Function Prototypes ---
void insertTerm(int c, int e);
void displayPoly();
void freeList();

/**
 * @brief Main function to drive the program
 */
int main() {
    int n, i;
    int c, e;

    printf("Enter the number of terms in the polynomial:\n");
    scanf("%d", &n);

    // Read each term and insert it into the linked list
    for (i = 0; i < n; i++) {
        printf("\n--- Term %d ---\n", i + 1);
        printf("Enter the coefficient: ");
        scanf("%d", &c);
        printf("Enter the exponent: ");
        scanf("%d", &e);
        insertTerm(c, e);
    }

    // Display the final polynomial
    printf("\nThe polynomial is:\n");
    displayPoly();

    // Free all dynamically allocated memory before exiting
    freeList();
    
    return 0;
}

/**
 * @brief Creates a new term (node) and inserts it at the end of the list.
 * @param c The coefficient of the term.
 * @param e The exponent of the term.
 */
void insertTerm(int c, int e) {
    // 1. Create the new node (term)
    Node newNode = (Node)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->coef = c;
    newNode->expo = e;
    newNode->next = NULL;

    // 2. Insert the node into the list
    
    // If the list is empty, the new node becomes the first node
    if (start == NULL) {
        start = newNode;
        return;
    }

    // Otherwise, traverse to the end of the list
    Node temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Link the last node to the new node
    temp->next = newNode;
}

/**
 * @brief Displays the polynomial in a standard mathematical format.
 */
void displayPoly() {
    if (start == NULL) {
        printf("0 (Polynomial is empty)\n");
        return;
    }

    Node temp = start;
    bool isFirstTerm = true; // Flag to handle the sign of the first term

    while (temp != NULL) {
        // --- Handle the sign ---
        if (!isFirstTerm) {
            if (temp->coef > 0) {
                printf(" + ");
            } else {
                printf(" - "); // Print space-minus-space for negative terms
            }
        } else if (temp->coef < 0) {
            printf("-"); // Only print minus for a negative first term
        }
        
        int abs_coef = abs(temp->coef); // Use absolute value for printing

        // --- Handle the coefficient ---
        // Don't print coefficient if it's 1 and there's an exponent
        if (abs_coef != 1 || temp->expo == 0) {
            printf("%d", abs_coef);
        }

        // --- Handle the exponent (variable 'x') ---
        if (temp->expo > 0) {
            printf("x");
            if (temp->expo > 1) {
                printf("^%d", temp->expo);
            }
        }if(temp->expo<0){
            printf("/X^%d",abs(temp->expo));
        }
     
        isFirstTerm = false;
        temp = temp->next;
    }
    printf("\n");
}
/**
 * @brief Frees all memory allocated for the linked list to prevent leaks.
 */
void freeList() {
    Node current = start;
    Node nextNode;
    
    while (current != NULL) {
        nextNode = current->next; // Store the next node
        free(current);            // Free the current one
        current = nextNode;       // Move to the next one
    }
    
    start = NULL; // Reset the start pointer
}