#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// MAX HEAPIFY: Maintains the property where Parent > Children
void maxHeapify(int arr[], int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // left child index
    int right = 2 * i + 2;    // right child index

    // Check if left child exists and is greater than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child exists and is greater than the current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// MIN HEAPIFY: Maintains the property where Parent < Children
void minHeapify(int arr[], int n, int i) {
    int smallest = i;         // Initialize smallest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child exists and is SMALLER than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // Check if right child exists and is SMALLER than current smallest
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);

        // Recursively heapify the affected sub-tree
        minHeapify(arr, n, smallest);
    }
}

// Function to build the heap
// type 1 = Max Heap, type 2 = Min Heap
void buildHeap(int arr[], int n, int type) {
    // Start from the last non-leaf node and move up to the root
    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        if (type == 1) {
            maxHeapify(arr, n, i);

        } else {
            minHeapify(arr, n, i);
        }
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, choice, i;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamic memory allocation for the array
    arr = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printArray(arr, n);

    printf("\nSelect Heap Type:\n");
    printf("1. Max Heap\n");
    printf("2. Min Heap\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        buildHeap(arr, n, 1);
        printf("\nResultant Max Heap Array: \n");
    } else if (choice == 2) {
        buildHeap(arr, n, 2);
        printf("\nResultant Min Heap Array: \n");
    } else {
        printf("Invalid choice!\n");
        free(arr);
        return;
    }

    printArray(arr, n);
    
    // Free allocated memory
    free(arr);
    return 0;
}       