#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> grafo(N + 1);

    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        grafo[A].push_back({B, C});
        grafo[B].push_back({A, C});
    }

    vector<int> distancia(N + 1, INF);
    distancia[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int custo = pq.top().first;
        int no = pq.top().second;
        pq.pop();

        if (custo > distancia[no]) continue;

        for (const auto& aresta : grafo[no]) {
            int vizinho = aresta.first;
            int peso = aresta.second;

            if (distancia[no] + peso < distancia[vizinho]) {
                distancia[vizinho] = distancia[no] + peso;
                pq.push({distancia[vizinho], vizinho});
            }
        }
    }

    cout << distancia[N] << endl;

    return 0;
}
