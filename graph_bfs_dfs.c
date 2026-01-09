/* * Program: Graph Operations (BFS and DFS) using Adjacency Matrix
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int a[MAX][MAX]; // Adjacency Matrix
int visited[MAX];
int n; // Number of cities/nodes

// Function to reset visited array before every traversal
void clearVisited() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
}

// Breadth First Search
void bfs(int start) {
    int q[MAX], front = 0, rear = -1;
    
    // Enqueue start node and mark visited
    q[++rear] = start;
    visited[start] = 1;
    
    printf("BFS Traversal: ");
    
    while (front <= rear) {
        int curr = q[front++]; // Dequeue
        printf("%d ", curr);
        
        // Check all adjacent nodes
        for (int i = 0; i < n; i++) {
            // If there is an edge AND it hasn't been visited
            if (a[curr][i] == 1 && visited[i] == 0) {
                q[++rear] = i; // Enqueue
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Depth First Search
void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;
    
    for (int i = 0; i < n; i++) {
        if (a[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int choice, startNode;
    
    printf("Enter the number of cities (N): ");
    scanf("%d", &n);
    
    printf("Enter the Adjacency Matrix (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    while (1) {
        printf("\n--- GRAPH MENU ---\n");
        printf("1. BFS Traversal (Reachable nodes)\n");
        printf("2. DFS Traversal (Reachable nodes)\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter starting node (0 to %d): ", n-1);
                scanf("%d", &startNode);
                if (startNode < 0 || startNode >= n) {
                    printf("Invalid start node.\n");
                } else {
                    clearVisited();
                    bfs(startNode);
                }
                break;
                
            case 2:
                printf("Enter starting node (0 to %d): ", n-1);
                scanf("%d", &startNode);
                if (startNode < 0 || startNode >= n) {
                    printf("Invalid start node.\n");
                } else {
                    clearVisited();
                    printf("DFS Traversal: ");
                    dfs(startNode);
                    printf("\n");
                }
                break;
                
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}