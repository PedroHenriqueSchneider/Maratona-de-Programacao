#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dist;

pair<int, int> bfs(int start, int n) {
    dist.assign(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthest = start;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > dist[farthest]) {
                    farthest = v;
                }
            }
        }
    }

    return {farthest, dist[farthest]};
}

int main() {
    int N;

    while (cin >> N && N != 0) {
        adj.assign(N + 1, vector<int>());

        for (int i = 0; i < N - 1; ++i) {
            int X, Y;
            cin >> X >> Y;
            adj[X].push_back(Y);
            adj[Y].push_back(X);
        }

        pair<int, int> p1 = bfs(1, N);
        pair<int, int> p2 = bfs(p1.first, N);
        int diameter = p2.second;
        int center = p2.first;

        for (int i = 0; i <= N; ++i) {
            if (dist[i] == diameter / 2 || dist[i] == (diameter + 1) / 2) {
                center = i;
                break;
            }
        }

        cout << center << endl;
    }

    return 0;
}
