#include <stdio.h>
#include <stdlib.h> // For malloc and free

// --- Node structure (NO CHANGE) ---
typedef struct Node {
    int row;
    int col;
    int value;
    struct Node *next; 
} Node;

// --- create_node function (NO CHANGE) ---
Node* create_node(int r, int c, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    if (newNode == NULL) { 
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->row = r;
    newNode->col = c;
    newNode->value = val;
    newNode->next = NULL; 
    return newNode;
}

// --- insert function (NO CHANGE) ---
void insert(Node* rows[], int r, int c, int val, int numRows) {
    if (r >= numRows || val == 0) {
        return;
    }

    Node* newNode = create_node(r, c, val);
    Node* current = rows[r];
    Node* prev = NULL; 

    while (current != NULL && current->col < c) { 
        prev = current;
        current = current->next;
    }

    if (prev == NULL) { 
        newNode->next = rows[r];
        rows[r] = newNode;
    } else {
        newNode->next = current;
        prev->next = newNode;
    }
}

// --- displayTriplet function (NO CHANGE) ---
void displayTriplet(Node* rows[], int numRows) {
    printf("\nSparse Matrix (Triplet Form - Row, Col, Value):\n"); 
    for (int i = 0; i < numRows; ++i) {
        Node* current = rows[i];
        while (current != NULL) { 
            printf("%d\t%d\t%d\n", current->row, current->col, current->value); 
            current = current->next;
        }
    }
}

// --- displayMatrix function (NO CHANGE) ---
void displayMatrix(Node* rows[], int numRows, int numCols) {
    printf("\nSparse Matrix (Grid Format):\n"); 
    for (int i = 0; i < numRows; ++i) {
        Node* current = rows[i];
        for (int j = 0; j < numCols; ++j) {
            if (current != NULL && current->col == j) { 
                printf("%d\t", current->value); 
                current = current->next;
            } else {
                printf("0\t"); 
            }
        }
        printf("\n"); 
    }
}

// ======================================================
// --- Main Function (THIS IS THE MODIFIED PART) ---
// ======================================================
int main() {
    int numRows = 4;
    int numCols = 5;
    int value; // Variable to store user input

    // --- 1. Initialization (Same as before) ---
    Node* rows[numRows];
    for (int i = 0; i < numRows; ++i) {
        rows[i] = NULL; 
    }

    // --- 2. User Input (Replaces hard-coded inserts) ---
    printf("Enter the elements for the %d x %d matrix:\n", numRows, numCols);
    for (int i = 0; i < numRows; i++) {
        printf("--- Entering Row %d ---\n", i);
        for (int j = 0; j < numCols; j++) {
            printf("  Enter value for (%d, %d): ", i, j);
            scanf("%d", &value); // Read integer from user
            
            // Call insert. It will automatically ignore '0's.
            insert(rows, i, j, value, numRows);
        }
    }

    // --- 3. Display (Same as before) ---
    // We call displayMatrix first to confirm the input
    displayMatrix(rows, numRows, numCols);
    
    // This is what you requested:
    displayTriplet(rows, numRows);


    // --- 4. Cleanup (Same as before) ---
    for (int i = 0; i < numRows; ++i) {
        Node* current = rows[i];
        while (current != NULL) { 
            Node* temp = current;
            current = current->next;
            free(temp); 
        }
         rows[i] = NULL;    
    }

    return 0;
}  
