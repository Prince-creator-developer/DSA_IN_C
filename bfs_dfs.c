#include <stdio.h>

// Global Variables for DFS
int a[10][10]; // Adjacency matrix
int s[10];     // Visited array (used for DFS)
int n;         // Number of nodes

// Function to read the adjacency matrix
void read_adjacency_matrix() {
    int i, j;
    printf("Enter the adjacency matrix:\n");
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
void print_graph_connections() {
    int i, j;
    int has_edges = 0;

    printf("\n--- Graph Connections (Visual) ---\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Check if there is a connection (1)
            if (a[i][j] == 1) {
                printf("%d -> %d\n", i, j);
                has_edges = 1;
            }
        }
    }

    if (!has_edges) {
        printf("No connections found (Graph is empty).\n");
    }
    printf("----------------------------------\n");
}
int main() {
    int i, source, choice;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    read_adjacency_matrix();

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. BFS (from specific source)\n");
        printf("2. DFS (Reachability from all sources)\n");
        printf("3. print_graph_connections\n");

        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter starting source node (0 to %d): ", n - 1);
                scanf("%d", &source);
                if (source >= 0 && source < n)
                    bfs(source);
                else
                    printf("Invalid source node.\n");
                break;

            case 2:
                // Check reachability for every node using DFS
                for (source = 0; source < n; source++) {
                    // Reset visited array 's' to 0 before every new DFS run
                    for (i = 0; i < n; i++) s[i] = 0;
                    
                    printf("Nodes reachable from %d: ", source);
                    dfs(source);
                    printf("\n");
                }
                break;
            case 3:
                print_graph_connections();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}