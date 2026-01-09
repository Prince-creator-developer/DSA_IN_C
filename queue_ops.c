#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int choice, ele, r = -1, f = 0, Q[SIZE];

void insert();
void delete();
void display();

int main() {
    while (1) {
        printf("1. insert\n2. delete\n3. display\n4. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Enter valid choice\n");
        }
    }
    return 0;
}

void insert() {
    if (r == SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &ele);
    Q[++r] = ele;
}

void delete() {
    if (f > r) {
        printf("Queue underflow\n");
        return;
    }
    ele = Q[f];
    printf("Element deleted is: %d\n", ele);
    f++;
}

void display() {
    if (f > r) {
        printf("Queue is Empty\n");
        return;
    }
    for (int i = f; i <= r; i++) {
        printf("%d\t", Q[i]);
    }
    printf("\n");
}