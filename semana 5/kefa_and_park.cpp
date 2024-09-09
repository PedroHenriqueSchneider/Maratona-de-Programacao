#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Lista de adjacências
vector<int> cats;        // Armazena se cada vértice tem gato ou não
int n, m;                // Número de vértices e limite de gatos consecutivos
int result = 0;          // Contador de restaurantes válidos

// Função DFS para explorar a árvore
void dfs(int node, int parent, int consecutive_cats) {
    if (cats[node] == 1) {
        consecutive_cats++;
    } else {
        consecutive_cats = 0; // Reiniciar o contador se não houver gato
    }

    // Se o número de gatos consecutivos exceder o limite, pare
    if (consecutive_cats > m) return;

    bool is_leaf = true;

    // Explorar os vizinhos
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            is_leaf = false;
            dfs(neighbor, node, consecutive_cats);
        }
    }

    // Se for folha, incrementar o resultado
    if (is_leaf) result++;
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    cats.resize(n + 1);

    // Leitura da linha com as informações sobre gatos em cada vértice
    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }

    // Leitura das arestas da árvore
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Começamos a DFS do vértice 1 (a casa de Kefa)
    dfs(1, -1, 0);

    // Imprimir o número de restaurantes válidos
    cout << result << endl;

    return 0;
}
