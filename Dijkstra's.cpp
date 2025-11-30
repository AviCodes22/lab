#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

// Function to pick minimum distance unvisited vertex
int minDistance(int dist[], int visited[], int noOfVertices) {
    int min = INF;
    int min_index = -1;

    for (int v = 0; v < noOfVertices; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}


// Dijkstra using adjacency matrix
void dijkstra(int graph[MAX][MAX], int noOfVertices, int src) {
    int dist[MAX], visited[MAX];

    for (int i = 0; i < noOfVertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < noOfVertices - 1; count++) {

        int u = minDistance(dist, visited, noOfVertices);
        visited[u] = 1;

        for (int v = 0; v < noOfVertices; v++) {
            if (visited[v] == 0 && graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", src);
    for (int i = 0; i < noOfVertices; i++) {
        if (dist[i] == INF)
            printf("To vertex %d = INF\n", i );
        else
            printf("To vertex %d = %d\n", i , dist[i]);
    }
}

int main() {
    int noOfVertices, src, type;
    int graph[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &noOfVertices);

    printf("Enter 1 for Directed Graph\nEnter 2 for Undirected Graph\n");
    printf("Enter type: ");
    scanf("%d", &type);

    //  Directed graph 
    if (type == 1) {
        printf("\nEnter Edge Information:\n");
        for (int i = 0; i < noOfVertices; i++) {
            for (int j = 0; j < noOfVertices; j++) {

                if (i == j) {
                    graph[i][j] = 0;
                    continue;
                }
                if (j < i)  
                    continue;

                int choice, weight;

                printf("\nFor vertices %d and %d:\n", i, j);
                printf("1. %d -> %d\n", i, j);
                printf("2. %d -> %d\n", j, i);
                printf("3. No edge\n");
                printf("Enter choice: ");
                scanf("%d", &choice);

                if (choice == 1) {
                    printf("Enter weight: ");
                    scanf("%d", &weight);
                    graph[i][j] = weight;
                    graph[j][i] = 0;
                }
                else if (choice == 2) {
                    printf("Enter weight: ");
                    scanf("%d", &weight);
                    graph[i][j] = 0;
                    graph[j][i] = weight;
                }
                else {
                    graph[i][j] = 0;
                    graph[j][i] = 0;
                }
            }
        }
    }

    // Undirected graph
    else if (type == 2) {
        printf("\nEnter Edge Weights (0 for no edge):\n");
        for (int i = 0; i < noOfVertices; i++) {
            for (int j = 0; j < noOfVertices; j++) {

                if (i == j) {
                    graph[i][j] = 0;
                    continue;
                }
                if (j < i)   // copy previous weight
                {
                    graph[i][j] = graph[j][i];
                    continue;
                }

                printf("Weight between %d and %d: ", i, j);
                scanf("%d", &graph[i][j]);
                graph[j][i] = graph[i][j]; // mirror
            }
        }
    }

    printf("\nEnter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, noOfVertices, src);

    return 0;
}