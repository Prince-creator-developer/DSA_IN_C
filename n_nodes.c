#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()

// 1. Define the structure for a node
struct node {
    int data;
    struct node *next;
};

// Function to display the linked list
void displayList(struct node *head) {
    struct node *temp = head;
    
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    // Note: The list will appear in reverse order of input
    printf("Created List (in reverse order of input): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free all allocated memory
void freeList(struct node *head) {
    struct node *current = head;
    struct node *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int n, i, data;
    
    // We only need the head pointer for this method
    struct node *head = NULL; 
    
    // --- Ask user for the number of nodes ---
    printf("Enter the total number of nodes you want to create: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("No nodes to create. Exiting.\n");
        return 0;
    }

    printf("\nEnter data (note: each new node is added to the front):\n");

    // --- Loop 'n' times to create nodes ---
    for (i = 0; i < n; i++) {
        
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        // 1. Create the new node
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        
        if (newNode == NULL) {
            printf("Error: Memory allocation failed!\n");
            freeList(head);
            return 1;
        }

        // 2. Assign data
        newNode->data = data;

        // --- This is the "Insert at Front" logic ---
        
        // 3. Point the new node's 'next' to the current head
        newNode->next = head;

        // 4. Move the 'head' to point to the new node
        head = newNode;
        // --- End of Insert at Front logic ---
    }

    printf("\nSuccessfully created %d nodes.\n", n);

    // --- Display the final list ---
    displayList(head);
    
    // --- Free all the allocated memory ---
    freeList(head);
    printf("All memory has been freed.\n");

    return 0;
}