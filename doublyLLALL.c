#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *rlink, *llink;
};
typedef struct node* NODE;

NODE first = NULL; // Initialize to NULL globally

NODE getnode() {
    NODE newnode;
    newnode = (NODE) malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory not allocated\n");
        exit(0);
    }
    int ele;
    printf("Enter the element to be inserted:\n");
    scanf("%d", &ele);

    newnode->info = ele;
    newnode->rlink = NULL;
    newnode->llink = NULL;
    return newnode;
}

int getcount() {
    NODE cur;
    int count = 0;
    cur = first;
    while (cur != NULL) {
        count++;
        cur = cur->rlink;
    }
    // Removed print statement here so it can be used silently by other functions
    return count;
}

void insert_at_front() {
    NODE temp = getnode();
    if (first == NULL) {
        first = temp;
        return;
    }
    // Direct logic without redundant checks
    first->llink = temp;
    temp->rlink = first;
    first = temp;
}

void delete_at_front() {
    NODE temp;
    if (first == NULL) {
        printf("The list is empty\n");
        return;
    }
    if (first->rlink == NULL) {
        // FIXED: specific syntax error with printf parenthesis
        printf("The deleted element is %d\n", first->info); 
        free(first);
        first = NULL;
        return;
    }

    temp = first;
    first = first->rlink;
    printf("The deleted element is %d\n", temp->info);
    free(temp);
    first->llink = NULL;
}

void insert_at_end() {
    NODE temp = getnode();
    if (first == NULL) {
        first = temp;
        return;
    }
    NODE cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
}

void delete_at_end() {
    NODE cur, prev;
    if (first == NULL) {
        printf("The list is empty\n");
        return;
    }
    if (first->rlink == NULL) {
        printf("The deleted element is %d\n", first->info);
        free(first);
        first = NULL;
        return;
    }
    // Using standard traversal
    cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    // cur is now the last node, cur->llink is the previous node
    prev = cur->llink; 
    printf("The deleted element is %d\n", cur->info);
    free(cur);
    prev->rlink = NULL;
}

void search() {
    NODE cur;
    int ele, pos = 1, flag = 0;
    if (first == NULL) {
        printf("The list is empty\n");
        return;
    }
    printf("Enter the element to be searched:\n");
    scanf("%d", &ele);
    cur = first;
    while (cur != NULL) {
        if (cur->info == ele) {
            printf("The element %d is found at position %d\n", ele, pos);
            flag = 1;
            return;
        }
        pos++;
        cur = cur->rlink;
    }
    if (flag == 0) {
        printf("The element %d is not found in the list\n", ele);
    }
}

void reverse() {
    NODE temp = NULL;
    NODE cur = first;

    if (first == NULL) {
        printf("The list is empty\n");
        return;
    }

    // Swap llink and rlink for every node
    while (cur != NULL) {
        temp = cur->llink;
        cur->llink = cur->rlink;
        cur->rlink = temp;
        
        // Move to the "next" node (which is now in llink due to swap)
        cur = cur->llink; 
    }

    // Adjust head: if temp is not NULL, it points to the old 2nd node (new 2nd to last).
    // The new head is the previous 'temp->llink' (which was the old last node).
    if (temp != NULL) {
        first = temp->llink;
    }
    printf("List reversed successfully.\n");
}

