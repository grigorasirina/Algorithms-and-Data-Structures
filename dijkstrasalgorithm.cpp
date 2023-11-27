#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX
using namespace std;

// Define the maximum number of vertices in the graph
const int MAX_VERTICES = 6;

// Function to find the vertex with the minimum distance which is not yet included in the shortest path tree
int minDistance(const vector<int>& dist, const vector<bool>& sptSet) {
    // Initialize minimum value
    int min = INT_MAX, min_index;

    for (int v = 0; v < MAX_VERTICES; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printSolution(const vector<int>& dist) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < MAX_VERTICES; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src) {
    vector<int> dist(MAX_VERTICES, INT_MAX); // Output array. dist[i] will hold the shortest distance from src to i

    vector<bool> sptSet(MAX_VERTICES, false); // sptSet[i] will be true if vertex i is included in shortest path tree

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < MAX_VERTICES - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < MAX_VERTICES; v++) {
            // Update dist[v] only if it's not in sptSet, there is an edge from u to v, and
            // total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist);
}

// Main function
int main() {
    // Example graph represented as an adjacency matrix
    int graph[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 4, 0, 0, 0},
                                             {1, 0, 4, 2, 7, 0},
                                             {4, 4, 0, 3, 5, 0},
                                             {0, 2, 3, 0, 4, 6},
                                             {0, 7, 5, 4, 0, 7},
                                             {0, 0, 0, 6, 7, 0}};

    // Call Dijkstra's algorithm function
    dijkstra(graph, 0); // 0 is the source vertex

    return 0;
}
