#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visitados;
void DFS(int v) {
    visitados[v] = true;
    for (int u : adj[v]) {
        if (!visitados[u]) {
            DFS(u);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    adj.resize(N + 1);
    visitados.resize(N + 1, false);

    for (int i = 0; i < M; i++) {
        int I, J;
        cin >> I >> J;
        adj[I].push_back(J);  // Adiciona uma aresta entre I e J
        adj[J].push_back(I);  // Adiciona uma aresta entre J e I (não-direcionado)
    }

    int times = 0;  // Variável para contar o número de componentes conexos

    // Para cada vértice, se ele não foi visitado, inicie uma DFS
    for (int i = 1; i <= N; i++) {
        if (!visitados[i]) {
            DFS(i);  // Chama DFS a partir do vértice não visitado
            times++;  // Incrementa o número de times (componentes conexos)
        }
    }

    // Imprime o número máximo de times que podem ser formados
    cout << times << endl;

    return 0;
}
