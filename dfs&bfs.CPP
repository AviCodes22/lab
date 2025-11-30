#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];

int visited[MAX];

void createGraph(int n);
void BFS(int start, int n);
void DFS(int start, int n);

int main() {
    int n, start, i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    createGraph(n);

    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        int j;
        for(j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter starting vertex (0 to %d): ", n-1);
    scanf("%d", &start);

    for(i = 0; i < n; i++) 
    printf("\nBFS Traversal: ");
    BFS(start, n);

    for(i = 0; i < n; i++)
        visited[i] = 0;
    printf("\nDFS Traversal (Using Stack): ");
    DFS(start, n);

    printf("\n");
    return 0;
}

void createGraph(int n) {
    int i, j;
    printf("\nEnter adjacency matrix (1 = edge, 0 = no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j){
                graph[i][j] = 0;
                continue;
            }
                
            printf("Edge from %d to %d: ", i+1, j+1);
            scanf("%d", &graph[i][j]);
        }
    }
}

void BFS(int start, int n) {
    int queue[MAX], front = 0, rear = 0;
    int current, i;

    queue[rear] = start;
    rear++;
    visited[start] = 1;

    while (front < rear) {
        current = queue[front];
        front++;
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                queue[rear] = i;
                rear++;
                visited[i] = 1;
            }
        }
    }
}

void DFS(int start, int n) {
    int stack[MAX], top = -1;
    int node, i;

    stack[++top] = start ;
    visited[start] = 1;

    while (top != -1) {
        node = stack[top--];
        printf("%d ", node);

        for (i = n - 1; i >= 0; i--) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}