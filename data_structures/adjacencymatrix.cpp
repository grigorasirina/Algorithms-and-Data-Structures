#include <iostream>
using namespace std;

const int MAX = 5; // Maximum number of vertices in the graph

// Function to add an edge in an undirected graph
void addEdge(int adjMatrix[][MAX], int u, int v) {
    // Inserting an edge between u and v.
    // For an undirected graph, we will have a symmetric matrix.
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

// Function to print the adjacency matrix
void printAdjMatrix(int adjMatrix[][MAX]) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    // Adjacency matrix representation of the graph
    int adjMatrix[MAX][MAX] = {0}; // Initialize with 0s

    // Adding edges
    // The graph is undirected and unweighted
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 4);

    // Printing the adjacency matrix
    printAdjMatrix(adjMatrix);

    return 0;
}
