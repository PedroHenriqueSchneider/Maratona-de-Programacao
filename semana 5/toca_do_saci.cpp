#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> mapa;
vector<vector<int>> dist;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int BFS(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        if (current == end) {
            return dist[end.first][end.second];
        }

        for (int i = 0; i < 4; i++) {
            int newX = current.first + dx[i];
            int newY = current.second + dy[i];

            if (isValid(newX, newY) && mapa[newX][newY] != 0 && dist[newX][newY] == -1) {
                dist[newX][newY] = dist[current.first][current.second] + 1;
                q.push({newX, newY});
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> M;
    mapa.resize(N, vector<int>(M));
    dist.resize(N, vector<int>(M, -1));

    pair<int, int> start, end;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mapa[i][j];
            if (mapa[i][j] == 2) {
                start = {i, j};
            } else if (mapa[i][j] == 3) {
                end = {i, j};  //
            }
        }
    }

    int result = BFS(start, end);

    cout << result << endl;

    return 0;
}
