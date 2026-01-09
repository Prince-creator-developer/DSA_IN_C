#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* link;
};
typedef struct node* NODE;

NODE last = NULL;

NODE getnode(){
    NODE newnode;
    newnode = (NODE) malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory not allocated\n");
        exit(0);
    }
    int ele;
    printf("enter the element to be inserted:\n");
    scanf("%d", &ele);
    newnode->info = ele;
    newnode->link = NULL; // This will be set by the insert function
    return newnode;
}
void insert_at_front(){
    NODE temp = getnode();
    if(last == NULL){
        last = temp;
        last->link = last; // Point to itself
        return;
    } else {
        temp->link = last->link;
        last->link = temp;
    }
    return;
}

void delete_at_front(){
    NODE temp;
    if (last == NULL){
        printf("the list is empty\n");
        return;
    }
    // --- THIS IS THE FIX ---
    // Check if it's the only node
    if(last->link == last){ 
        printf("the deleted element is %d\n", last->info);
        free(last);
        last = NULL;
        return;
    }
// --- END FIX ---

    temp = last->link; // temp points to the front node
    last->link = temp->link; // last now links to the new front node
    printf("the deleted element is %d\n", temp->info);
    free(temp);
    return;
}

void insert_at_end(){
    NODE temp = getnode();
    if(last == NULL){
        last = temp;
        last->link = last; // Point to itself
        return;
    }
    
    temp->link = last->link; // New node points to the front
    last->link = temp;     // Old last node points to the new node
    last = temp;           // Update last to be the new node
    return;
}

void delete_at_end(){
    NODE cur, prev;
    if(last == NULL){
        printf("the list is empty\n");
        return;
    }
    
    // --- THIS IS THE FIX ---
    // Check if it's the only node
    if(last->link == last){
        printf("the deleted element is %d\n", last->info);
        free(last);
        last = NULL;
        return;
    }
    // --- END FIX ---

    prev = NULL;
    cur = last->link; // Start at the front
    
    // Traverse until cur points to the last node
    while(cur != last){
        prev = cur;
        cur = cur->link;
    }
    
    // Now, prev points to the second-to-last node
    // and cur points to the last node
    printf("the deleted element is %d\n", cur->info); // or last->info
    prev->link = last->link; // Second-to-last node points to the front
    free(last); // Free the old last node
    last = prev; // Update last to be the second-to-last node
    
    return;
}

void display(){
    NODE cur;
    if(last == NULL){
        printf("the list is empty\n");
        return;
    }
    
    printf("the contents of the list are:\n");
    cur = last->link; // Start at the front
    
    while(cur != last){
        printf("%d -> ", cur->info);
        cur = cur->link;
    }
    // Print the last node
    printf("%d -> ", cur->info);
    
    // Show where the circular link points
    printf("(links back to %d)\n", last->link->info); 
    return;
}

void main(){
    int choice;
    while(1){
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Delete at front\n");
        printf("3. Insert at end\n");
        printf("4. Delete at end\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("---------------------------------\n");
        printf("Enter the choice: ");
        
        scanf("%d", &choice);
        
        switch(choice){
            case 1: insert_at_front(); break;
            case 2: delete_at_front(); break;
            case 3: insert_at_end(); break;
            case 4: delete_at_end(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Enter a valid choice\n");
        }
    }
}