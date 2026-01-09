#include <stdio.h>
#include <stdlib.h> // For malloc(), free(), and exit()

// --- Structure Definition ---

struct node {
    int data;
    struct node* next;
};

// Use typedef to create an alias 'Node' for 'struct node*'
typedef struct node* Node;

// Global 'top' pointer, initialized to NULL (empty stack)
Node top = NULL;

// --- Function Prototypes ---
void push();
void pop();
void peek();
void display();
void isEmpty();

/**
 * @brief Main function to drive the menu
 */
int main() {
    int choice;
    while (1) { // Infinite loop for the menu
        printf("\n\n--- Stack Operations (using Linked List) ---\n");
        printf("1. Push (Insert at Top)\n");
        printf("2. Pop (Delete from Top)\n");
        printf("3. Peek (View Top Element)\n");
        printf("4. Display Stack\n");
        printf("5. Check if Empty\n");
        printf("6. Exit\n");
        printf("---------------------------------------------\n");
        printf("Enter your choice: ");
        
        // This scanf is now UNSAFE. Entering a letter here will cause an infinite loop.
        scanf("%d", &choice);

        switch (choice) {
            case 1: push();      break;
            case 2: pop();       break;
            case 3: peek();      break;
            case 4: display();   break;
            case 5: isEmpty();   break;
            case 6: 
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// --- Stack Function Implementations ---

/**
 * @brief 1. Pushes a new element onto the top of the stack.
 */
void push() {
    // 1. Create the new node
    Node newNode = (Node)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Stack Overflow! (Memory allocation failed)\n");
        return;
    }

    // 2. Get data for the node
    printf("  Enter the integer data to push: ");
    
    // This scanf is also UNSAFE.
    scanf("%d", &newNode->data);

    // 3. Link the new node to the list
    newNode->next = top; // Point the new node to the old top
    top = newNode;       // Make the new node the new top
    
    printf("[SUCCESS] %d has been pushed onto the stack.\n", newNode->data);
}

/**
 * @brief 2. Pops (removes) the top element from the stack.
 */
void pop() {
    // Check for "Stack Underflow"
    if (top == NULL) {
        printf("Stack Underflow! (List is empty)\n");
        return;
    }
    // 1. Store the node to be deleted in 'temp'
    Node temp = top;
    int popped_data = temp->data;
    // 2. Move the 'top' pointer to the next node
    top = top->next;
    // 3. Free the old top node
    free(temp);
    printf("[SUCCESS] %d has been popped from the stack.\n", popped_data);
}

/**
 * @brief 3. Displays the top element without removing it.
 */
void peek() {
    // Check if the stack is empty
    if (top == NULL) {
        printf("Stack is empty. Nothing to peek.\n");
        return;
    }
    
    printf("The element at the top is: %d\n", top->data);
}

/**
 * @brief 4. Displays all elements in the stack from top to bottom.
 */
void display() {
    // Check if the stack is empty
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    Node temp = top;
    printf("Stack (Top to Bottom):\n");
    printf("TOP -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL (Bottom)\n");
}

/**
 * @brief 5. Checks if the stack is empty.
 */
void isEmpty() {
    if (top == NULL) {
        printf("Stack is EMPTY.\n");
    } else {
        printf("Stack is NOT empty.\n");
    }
}