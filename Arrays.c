#include <stdio.h>
#include <stdlib.h>

// n (size) and a (array) are global to be shared by all functions.
int a[100], n = 0; // Initialize n to 0

void create() {
    // Declare 'i' locally.
    int i; 
    printf("Enter the no. of elements in array\n");
    scanf("%d", &n);
    
    // Check if the user is asking for more elements than the array can hold
    if (n > 100 || n < 0) {
        printf("Invalid size. Size must be between 0 and 100.\n");
        n = 0; // Reset n
        return;
    }

    printf("Enter %d elements in array\n", n);
    // The scanf must be INSIDE the for loop
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]); 
    }
}

void display() {
    // Declare 'i' locally.
    int i; 
    printf("The Array Contents are:\n");
    for (i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
}

void insert() {
    int ele, pos, i; // Declare all variables locally

    // Check if the array is already full
    if (n == 100) {
        printf("Array is Full. Cannot insert.\n");
        return;
    }

    printf("Enter the element to be inserted and its position\n");
    scanf("%d %d", &ele, &pos);

    // Position check: 0 <= pos <= n
    // (You can insert at position 'n', which is the end of the array)
    if (pos > n || pos < 0) {
        printf("Invalid Position\n");
        return;
    }

    // Shift elements to the right
    for (i = n - 1; i >= pos; i--) {
        a[i + 1] = a[i];
    }
    
    a[pos] = ele; // Insert the element
    n = n + 1;    // Increase the size

    printf("\nArray after Insertion\n");
    display(); // Call the display function instead of repeating code
}

void del() {
    int pos, i; // Declare variables locally
    
    printf("Enter the position to delete element:\t");
    scanf("%d", &pos);

    // Position check: 0 <= pos < n
    // (You can only delete an existing element)
    if (pos < 0 || pos >= n) {
        printf("Invalid Position\n");
        return;
    }

    printf("Element deleted is %d\n", a[pos]);

    // Shift elements to the left
    for (i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    
    n = n - 1; // Decrease the size

    printf("\nArray after Deletion\n");
    display(); // Call the display function
}

void main() {
    int ch;
    for (;;) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1 : Create array\n");
        printf("2 : Display array\n");
        printf("3 : Insert element\n");
        printf("4 : Delete element\n");
        printf("5 : Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                if (n == 0)
                    printf("Array is Empty\n");
                else
                    display();
                break;
            case 3:
                // You can insert into an empty array (at pos 0)
                // so we don't need to check if n==0
                insert();
                break;
            case 4:
                if (n == 0)
                    printf("Array is Empty\n");
                else
                    del();
                break;
            case 5:
                exit(0);
            default:
                // Use standard quotes "" not smart quotes “”
                printf("Invalid Choice\n"); 
        }
    }
}