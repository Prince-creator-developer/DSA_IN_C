#include <stdio.h>
#include <stdlib.h>

// Global Variables
int a[10][10]; // Adjacency matrix
int s[10];     // Visited array (used for DFS)
int n;         // Number of nodes

// Function to read the adjacency matrix
void read_adjacency_matrix() {
    int i, j;
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

// Breadth First Search Function
void bfs(int u) {
    int f, r, q[10], v;
    int visited[10] = {0}; // Local visited array for BFS

    printf("BFS - Nodes reachable from %d: ", u);
    
    f = 0; r = -1; // Queue initialization
    q[++r] = u;    // Enqueue u
    visited[u] = 1; // Mark u as visited
    printf("%d ", u);

    while (f <= r) {
        u = q[f++]; // Dequeue
        for (v = 0; v < n; v++) {
            // If adjacent and not visited
            if (a[u][v] == 1 && visited[v] == 0) {
                printf("%d ", v);
                visited[v] = 1;
                q[++r] = v; // Enqueue v
            }
        }
    }
    printf("\n");
}

// Depth First Search Function (Recursive)
void dfs(int u) {
    int v;
    s[u] = 1; // Mark current node as visited (global array)
    printf("%d ", u);
    
    for (v = 0; v < n; v++) {
        if (a[u][v] == 1 && s[v] == 0) {
            dfs(v);
        }
    }
}

int main() {
    int i, source, choice;

    printf("Enter the number of nodes (Cities): ");
    scanf("%d", &n);

    read_adjacency_matrix();

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. BFS (Reachability from a specific source)\n");
        printf("2. DFS (Reachability from a specific source)\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter starting source node for BFS (0 to %d): ", n - 1);
                scanf("%d", &source);
                if (source >= 0 && source < n)
                    bfs(source);
                else
                    printf("Invalid source node.\n");
                break;

            case 2:
                printf("Enter starting source node for DFS (0 to %d): ", n - 1);
                scanf("%d", &source);
                if (source >= 0 && source < n) {
                    // Reset visited array 's' to 0 before DFS run
                    for (i = 0; i < n; i++) s[i] = 0;
                    
                    printf("DFS - Nodes reachable from %d: ", source);
                    dfs(source);
                    printf("\n");
                } else {
                    printf("Invalid source node.\n");
                }
                break;
                

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}