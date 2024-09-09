#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// Estrutura para representar uma posição no tabuleiro
struct Position {
    int x, y, moves; // coordenadas e número de movimentos
};

// Movimentos possíveis do cavalo
const vector<pair<int, int>> knightMoves = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

// Verifica se a posição está dentro do tabuleiro
bool isValid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// Função para converter a posição do tabuleiro de string para coordenadas
Position convertPosition(const string& pos) {
    int x = pos[0] - 'a'; // coluna
    int y = pos[1] - '1'; // linha
    return {x, y, 0}; // inicializa os movimentos como 0
}

// Função para calcular o número mínimo de movimentos do cavalo
int bfs(Position start, Position end) {
    queue<Position> q;
    vector<vector<bool>> visited(8, vector<bool>(8, false));

    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        Position current = q.front();
        q.pop();

        // Se chegamos à posição de destino
        if (current.x == end.x && current.y == end.y) {
            return current.moves; // retorna o número de movimentos
        }

        // Explora os movimentos do cavalo
        for (const auto& move : knightMoves) {
            int newX = current.x + move.first;
            int newY = current.y + move.second;

            if (isValid(newX, newY) && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({newX, newY, current.moves + 1});
            }
        }
    }
    return -1; // Em caso de não encontrar (não deve acontecer no tabuleiro)
}

int main() {
    string startPos, endPos;
    while (cin >> startPos >> endPos) {
        Position start = convertPosition(startPos);
        Position end = convertPosition(endPos);
        int moves = bfs(start, end);
        cout << "To get from " << startPos << " to " << endPos << " takes " << moves << " knight moves." << endl;
    }
    return 0;
}
