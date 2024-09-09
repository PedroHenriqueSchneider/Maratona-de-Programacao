#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void dfs(char node, vector<vector<char>>& graph, vector<bool>& visited, set<char>& component) {
    visited[node - 'a'] = true; // Mark the node as visited
    component.insert(node); // Add node to the current component

    for (char neighbor : graph[node - 'a']) {
        if (!visited[neighbor - 'a']) {
            dfs(neighbor, graph, visited, component);
        }
    }
}

int main() {
    int T;
    cin >> T; // Number of test cases

    for (int caseNumber = 1; caseNumber <= T; ++caseNumber) {
        int V, E;
        cin >> V >> E; // Number of vertices and edges

        vector<vector<char>> graph(26); // Graph representation (up to 26 letters)

        // Read edges
        for (int i = 0; i < E; ++i) {
            char u, v;
            cin >> u >> v;
            graph[u - 'a'].push_back(v);
            graph[v - 'a'].push_back(u); // Assuming undirected edges
        }

        vector<bool> visited(26, false);
        vector<set<char>> components; // To store all components

        // Find all components using DFS
        for (char i = 'a'; i < 'a' + V; ++i) {
            if (!visited[i - 'a']) {
                set<char> component;
                dfs(i, graph, visited, component);
                components.push_back(component);
            }
        }

        // Output results
        cout << "Case #" << caseNumber << ":" << endl;
        for (const auto& component : components) {
            // Sort the component to ensure order
            vector<char> sortedComponent(component.begin(), component.end());
            sort(sortedComponent.begin(), sortedComponent.end());

            // Print the component
            for (size_t j = 0; j < sortedComponent.size(); ++j) {
                cout << sortedComponent[j];
                if (j < sortedComponent.size() - 1) {
                    cout << ",";
                }
            }
            cout << "," << endl; // Ending with a comma
        }
        cout << components.size() << " components" << endl << endl; // Number of components
    }

    return 0;
}
