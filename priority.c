#include <stdio.h>
#include <stdlib.h> // For exit()

// Set the maximum size of the priority queue
#define MAX_SIZE 100

/**
 * @brief A struct to hold the data item and its priority.
 */
struct item {
    int value;
    int priority;
};
typedef struct item Node;
// --- Global Variables ---
Node pq[MAX_SIZE]; // Array to store the priority queue items
int size = 0;             // Current number of items in the queue

// --- Function Prototypes ---
void enqueue();
void dequeue();
void display();
int isEmpty();
int isFull();

/**
 * @brief Checks if the priority queue is full.
 */
int isFull() {
    return size == MAX_SIZE;
}

/**
 * @brief Checks if the priority queue is empty.
 */
int isEmpty() {
    return size == 0;
}

/**
 * @brief Adds an item to the queue based on its priority.
 * Items are stored in ascending order of priority (lowest at front).
 */
void enqueue() {
    if (isFull()) {
        printf("Priority Queue is full! Cannot enqueue.\n");
        return;
    }

    int value, priority;
    printf("Enter the value to enqueue: ");
    scanf("%d", &value);
    printf("Enter its priority (higher number = higher priority): ");
    scanf("%d", &priority);

    Node newItem;
    newItem.value = value;
    newItem.priority = priority;

    int i;

    // Find the correct position to insert the new item
    // We loop from the end backwards
    for (i = size - 1; i >= 0; i--) {
        // If the current item's priority is higher than the new item's,
        // shift the current item one position to the right
        if (pq[i].priority > priority){
            pq[i + 1] = pq[i];
        } else {
            // Found the correct spot (or the beginning)
            break;
        }
    }

    // Insert the new item at its correct, sorted position
    pq[i + 1] = newItem;
    size++; // Increment the size

    printf("\nEnqueued {value: %d, priority: %d} successfully.\n", value, priority);
}

/**
 * @brief Removes the item with the highest priority from the queue.
 * Since the array is sorted, this is the last item.
 */
void dequeue() {
    if (isEmpty()) {
        printf("Priority Queue is empty! Cannot dequeue.\n");
        return;
    }

    // The item with the highest priority is at the end of the array
    Node removedItem = pq[size - 1];
    
    // Simply decrement the size to "remove" the item (O(1) operation)
    size--;

    printf("\nDequeued {value: %d, priority: %d}.\n", removedItem.value, removedItem.priority);
}

/**
 * @brief Displays all items in the priority queue.
 */
void display() {
    if (isEmpty()) {
        printf("The priority queue is empty.\n");
        return;
    }

    printf("\nPriority Queue (Lowest to Highest Priority):\n");
    printf("------------------------------------------\n");
    printf("(Index) -> (Value, Priority)\n");
    for (int i = 0; i < size; i++) {
        printf("[%d] -> (%d, %d)\n", i, pq[i].value, pq[i].priority);
    }
    printf("------------------------------------------\n");
}

/*
 * The main function provides the menu-driven interface.
 */
int main() {
    int choice;

    while (1) {
        printf("\n--- PRIORITY QUEUE MENU ---\n");
        printf("1. Enqueue (Add an item)\n");
        printf("2. Dequeue (Remove highest priority item)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("---------------------------\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}