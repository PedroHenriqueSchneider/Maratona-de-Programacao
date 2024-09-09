#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int n, m;

// Função para verificar se o grafo é conexo usando DFS
void DFS(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            DFS(u);
        }
    }
}

// Função principal
int main() {
    cin >> n >> m;

    // Se o número de arestas não for igual ao número de vértices, já podemos retornar "NO"
    if (m != n) {
        cout << "NO" << endl;
        return 0;
    }

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    // Leitura das arestas
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Verificamos se o grafo é conexo
    DFS(1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    // Agora verificamos se há exatamente um ciclo usando a condição de que m == n
    // Se o grafo é conexo e tem exatamente n arestas, então tem exatamente um ciclo
    cout << "FHTAGN!" << endl;

    return 0;
}
