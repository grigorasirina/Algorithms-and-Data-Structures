#include <iostream>
#include <list>
using namespace std;

// Graph class represents a directed graph using adjacency list representation
class Graph {
    int V; // Number of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists

public:
    Graph(int V); // Constructor

    // Function to add an edge to the graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices reachable from v
    void DFS(int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}

// DFS traversal from a given vertex v. It uses recursive DFSUtil()
void Graph::DFS(int v) {
    // Initially mark all vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create a stack for DFS
    list<int> stack;

    // Push the current source node.
    stack.push_back(v);

    while (!stack.empty()) {
        // Pop a vertex from stack and print it
        v = stack.back();
        stack.pop_back();

        // Stack may contain same vertex twice. So we need to print the popped item only
        // if it is not visited.
        if (!visited[v]) {
            cout << v << " ";
            visited[v] = true;
        }

        // Get all adjacent vertices of the popped vertex v
        // If an adjacent has not been visited, then push it to the stack.
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                stack.push_back(*i);
    }
}

// Driver code
int main() {
    // Create a graph given in the above diagram
    Graph g(4); // 4 vertices numbered from 0 to 3
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal starting from vertex 2:\n";
    g.DFS(2);

    return 0;
}
