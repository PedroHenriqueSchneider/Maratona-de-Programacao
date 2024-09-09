#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>

using namespace std;

struct Graph {
    int N; // número de pontos estratégicos
    vector<vector<int>> adj; // lista de adjacência
    vector<int> snipers; // número de atiradores em cada ponto

    Graph(int n) : N(n), adj(n + 1), snipers(n + 1, 0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // grafo não direcionado
    }

    void setSnipers(int pos, int count) {
        snipers[pos] = count;
    }

    int getSnipers(int pos) {
        return snipers[pos];
    }
};

double bfs(Graph& graph, int start, int end, int K, double P) {
    queue<pair<int, int>> q; // (ponto atual, balas restantes)
    vector<bool> visited(graph.N + 1, false);
    q.push({start, K});
    visited[start] = true;

    double maxProbability = 0.0;

    while (!q.empty()) {
        auto [current, bullets] = q.front();
        q.pop();

        // Calcule a probabilidade atual considerando os atiradores no ponto atual
        int snipersAtCurrent = graph.getSnipers(current);
        if (bullets < snipersAtCurrent) {
            continue; // não podemos matar todos os atiradores
        }

        // Calcule a nova probabilidade após lidar com os atiradores
        double newProbability = pow(P, snipersAtCurrent) * pow((1 - P), bullets - snipersAtCurrent);

        if (current == end) {
            maxProbability = max(maxProbability, newProbability);
            continue;
        }

        for (int neighbor : graph.adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, bullets - snipersAtCurrent});
            }
        }
    }

    return maxProbability;
}

int main() {
    int N, M, K;
    double P;

    while (cin >> N >> M >> K >> P) {
        Graph graph(N);

        // Leitura das estradas
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            graph.addEdge(u, v);
        }

        // Leitura dos atiradores
        int A;
        cin >> A;
        for (int i = 0; i < A; ++i) {
            int position;
            cin >> position;
            graph.setSnipers(position, graph.getSnipers(position) + 1);
        }

        // Leitura dos pontos de partida e destino
        int start, end;
        cin >> start >> end;

        // Cálculo da probabilidade de sucesso
        double probability = bfs(graph, start, end, K, P);
        cout << fixed << setprecision(3) << probability << endl;
    }

    return 0;
}
