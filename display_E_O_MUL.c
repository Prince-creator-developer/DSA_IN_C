#include <stdio.h>
#include <stdlib.h> // For malloc(), free(), and exit()
#include <stdbool.h> // For bool type in search/filter functions

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
void deleteAtMid();
void sortList();
void reverseList();
void insertInSorted();
void getEvenData();     // Added Function
void getOddData();      // Added Function
void getMultiples();    // Added Function
void search();
void countNodes();
void sumAndAverage();
void display();
void searchFindFirst(); // <--- ADD THIS LINE

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
        printf(" 4. Delete from the middle position\n");
        printf(" 5. Reverse the list\n");
        printf(" 6. Sort the given list\n");
        printf(" 7. Insert in a sorted list\n");
        printf(" 8. Get even data nodes\n");         // Added
        printf(" 9. Get odd data nodes\n");          // Added
        printf("10. Get multiples of a number\n");  // Added
        printf("11. Search for a node\n");
        printf("12. Count the number of nodes\n");
        printf("13. Find Sum and Average of data\n");
        printf("14. Display the list\n");
        printf("15. Search for FIRST occurrence\n"); // <--- ADDED
        printf("16. Exit\n");
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
            case 4: deleteAtMid();     break;
            case 5: reverseList();     break;
            case 6: sortList();        break;
            case 7: insertInSorted();  break;
            case 8: getEvenData();     break; // Added
            case 9: getOddData();      break; // Added
            case 10: getMultiples();   break; // Added
            case 11: search();         break;
            case 12: countNodes();     break;
            case 13: sumAndAverage();  break;
            case 14: display();        break;
            case 15: searchFindFirst(); break;
            case 16:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// --- Helper Functions ---

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Node createNode() {
    Node newNode = (Node)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed (Heap Overflow)!\n");
        return NULL;
    }
    printf("  Enter the integer data: ");
    
    while (scanf("%d", &newNode->data) != 1) {
        printf("Invalid input! Please enter an integer: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    
    newNode->next = NULL;
    return newNode;
}

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

void insertAtPos() {
    int pos, i;
    int count = getCount();
    
    printf("Enter the position to insert (1 to %d): ", count + 1);

    while (scanf("%d", &pos) != 1) {
        printf("Invalid input! Please enter a number: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position! Must be between 1 and %d.\n", count + 1);
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
    int pos,i;

    int count = getCount();

    if (start == NULL) {
        printf("List is empty (Underflow)!\n");
        return;
    }

    printf("Enter the position to delete (1 to %d): ", count);
    
    while (scanf("%d", &pos) != 1) {
        printf("Invalid input! Please enter a number: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    if (pos < 1 || pos > count) {
        printf("Invalid position! Must be between 1 and %d.\n", count);
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

void deleteAtMid() {
    int count = getCount();
    if (count == 0) {
        printf("List is empty. Cannot delete from middle.\n");
        return;
    }
    
    int pos = (count / 2) + 1;
    Node temp;
    
    if (pos == 1) {
        temp = start;
        start = start->next;
    } else {
        Node prev = start;
        for (int i = 1; i < pos - 1; i++) {
            prev = prev->next;
        }
        temp = prev->next;
        prev->next = temp->next;
    }
    
    printf("[SUCCESS] Deleted node with data %d from middle position %d.\n", temp->data, pos);
    free(temp);
}

void reverseList() {
    if (start == NULL || start->next == NULL) {
        printf("List is empty or has only one node, no need to reverse.\n");
        return;
    }
    
    Node prevNode = NULL;
    Node currentNode = start;
    Node nextNode = NULL;
    
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    start = prevNode;
    
    printf("[SUCCESS] The list has been reversed.\n");
    display();
}


void sortList() {
    Node ptr1, ptr2;
    int temp_data;

    if (start == NULL || start->next == NULL) {
        printf("List is empty or has only one node. No sorting needed.\n");
        return;
    }

    for (ptr1 = start; ptr1 != NULL; ptr1 = ptr1->next) {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
            if (ptr1->data > ptr2->data) {
                temp_data = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp_data;
            }
        }
    }
    printf("[SUCCESS] The list has been sorted.\n");
    display();
}

void insertInSorted() {
    printf("Creating node to insert into the sorted list...\n");
    Node newNode = createNode();
    if (newNode == NULL) return;

    if (start == NULL || start->data >= newNode->data) {
        newNode->next = start;
        start = newNode;
        printf("[SUCCESS] Inserted %d at the beginning.\n", newNode->data);
        return;
    }
    
    Node current = start;
    while (current->next != NULL && current->next->data < newNode->data){
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    
    printf("[SUCCESS] Inserted %d in its sorted position.\n", newNode->data);
}

/**
 * @brief Displays all nodes with even data.
 */
void getEvenData() {
    if (start == NULL) {
        printf("List is empty. Cannot search for even data.\n");
        return;
    }
    
    Node temp = start;
    bool found = false;
    printf("Even numbers in the list: ");
    
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            printf("%d ", temp->data);
            found = true;
        }
        temp = temp->next;
    }
    
    if (!found){
        printf("None found.");
    }
    printf("\n");
}
/**
 * @brief Displays all nodes with odd data.
 */
void getOddData(){
    if (start == NULL) {
        printf("List is empty. Cannot search for odd data.\n");
        return;
    }

    Node temp = start;
    bool found = false;
    printf("Odd numbers in the list: ");
    
    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            printf("%d ", temp->data);
            found = true;
        }
        temp = temp->next;
    }
    
    if (!found) {
        printf("None found.");
    }
    printf("\n");
}

/**
 * @brief Asks for a number and displays all nodes whose data is a multiple.
 */
void getMultiples() {
    if (start == NULL) {
        printf("List is empty. Cannot search for multiples.\n");
        return;
    }
    
    int key;
    printf("Enter a number to find its multiples: ");
    
    // Robust input validation for the key
    while (scanf("%d", &key) != 1) {
        printf("Invalid input! Please enter a number: ");
        clearInputBuffer();
    }
    clearInputBuffer();   // Clear trailing '\n'
    
    // Handle division by zero case
    if (key == 0) {
        printf("All numbers are multiples of 0 (if 0*n=x), or none are (if x/0). Cannot compute.\n");
        return;
    }

    Node temp = start;
    bool found = false;
    printf("Multiples of %d in the list: ", key);
    
    while (temp != NULL) {
        // Check if data is a multiple of key
        if (temp->data % key == 0) {
            printf("%d ", temp->data);
            found = true;
        }
        temp = temp->next;
    }
    
    if (!found) {
        printf("None found.");
    }
    printf("\n");
}


/**
 * d. Searching for a node with given value.
 */
void search() {
    if (start == NULL) {
        printf("List is empty. Cannot search.\n");
        return;
    }
    
    int key, pos = 1;
    bool found = false;                                                                          // Use bool for clarity
    Node temp = start;

    printf("Enter the integer value to search for: ");
    
    while (scanf("%d", &key) != 1) {
        printf("Invalid input! Please enter a number: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    while (temp != NULL) {
        if (temp->data == key) {
            printf("[SUCCESS] Found %d at position %d.\n", key, pos);
            found = true;
        }
        temp = temp->next;
        pos++;
    }

    if (!found) {
        printf("[FAILURE] %d was not found in the list.\n", key);
    }
}

/**
 * e. Count the number of nodes in the list.
 */
void countNodes() {
    int count = getCount();
    printf("Total number of nodes in the list: %d\n", count);
}

/**
 * f. Find the sum and average of data present in all nodes.
 */
void sumAndAverage() {
    if (start == NULL) {
        printf("List is empty.\n");
        printf("Sum: 0, Average: 0.0\n");
        return;
    }
    
    // Use long int for sum to prevent potential overflow
    long int sum = 0; 
    int count = 0;
    Node temp = start;
    
    while (temp != NULL) {
        sum = sum + temp->data;
        count++;
        temp = temp->next;
    }
    
    float average = (float)sum / count; 
    
    printf("--- Statistics ---\n");
    printf("Total Sum: %ld\n", sum); // Use %ld for long int
    printf("Total Count: %d\n", count);
    printf("Average:   %.2f\n", average);
}
/**
 * @brief Searches for the FIRST node with a given value and stops.
 */
void searchFindFirst() {
    if (start == NULL) {
        printf("List is empty. Cannot search.\n");
        return;
    }
    
    int key, pos = 1;
    Node temp = start;

    printf("Enter the integer value to search for (finds first): ");
    
    // Input validation
    while (scanf("%d", &key) != 1) {
        printf("Invalid input! Please enter a number: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    // --- Search Logic ---
    // 
    while (temp != NULL) {
        if (temp->data == key) {
            // Found it!
            printf("[SUCCESS] Found %d at position %d.\n", key, pos);
            return; // <-- Key difference: exit the function immediately
        }
        temp = temp->next; // Move to the next node
        pos++;             // Increment position counter
    }

    // If the loop finishes, it was not found
    printf("[FAILURE] %d was not found in the list.\n", key);
}
/**
 * @brief Displays all elements in the linked list.
 */
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