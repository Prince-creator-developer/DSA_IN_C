#include <stdio.h>
#include <stdlib.h> // For malloc(), free(), and exit()

// --- Structure Definitions ---

struct node {
    int data;
    struct node* next;
};

// Use typedef to create a simple alias 'Node' for 'struct node*'
typedef struct node* Node;

// Global 'start' pointer, initialized to NULL (empty list)
Node start = NULL;

// --- Function Prototypes ---
Node createNode();
int getCount();
void clearInputBuffer(); // Helper for robust input
void insertAtPos();
void deleteAtPos();
void insertAtMid();
void deleteAtMid();     // g. Added Function
void reverseList();     // h. Added Function
void insertInSorted();  // i. Added Function
void search();
void countNodes();
void sumAndAverage();
void display();

/**
 * @brief Main function to drive the menu
 */
int main() {
    int choice;
    while (1) { // Infinite loop for the menu
        printf("\n\n--- SLL Operations Menu (Integers) ---\n");
        printf(" 1. Insert at a given position\n");
        printf(" 2. Delete from a given position\n");
        printf(" 3. Insert at the middle position\n");
        printf(" 4. Delete from the middle position\n"); // Added
        printf(" 5. Reverse the list\n");                 // Added
        printf(" 6. Insert in a sorted list\n");        // Added
        printf(" 7. Search for a node\n");
        printf(" 8. Count the number of nodes\n");
        printf(" 9. Find Sum and Average of data\n");
        printf("10. Display the list\n");
        printf("11. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        
        // Robust input check
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer(); // Clear bad input
            continue;           // Restart the loop
        }
        clearInputBuffer(); // Clear the trailing newline

        switch (choice) {
            case 1: insertAtPos();     break;
            case 2: deleteAtPos();     break;
            case 3: insertAtMid();     break;
            case 4: deleteAtMid();     break; // Added
            case 5: reverseList();     break; // Added
            case 6: insertInSorted();  break; // Added
            case 7: search();          break;
            case 8: countNodes();      break;
            case 9: sumAndAverage();   break;
            case 10: display();        break;
            case 11: 
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// --- Helper Functions ---

/**
 * @brief Reads and discards all characters from the input stream
 * until a newline or EOF is encountered. Prevents infinite loops.
 */
    void clearInputBuffer() {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    /**
     * @brief Allocates memory for a new node and gets data from the user.
     * @return A pointer to the newly created node.
     */
    Node createNode() {
        Node newNode = (Node)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed (Heap Overflow)!\n");
            return NULL;
        }
        printf("  Enter the integer data: ");
        
        // Robust input check for the node's data
        while (scanf("%d", &newNode->data) != 1) {
            printf("Invalid input! Please enter an integer: ");
            clearInputBuffer();
        }
        clearInputBuffer(); // Clear the trailing newline
        
        newNode->next = NULL;
        return newNode;
    }

/**
 * @brief Helper function to get the current count of nodes.
 * @return The integer count of nodes.
 */
int getCount() {
    int count = 0;
    Node temp = start;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// --- Menu Function Implementations ---
// (insertAtPos, deleteAtPos, insertAtMid are unchanged and valid)

void insertAtPos() {
    int pos, i;
    int count = getCount();
    
    printf("Enter the position to insert (1 to %d): ", count + 1);
    scanf("%d", &pos);
    clearInputBuffer();

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position!\n");
        return;
    }

    Node newNode = createNode();
    if (newNode == NULL) return;

    if (pos == 1) {
        newNode->next = start;
        start = newNode;
    } else {
        Node prev = start;
        for (i = 1; i < pos - 1; i++) {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
    printf("[SUCCESS] Inserted %d at position %d.\n", newNode->data, pos);
}

void deleteAtPos() {
    int pos, i;
    int count = getCount();

    if (start == NULL) {
        printf("List is empty (Underflow)!\n");
        return;
    }

    printf("Enter the position to delete (1 to %d): ", count);
    scanf("%d", &pos);
    clearInputBuffer();

    if (pos < 1 || pos > count){
        printf("Invalid position!\n");
        return;
    }

    Node temp;
    if (pos == 1) {
        temp = start;
        start = start->next;
    } else {
        Node prev = start;
        for (i = 1; i < pos - 1; i++) {
            prev = prev->next;
        }
        temp = prev->next;
        prev->next = temp->next;
    }
    
    printf("[SUCCESS] Deleted node with data: %d from position %d.\n", temp->data, pos);
    free(temp);
}

void insertAtMid() {
    int count = getCount();
    int pos = (count / 2) + 1;

    printf("Inserting at middle position (Pos %d of %d)...\n", pos, count + 1);
    Node newNode = createNode();
    if (newNode == NULL) return;

    if (pos == 1) {
        newNode->next = start;
        start = newNode;
    } else {
        Node prev = start;
        for (int i = 1; i < pos - 1; i++) {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
    printf("[SUCCESS] Inserted %d at middle position %d.\n", newNode->data, pos);
}

/**
 * g. Deletion of the node from the middle of the list.
 * We define 'mid' as (count / 2) + 1.
 */
void deleteAtMid() {
    int count = getCount();
    if (count == 0) {
        printf("List is empty. Cannot delete from middle.\n");
        return;
    }
    
    int pos = (count / 2) + 1; // Calculate the middle position
    Node temp; // Node to be deleted
    
    if (pos == 1) {
        // Case 1: List has 1 or 2 nodes, so mid is the first node
        temp = start;
        start = start->next;
    } else {
        // Case 2: List has 3+ nodes. Traverse to node *before* the middle
        Node prev = start;
        for (int i = 1; i < pos - 1; i++) {
            prev = prev->next;
        }
        temp = prev->next;
        prev->next = temp->next;
    }
    
    printf("[SUCCESS] Deleted node with data %d from middle position %d.\n", temp->data, pos);
    free(temp); // Don't forget to free memory
}

/**
 * h. Reversing the linked list.
 * Uses an iterative approach with three pointers.
 */
void reverseList() {
    if (start == NULL || start->next == NULL) {
        printf("List is empty or has only one node, no need to reverse.\n");
        return;
    }
    
    Node prevNode = NULL;
    Node currentNode = start;
    Node nextNode = NULL;
    
    while (currentNode != NULL) {
        // Store the next node
        nextNode = currentNode->next;
        // Reverse the current node's pointer
        currentNode->next = prevNode;
        // Move pointers one position ahead
        prevNode = currentNode;
        currentNode = nextNode;
    }
    // After the loop, prevNode is the new head of the list
    start = prevNode;
    
    printf("[SUCCESS] The list has been reversed.\n");
    display(); // Show the reversed list
}
/**
 * i. Insertion of the node at the proper position in a sorted list.
 * NOTE: This function assumes the list is already sorted in ascending order.
 */
void insertInSorted() {  
    printf("Creating node to insert into the sorted list...\n");
    Node newNode = createNode();
    if (newNode == NULL) return;

    // Case 1: List is empty OR new node is the smallest
    if (start == NULL || start->data >= newNode->data) {
        newNode->next = start;
        start = newNode;
        printf("[SUCCESS] Inserted %d at the beginning.\n", newNode->data);
        return;
    }
    
    // Case 2: Find the correct position to insert
    Node current = start;
    // Traverse until we find a node that is LARGER than the new node
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }
    
    // Insert the new node after 'current'
    newNode->next = current->next;
    current->next = newNode;
    
    printf("[SUCCESS] Inserted %d in its sorted position.\n", newNode->data);
}

// (search, countNodes, sumAndAverage, display are unchanged and valid)
void search() {
    if (start == NULL) {
        printf("List is empty. Cannot search.\n");
        return;
    }
    
    int key, pos = 1;
    int found = 0;
    Node temp = start;

    printf("Enter the integer value to search for: ");
    scanf("%d", &key);
    clearInputBuffer();

    while (temp != NULL) {
        if (temp->data == key) {
            printf("[SUCCESS] Found %d at position %d.\n", key, pos);
            found = 1; 
        }
        temp = temp->next;
        pos++;
    }

    if (!found) {
        printf("[FAILURE] %d was not found in the list.\n", key);
    }
}

void countNodes() {
    int count = getCount();
    printf("Total number of nodes in the list: %d\n", count);
}

void sumAndAverage() {
    if (start == NULL) {
        printf("List is empty.\n");
        printf("Sum: 0, Average: 0.0\n");
        return;
    }
    
    int sum = 0;
    int count = 0;
    Node temp = start;
    
    while (temp != NULL) {
        sum = sum + temp->data;
        count++;
        temp = temp->next;
    }
    
    float average = (float)sum / count; 
    
    printf("--- Statistics ---\n");
    printf("Total Sum: %d\n", sum);
    printf("Total Count: %d\n", count);
    printf("Average:   %.2f\n", average);
}

void display() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node temp = start;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}