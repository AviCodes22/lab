#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * @brief Performs Breadth-First Search (BFS) on a graph.
 * @param startNode The vertex from which to start the traversal.
 * @param numVertices The total number of vertices in the graph.
 * @param adj The adjacency list representation of the graph.
 */
void BFS(int startNode, int numVertices, const vector<vector<int>>& adj) {
    if (startNode >= numVertices || startNode < 0) {
        cout << "Error: Invalid starting node." << endl;
        return;
    }

    // A vector to keep track of visited vertices, initialized to false.
    vector<bool> visited(numVertices, false);
    // A queue for the BFS algorithm.
    queue<int> q;

    // Mark the starting node as visited and enqueue it.
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal starting from node " << startNode << ": ";

    while (!q.empty()) {
        // Dequeue a vertex from the queue and print it.
        int u = q.front();
        q.pop();
        cout << u << " ";

        // Get all adjacent vertices of the dequeued vertex u.
        // If an adjacent vertex has not been visited, mark it visited and enqueue it.
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

int main() {
    int numVertices = 0;
    vector<vector<int>> adj;
    int choice;

    do {
        cout << "\n--- Graph Traversal Menu ---" << endl;
        cout << "1. Read Graph" << endl;
        cout << "2. BFS Traversal" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int numEdges;
                cout << "Enter the number of vertices: ";
                cin >> numVertices;
                cout << "Enter the number of edges: ";
                cin >> numEdges;

                // Resize the adjacency list to hold all vertices.
                adj.assign(numVertices, vector<int>());

                cout << "Enter the edges (format: u v):" << endl;
                for (int i = 0; i < numEdges; ++i) {
                    int u, v;
                    cin >> u >> v;
                    // Assuming an undirected graph
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
                cout << "Graph has been read successfully." << endl;
                break;
            }
            case 2: {
                if (numVertices == 0) {
                    cout << "Please read a graph first (Option 1)." << endl;
                } else {
                    int startNode;
                    cout << "Enter the starting node for BFS: ";
                    cin >> startNode;
                    BFS(startNode, numVertices, adj);
                }
                break;
            }
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}