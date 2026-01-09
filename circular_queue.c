#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int front = 0, rear = -1, count = 0, Q[SIZE], ele;

void insert();
void delete();
void display();

int main() {
    int choice;
    while (1) {
        printf("\n\t1 => Insert an element into CIRCULAR QUEUE\n");
        printf("\t2 => Delete an element from CIRCULAR QUEUE\n");
        printf("\t3 => Display the status of CIRCULAR QUEUE\n");
        printf("\t4 => Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Enter a valid choice\n");
        }
    }
    return 0;
}

void insert() {
    if (count == SIZE){
        printf("Circular Queue is full, elements cannot be inserted\n");
        return;
    }
    rear = (rear + 1) % SIZE;
    printf("Enter the element to be inserted into the Circular Queue: ");
    scanf("%d", &ele);
    Q[rear] = ele;
    count++;
}

void delete() {
    if (count == 0) {
        printf("Circular Queue is empty, no elements to delete\n");
        return;
    }
    ele = Q[front];
    front = (front + 1) % SIZE;
    printf("The element deleted is %d\n", ele);
    count--;
}

void display() {
    if (count == 0) {
        printf("CIRCULAR QUEUE is empty, no element to display\n");
        return;
    }
    printf("Circular Queue contents are:\n");
    int i = front;
    for (int c = 0; c < count; c++) {
        printf("%d\t", Q[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}