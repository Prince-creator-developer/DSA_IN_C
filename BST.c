#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node *NODE;
NODE root = NULL;

// Function Prototypes
void insert(int item); // Modified to accept integer directly
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);
void display(NODE root, int level);
void search(NODE root, int key);
void findMinMax(NODE root);

int main() {
    int ch, i, n, key, val;
    
    // --- AUTOMATIC INSERTION logic ---
    int inputData[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 5, 2};
    int totalInputs = 11;

    printf("--- AUTOMATICALLY INSERTING GIVEN DATA ---\n");
    printf("Input Sequence: 6, 9, 5, 2, 8, 15, 24, 14, 7, 5, 2\n\n");
    
    for(i = 0; i < totalInputs; i++) {
        insert(inputData[i]);
    }
    printf("\nData loaded! Duplicates (5, 2) were rejected.\n");
    // ---------------------------------

    while (1) {
        printf("\n\n*** TREE OPERATIONS ***\n");
        printf("1: Insert new node manually\n");
        printf("2: Inorder traversal\n");
        printf("3: Preorder traversal\n");
        printf("4: Postorder traversal\n");
        printf("5: Display Tree Structure\n");
        printf("6: Search for a Key\n");
        printf("7: Find Min & Max\n");
        printf("8: Exit\n");
        printf("***********************\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &val);
                insert(val);
                break;

            case 2:
                if (root == NULL) printf("Empty tree\n");
                else { printf("Inorder: "); inorder(root); }
                break;

            case 3:
                if (root == NULL) printf("Empty tree\n");
                else { printf("Preorder: "); preorder(root); }
                break;

            case 4:
                if (root == NULL) printf("Empty tree\n");
                else { printf("Postorder: "); postorder(root); }
                break;

            case 5:
                if (root == NULL) printf("Empty tree\n");
                else { printf("Tree Structure (Tilt head left):\n"); display(root, 1); }
                break;

            case 6: 
                if (root == NULL) printf("Empty tree\n");
                else {
                    printf("Enter the key to search: ");
                    scanf("%d", &key);
                    search(root, key);
                }
                break;

            case 7: 
                findMinMax(root);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// Modified insert to take 'item' as argument
void insert(int item) {
    NODE newnode, prev, curr;
    newnode = (NODE)malloc(sizeof(struct node));
    
    newnode->data = item;
    newnode->lchild = newnode->rchild = NULL;

    if (root == NULL) {
        root = newnode;
        printf("Inserted: %d (Root)\n", item);
        return;
    }

    prev = NULL;
    curr = root;
    while (curr != NULL) {
        if (curr->data == item) {
            printf("Ignored Duplicate: %d\n", item); // Report duplicate
            free(newnode);
            return;
        }
        prev = curr;
        if (item < curr->data) curr = curr->lchild;
        else curr = curr->rchild;
    }
    
    if (item < prev->data) prev->lchild = newnode;
    else prev->rchild = newnode;
    
    printf("Inserted: %d\n", item);
}

void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

void preorder(NODE root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}

void display(NODE root, int level) {
    int i;
    if (root) {
        display(root->rchild, level + 1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf("\t");
        printf("%d", root->data);
        display(root->lchild, level + 1);
    }
}

void search(NODE root, int key) {
    NODE cur = root;
    if (root == NULL) {
        printf("\nTree is empty. Cannot search.");
        return;
    }
    while (cur != NULL) {
        if (key == cur->data) {
            printf("\nSEARCH RESULT: Key %d FOUND in the tree.", key);
            return;
        }
        if (key < cur->data) cur = cur->lchild;
        else cur = cur->rchild;
    }
    printf("\nSEARCH RESULT: Key %d NOT found in the tree.", key);
}

void findMinMax(NODE root) {
    NODE cur = root;
    if (root == NULL) {
        printf("\nTree is empty.");
        return;
    }
    while (cur->lchild != NULL) cur = cur->lchild;
    printf("\nMinimum element is: %d", cur->data);

    cur = root;
    while (cur->rchild != NULL) cur = cur->rchild;
    printf("\nMaximum element is: %d", cur->data);
}