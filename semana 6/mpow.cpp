#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

void multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
            for (int k = 0; k < size; k++) {
                C[i][j] = (C[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }
}

void matrixPower(const vector<vector<int>>& matrix, int power, vector<vector<int>>& result, int size) {
    // Initialize result as the identity matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j)
                result[i][j] = 1;
            else
                result[i][j] = 0;
        }
    }

    vector<vector<int>> temp = matrix;

    while (power) {
        if (power % 2 == 1) {
            multiplyMatrices(result, temp, result, size);
        }
        multiplyMatrices(temp, temp, temp, size);
        power /= 2;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int M, N;
        cin >> M >> N;

        vector<vector<int>> matrix(M, vector<int>(M));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }

        vector<vector<int>> result(M, vector<int>(M));
        matrixPower(matrix, N, result, M);

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