void sort() {
    NODE i, j;
    int temp;
    if (first == NULL) {
        printf("The list is empty\n");
        return;
    }
    // Simple Bubble sort by swapping data
    for (i = first; i->rlink != NULL; i = i->rlink) {
        for (j = i->rlink; j != NULL; j = j->rlink) {
            if (i->info > j->info) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
    printf("List sorted successfully.\n");
}

void insert_at_pos() {
    int pos, count = 0, i;
    
    if (first == NULL) {
        // If list is empty, we can only insert at position 1
        printf("List is empty. Inserting at position 1.\n");
        insert_at_front();
        return; 
    }

    printf("Enter the position to insert the node:\n");
    scanf("%d", &pos);
    
    count = getcount();

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position\n");
        return;
    }
    
    if (pos == 1) {
        insert_at_front();
        return;
    }
    if (pos == count + 1) {
        insert_at_end();
        return;
    }
    
    // MOVED getnode() here. Only allocate if position is valid.
    NODE temp = getnode();
    NODE cur = first;
    NODE prev = NULL;

    // Traverse to the node currently at 'pos'
    for (i = 1; i < pos; i++) {
        cur = cur->rlink;
    }
    
    // Insert 'temp' before 'cur'
    prev = cur->llink;
    
    prev->rlink = temp;
    temp->llink = prev;
    
    temp->rlink = cur;
    cur->llink = temp;
}

void delete_at_pos() {
    NODE cur;
    int pos, count = 0, i;

    if (first == NULL) {
        printf("The list is empty\n");
        return;
    }
    printf("Enter the position to delete the node:\n");
    scanf("%d", &pos);
    
    count = getcount();
    
    if (pos < 1 || pos > count) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        delete_at_front();
        return;
    }
    if (pos == count) {
        delete_at_end();
        return;
    }

    cur = first;
    for (i = 1; i < pos; i++) {
        cur = cur->rlink;
    }

    // Logic for deleting a node in the middle
    cur->llink->rlink = cur->rlink;
    cur->rlink->llink = cur->llink;

    printf("The deleted element is %d\n", cur->info);
    free(cur);
}
void delete_by_info() {
    NODE cur;
    int key, flag = 0;

    if (first == NULL) {
        printf("The list is empty\n");
        return;
    }

    printf("Enter the element to be deleted: ");
    scanf("%d", &key);

    cur = first;

    // Search for the node with the specific info
    while (cur != NULL) {
        if (cur->info == key) {
            flag = 1;
            break;
        }
        cur = cur->rlink;
    }

    if (flag == 0) {
        printf("Element %d not found in the list\n", key);
        return;
    }

    // If node to be deleted is the ONLY node
    if (cur == first && cur->rlink == NULL) {
        first = NULL;
    }
    // If node to be deleted is the FIRST node
    else if (cur == first) {
        first = cur->rlink;
        first->llink = NULL;
    }
    // If node to be deleted is the LAST node
    else if (cur->rlink == NULL) {
        cur->llink->rlink = NULL;
    }
    // If node to be deleted is in the MIDDLE
    else {
        cur->llink->rlink = cur->rlink;
        cur->rlink->llink = cur->llink;
    }

    printf("Node with value %d deleted successfully.\n", key);
    free(cur);
}
void display() {
    NODE cur;
    if (first == NULL) {
        printf("The list is empty\n");
        return;
    }
    printf("The contents of the list are:\n");
    cur = first;
    printf("NULL <-> ");
    while (cur != NULL) {
        printf("%d <-> ", cur->info);
        cur = cur->rlink;
    }
    printf("NULL\n");
}

void main() {
    int choice;
    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert at front\n");
        printf("2. Delete at front\n");
        printf("3. Insert at end\n");
        printf("4. Delete at end\n");
        printf("5. Display\n");
        printf("6. Insert at Position\n");
        printf("7. Delete at Position\n");
        printf("8. Search\n");
        printf("9. Get Count\n");
        printf("10. Reverse List\n");
        printf("11. Sort List\n");
        printf("12. Exit\n");
        printf("13. Create DLL of n nodes\n");
        printf("14. delete by info");

        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: insert_at_front(); break;
            case 2: delete_at_front(); break;
            case 3: insert_at_end(); break;
            case 4: delete_at_end(); break;
            case 5: display(); break;
            case 6: insert_at_pos(); break;
            case 7: delete_at_pos(); break;
            case 8: search(); break;
            case 9: printf("Node count: %d\n", getcount()); break;
            case 10: reverse(); break;
            case 11: sort(); break;
            case 12: exit(0);
            case 13:{
                int n, i;
                printf("Enter the number of nodes to create:\n");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    insert_at_front();
                }
                break;
            }
            case 14: delete_by_info(); break;
            default: printf("Enter a valid choice\n");
        }
    }
}