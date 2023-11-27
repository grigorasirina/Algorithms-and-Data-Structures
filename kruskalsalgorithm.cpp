#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

class Graph {
private:
    int V; // Number of vertices
    vector<Edge> edges; // Vector to store edges

public:
    Graph(int vertices) : V(vertices) {}

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }

    // Function to find the parent of a vertex
    int findParent(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return findParent(parent, parent[i]);
    }

    // Function to perform union of two sets
    void unionSets(vector<int>& parent, int x, int y) {
        int xRoot = findParent(parent, x);
        int yRoot = findParent(parent, y);
        parent[xRoot] = yRoot;
    }

    // Kruskal's algorithm to find the minimum spanning tree
    void kruskalMST() {
        vector<Edge> result; // Stores the edges in the minimum spanning tree
        int i = 0; // Index for iterating through sorted edges
        int edgeCount = 0; // Counter for edges included in the MST

        // Sort edges in non-decreasing order of their weights
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        vector<int> parent(V);

        // Initialize each vertex as its own parent
        for (int v = 0; v < V; v++) {
            parent[v] = v;
        }

        // Iterate through sorted edges and add them to the MST if they don't form a cycle
        while (edgeCount < V - 1 && i < edges.size()) {
            Edge nextEdge = edges[i++];
            int x = findParent(parent, nextEdge.src);
            int y = findParent(parent, nextEdge.dest);

            if (x != y) {
                result.push_back(nextEdge);
                unionSets(parent, x, y);
                edgeCount++;
            }
        }

        // Print the edges in the minimum spanning tree
        cout << "Edges in the Minimum Spanning Tree:" << endl;
        for (const Edge& edge : result) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
        }
    }
};

int main() {
    int V = 4; // Number of vertices in the graph
    Graph g(V);

    // Adding edges to the graph
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    // Find and print the Minimum Spanning Tree
    g.kruskalMST();

    return 0;
}
