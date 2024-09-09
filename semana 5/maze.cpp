#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<string> maze;
vector<vector<bool>> visited;
vector<pair<int, int>> empty_cells;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// Função de DFS para percorrer o labirinto
void dfs(int x, int y) {
    visited[x][y] = true;
    empty_cells.push_back({x, y});

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && maze[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    maze.resize(n);
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }

    // Encontrar uma célula vazia inicial para começar o DFS
    bool found = false;
    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < m && !found; j++) {
            if (maze[i][j] == '.') {
                dfs(i, j);
                found = true;
            }
        }
    }

    // Transformar as últimas k células vazias encontradas em paredes 'X'
    int cells_to_fill = k;
    for (int i = empty_cells.size() - 1; i >= 0 && cells_to_fill > 0; i--, cells_to_fill--) {
        maze[empty_cells[i].first][empty_cells[i].second] = 'X';
    }

    // Imprimir o labirinto modificado
    for (int i = 0; i < n; i++) {
        cout << maze[i] << endl;
    }

    return 0;
}
