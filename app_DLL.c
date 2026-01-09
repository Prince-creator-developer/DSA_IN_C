#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char ssn[25], name[25], dept[10], designation[25];
    long int sal, phoneno;
    struct node *llink;
    struct node *rlink;
};

typedef struct node* NODE;
NODE first = NULL;
int count = 0;

NODE getNode() {
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    
    // FIX: Check for memory failure BEFORE scanning input
    if (newnode == NULL) {
        printf("\nRunning out of memory");
        exit(0);
    }

    printf("\nEnter the Employee SSN, Name, Dept, Designation, Salary, PhoneNo: \n");
    scanf("%s %s %s %s %ld %ld", newnode->ssn, newnode->name, newnode->dept, 
          newnode->designation, &newnode->sal, &newnode->phoneno);

    newnode->llink = NULL;
    newnode->rlink = NULL;
    count++;
    return newnode;
}

void insertAtFront() {
    NODE temp;
    temp = getNode();
    if (first == NULL) {
        first = temp;
        return;
    }
    temp->rlink = first;
    first->llink = temp;
    first = temp;
}

void deleteAtFront() {
    NODE temp;
    if (first == NULL) {
        printf("\nDoubly Linked List is empty");
        return;
    }
    
    temp = first;
    first = first->rlink;
    
    // FIX: Handle case where list becomes empty
    if (first != NULL) {
        first->llink = NULL;
    }
    
    printf("\nThe employee node with the ssn:%s is deleted", temp->ssn);
    free(temp);
    count--;
}

void insertAtEnd() {
    NODE cur, temp;
    temp = getNode();
    if (first == NULL) {
        first = temp;
        return;
    }
    cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
}

void deleteAtEnd() {
    NODE cur;
    if (first == NULL) {
        printf("\nDoubly Linked List is empty");
        return;
    }

    // Case 1: Only one node in the list
    if (first->rlink == NULL) {
        printf("\nThe employee node with the ssn:%s is deleted", first->ssn);
        free(first);
        first = NULL;
        count--;
        return;
    }

    // Case 2: Multiple nodes
    cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    
    // cur is now the last node
    cur->llink->rlink = NULL; // Disconnect from previous
    printf("\nThe employee node with the ssn:%s is deleted", cur->ssn);
    free(cur);
    count--;
}

void displayStatus() {
    NODE cur;
    int nodeno = 1;
    cur = first;
    
    if (first == NULL) {
        printf("\nNo Contents to display in DLL");
        return;
    }
    
    printf("\nNode#\t SSN\t Name\t Dept\t Desig\t Salary\t Phone\n");
    while (cur != NULL) {
        printf("\n%d\t %s\t %s\t %s\t %s\t %ld\t %ld", 
               nodeno, cur->ssn, cur->name, cur->dept, 
               cur->designation, cur->sal, cur->phoneno);
        cur = cur->rlink;
        nodeno++;
    }
    printf("\n\nNo of employee nodes is %d", count);
}

void doubleEndedQueueDemo() {
    int ch;
    // FIX: Removed unreachable breaks and fixed switch case fall-through
    while (1) {
        printf("\n\nDemo Double Ended Queue Operation");
        printf("\n1: InsertQueueFront\n2: DeleteQueueFront\n3: InsertQueueRear\n4: DeleteQueueRear\n5: DisplayStatus\n6: Exit Demo\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: insertAtFront(); break;
            case 2: deleteAtFront(); break;
            case 3: insertAtEnd(); break;
            case 4: deleteAtEnd(); break;
            case 5: displayStatus(); break;
            case 6: return; // Exits to main menu
            default: printf("Invalid choice");
        }
    }
}

int main() {
    int ch, i, n;
    while (1) {
        printf("\n\n~~~Menu~~~");
        printf("\n1: Create DLL of Student Nodes");
        printf("\n2: DisplayStatus");
        printf("\n3: DoubleEndedQueueDemo");
        printf("\n4: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: 
                printf("\nEnter the no of Employees: ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++)
                    insertAtEnd();
                break;
            case 2: displayStatus(); break;
            case 3: doubleEndedQueueDemo(); break;
            case 4: exit(0);
            default: printf("\nEnter a valid choice");
        }
    }
    return 0;
}