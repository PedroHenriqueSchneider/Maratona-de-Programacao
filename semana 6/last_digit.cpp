#include <iostream>
using namespace std;

int lastDigit(int a, int b) {
    if (b == 0) return 1; // qualquer número elevado a 0 é 1
    int lastDigits[10][4] = {
        {0},         // a = 0
        {1},         // a = 1
        {0, 4, 6},   // a = 2
        {0, 3, 9, 7}, // a = 3
        {0, 6},      // a = 4
        {0, 5},      // a = 5
        {0, 6},      // a = 6
        {0, 7, 9, 3}, // a = 7
        {0, 8, 4},   // a = 8
        {0, 9, 1}    // a = 9
    };

    // Para a = 0 ou 1, o resultado é direto
    if (a == 0) return 0;
    if (a == 1) return 1;

    // Para a > 1, usamos a tabela lastDigits
    int index = (b - 1) % (lastDigits[a].size() - 1);
    return lastDigits[a][index + 1];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << lastDigit(a, b) << endl;
    }
    return 0;
}
