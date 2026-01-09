#include <stdio.h>
#include <stdlib.h>

// --- STRUCTURE DEFINITIONS ---
struct StudentData {
    char usn[20];
    char name[100];
    char branch[50];
    int sem;
};

struct node {
    struct StudentData info; // Renamed from 'data' to 'info' to match your code
    struct node* link;
};
typedef struct node* NODE;

// --- GLOBAL HEAD POINTER ---
// It's good practice to initialize global pointers to NULL
NODE first = NULL;

// --- FUNCTION PROTOTYPES ---
NODE getnode();
void insert_at_front();
void delete_at_front();
void insert_at_end();
void delete_at_end();
void display();

/**
 * @brief Allocates memory for a new node and gets student data from the user.
 * This function is now corrected.
 */
NODE getnode() {
    NODE newnode;
    // 1. Allocate memory
    newnode = (NODE)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory not allocated\n");
        exit(0);
    }

    // 2. Get student data from the user and store it
    printf("Enter Student Details:\n");
    printf("  Enter USN: ");
    scanf("%s", newnode->info.usn);
    printf("  Enter Name (one word): ");
    scanf("%s", newnode->info.name);
    printf("  Enter Branch (e.g., CSE): ");
    scanf("%s", newnode->info.branch);
    printf("  Enter Semester: ");
    scanf("%d", &newnode->info.sem);

    // 3. Initialize the link and return the new node
    newnode->link = NULL;
    return newnode;
}

/**
 * @brief Inserts a new student node at the front of the list.
 */
void insert_at_front() {
    NODE temp = getnode(); // Correctly gets a new, populated node
    temp->link = first;
    first = temp;
    printf("\n[SUCCESS] Student inserted at the front.\n");
    return;
}

/**
 * @brief Deletes the student node from the front of the list.
 */
void delete_at_front() {
    NODE temp;
    if (first == NULL) {
        printf("The list is empty (Underflow)\n");
        return;
    }
    temp = first;
    first = first->link;
    printf("\n[SUCCESS] Deleted student from front of the list:\n  USN: %s, Name: %s\n",
           temp->info.usn, temp->info.name);
    free(temp);
    return;
}

/**
 * @brief Inserts a new student node at the end of the list.
 */
void insert_at_end() {
    NODE temp = getnode(); // Correctly gets a new, populated node
    
    // If the list is empty, the new node becomes the first node
    if (first == NULL) {
        first = temp;
        printf("\n[SUCCESS] Student inserted at the end.\n");
        return;
    }
    
    // Traverse to the end of the list
    NODE cur = first;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    
    // Link the last node to the new node
    cur->link = temp;
    printf("\n[SUCCESS] Student inserted at the end.\n");
}

/**
 * @brief Deletes the student node from the end of the list.
 * This function is now corrected.
 */
void delete_at_end() {
    NODE cur, prev;
    if (first == NULL) {
        printf("The list is empty (Underflow)\n");
        return;
    }

    // Case 1: Only one node in the list
    if (first->link == NULL) {
        // Corrected: Print student details, not the whole struct
        printf("\n[SUCCESS] Deleted student from list:\n  USN: %s, Name: %s\n",
               first->info.usn, first->info.name);
        free(first);
        first = NULL;
        return;
    }

    // Case 2: More than one node
    prev = NULL;
     cur = first;
    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }
    
    // Corrected: Message now correctly says "from end"
    printf("\n[SUCCESS] Deleted student from *end* of the list:\n  USN: %s, Name: %s\n",
           cur->info.usn, cur->info.name);
    free(cur);
    prev->link = NULL; // Unlink the last node
    return;
}

/**
 * @brief Displays all student nodes in the list and counts them.
 * This function is now corrected.
 */
void display() {
    NODE cur;
    int count = 0; // Added a counter
    
    if (first == NULL) {
        printf("The list is empty\n");
        printf("Total number of nodes: 0\n");
        return;
    }

    printf("\n--- Singly Linked List Contents ---\n");
    cur = first;
    while (cur != NULL) {
        // Corrected: Print each member of the struct
        printf("\nNode %d:\n", count + 1);
        printf("  USN   : %s\n", cur->info.usn);
        printf("  Name  : %s\n", cur->info.name);
        printf("  Branch: %s\n", cur->info.branch);
        printf("  Sem   : %d\n", cur->info.sem);
        
        count++;
        cur = cur->link;
    }
    printf("\n-------------------------------------\n");
    printf("Total number of nodes: %d\n", count); // Print the total count
}

/**
 * @brief The main menu-driven function.
 */
void main() {
    int choice;
    while (1) {
        // Corrected menu formatting for clarity
        printf("\n\n--- SLL Student Database Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Delete at Front\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_at_front(); break;
            case 2: delete_at_front(); break;
            case 3: insert_at_end();   break;
            case 4: delete_at_end();   break;
            case 5: display();         break;
            case 6: exit(0);
            default: printf("Invalid choice, please try again.\n");
        }
    }
}