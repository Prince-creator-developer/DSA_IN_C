/* * Program to Design, Develop and Implement a Max Heap 
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int heap[MAX_SIZE];
int n = 0; // Current number of elements

// Function to insert an element into the Max Heap
void insert(int item) {
    if (n == MAX_SIZE) {
        printf("Heap is Full!\n");
        return;
    }
    
    n++;
    int i = n;
    // Heapify Up
    while (i > 1 && item > heap[i / 2]) {
        heap[i] = heap[i / 2];
        i = i / 2;
    }
    heap[i] = item;
    printf("Inserted %d\n", item);
}

// Function to display the Heap
void display() {
    if (n == 0) {
        printf("Heap is Empty.\n");
        return;
    }
    printf("Max Heap elements: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;
    
    while (1) {
        printf("\n--- MAX HEAP MENU ---\n");
        printf("1. Insert\n2. Display\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}