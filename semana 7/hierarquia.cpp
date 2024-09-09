#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void pathR(const vector<vector<int>>& graph, int node, vector<bool>& visited, int depth) {
    visited[node] = true;

    // Indentation based on depth
    for (int i = 0; i < depth; i++) {
        cout << "b"; // b represents a space
    }
    cout << node; // Print the current node

    // Print the edges of the current node
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            cout << "-" << neighbor; // Print the connection to the neighbor
        }
    }
    cout << " pathR(G," << node << ")" << endl; // End of current node's output

    // Recursion to the neighbors
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            pathR(graph, neighbor, visited, depth + 1);
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> graph(V);
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u); // Assuming it's an undirected graph
        }

        vector<bool> visited(V, false);

        // Start DFS from each unvisited node (to handle disconnected components)
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                pathR(graph, i, visited, 0);
            }
        }
        cout << endl; // Blank line after each case
    }

    return 0;
}
