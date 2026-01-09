#include <stdio.h>
#include <stdlib.h> // For malloc(), free(), and exit()

// --- Structure Definition ---

struct node {
    int data;
    struct node* next;
};

// Use typedef to create an alias 'Node' for 'struct node*'
typedef struct node* Node;

// Global pointers for the queue
Node front = NULL; // Points to the first node in line
Node rear = NULL;  // Points to the last node in line

// --- Function Prototypes ---
void enqueue();
void dequeue();
void peek();
void display();
void isEmpty();
void clearInputBuffer(); // Helper for robust input

/**
 * @brief Main function to drive the menu
 */
int main() {
    int choice;
    while (1) { // Infinite loop for the menu
        printf("\n\n--- Queue Operations (using Linked List) ---\n");
        printf("1. Enqueue (Insert at Rear)\n");
        printf("2. Dequeue (Delete from Front)\n");
        printf("3. Peek (View Front Element)\n");
        printf("4. Display Queue\n");
        printf("5. Check if Empty\n");
        printf("6. Exit\n");
        printf("------------------------------------------\n");
        printf("Enter your choice: ");
        
        // Robust input check
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer(); // Clear the trailing newline

        switch (choice) {
            case 1: enqueue();   break;
            case 2: dequeue();   break;
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

// --- Helper Function ---

/**
 * @brief Reads and discards all characters from the input stream
 * until a newline or EOF is encountered.
 */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// --- Queue Function Implementations ---

/**
 * @brief 1. Inserts a new element at the rear of the queue.
 */
void enqueue() {
    // 1. Create the new node
    Node newNode = (Node)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Queue Overflow! (Memory allocation failed)\n");
        return;
    }

    // 2. Get data for the node
    printf("  Enter the integer data to enqueue: ");
    while (scanf("%d", &newNode->data) != 1) {
        printf("Invalid input! Please enter an integer: ");
        clearInputBuffer();
    }
    clearInputBuffer(); // Clear trailing '\n'
    newNode->next = NULL;

    // 3. Link the new node to the queue
    
    // Case 1: The queue is currently empty
    if(rear == NULL) {
        front = newNode; // The new node is both the front and the rear
        rear = newNode;
    } 
    // Case 2: The queue is not empty
    else{
        rear->next = newNode; // Point the old rear to the new node
        rear = newNode;       // Make the new node the new rear
    }
    
    printf("[SUCCESS] %d has been added to the queue.\n", newNode->data);
}

/**
 * @brief 2. Deletes the element from the front of the queue.
 */
void dequeue(){
    // Check for "Queue Underflow"
    if (front == NULL) {
        printf("Queue Underflow! (List is empty)\n");
        return;
    }

    // 1. Store the node to be deleted in 'temp'
    Node temp = front;
    int dequeued_data = temp->data;

    // 2. Move the 'front' pointer to the next node
    front = front->next;

    // 3. Special Case: If the list is now empty...
    // We must also update 'rear' to be NULL.
    if (front == NULL) {
        rear = NULL;
    }

    // 4. Free the old front node
    free(temp);

    printf("[SUCCESS] %d has been dequeued from the queue.\n", dequeued_data);
}

/**
 * @brief 3. Displays the front element without removing it.
 */
void peek() {
    // Check if the queue is empty
    if (front == NULL) {
        printf("Queue is empty. Nothing to peek.\n");
        return;
    }
    
    printf("The element at the front is: %d\n", front->data);
}

/**
 * @brief 4. Displays all elements in the queue from front to rear.
 */
void display() {
    // Check if the queue is empty
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Node temp = front;
    printf("Queue (Front to Rear):\n");
    printf("FRONT -> ");
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL (Rear)\n");
}

/**
 * @brief 5. Checks if the queue is empty.
 */
void isEmpty() {
    if (front == NULL) {
        printf("Queue is EMPTY.\n");
    } else {
        printf("Queue is NOT empty.\n");
    }
}