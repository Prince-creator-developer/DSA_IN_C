#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node *NODE;
NODE root = NULL; // Global root

// Function Prototypes
void insert();
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);
void display(NODE root, int level);

int main() {
    int ch, i, n;
    
    for (;;) {
        printf("\n*** TREE OPERATIONS ***\n");
        printf(" 1: Insert nodes\n 2: Inorder traversal\n 3: Preorder traversal\n 4: Postorder traversal\n 5: Display\n 6: Exit");
        printf("\n***********************\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the no of elements: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                    insert();
                break;
            case 2:
                if (root == NULL)
                    printf("Empty tree\n");
                else {
                    printf("Inorder traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if (root == NULL)
                    printf("Empty tree\n");
                else {
                    printf("Preorder traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL)
                    printf("Empty tree\n");
                else {
                    printf("Postorder traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
                if (root == NULL)
                    printf("Empty tree\n");
                else {
                    printf("The tree structure (rotated 90 deg):\n");
                    display(root, 1);
                }
                break;
            case 6: // Fixed: changed 'Case' to 'case'
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void insert() {
    NODE newnode, prev, curr;
    newnode = (NODE)malloc(sizeof(struct node));
    
    printf("Enter the element to be inserted: ");
    scanf("%d", &newnode->data);
    
    newnode->lchild = newnode->rchild = NULL;
    
    if (root == NULL) {
        root = newnode;
        return;
    }
    
    prev = NULL;
    curr = root;
    
    while (curr != NULL) {
        if (curr->data == newnode->data) {
            printf("Duplicate is not possible\n");
            free(newnode);
            return;
        }
        prev = curr;
        if (newnode->data < curr->data)
            curr = curr->lchild;
        else
            curr = curr->rchild;
    }
    
    if (newnode->data < prev->data)
        prev->lchild = newnode;
    else
        prev->rchild = newnode;
}

void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%4d", root->data);
        inorder(root->rchild);
    }
}

void preorder(NODE root) {
    if (root != NULL) {
        printf("%4d", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%4d", root->data);
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