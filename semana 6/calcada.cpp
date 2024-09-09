#include <iostream>
#include <cmath>
using namespace std;

// Função para calcular o máximo divisor comum
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int T;
    cin >> T;  // Lê o número de casos de teste

    while (T--) {
        long long A, B, C, D;
        cin >> A >> B >> C >> D;  // Lê as coordenadas A, B, C, D

        long long dx = abs(A - C);  // Diferença em X
        long long dy = abs(B - D);  // Diferença em Y

        // Calcula o número de interseções
        long long intersections = dx + dy - gcd(dx, dy);
        cout << intersections << endl;  // Imprime o resultado
    }

    return 0;
}
