#include <bits/stdc++.h>
using namespace std;

int main() {

    double valor = 0;
    int n100 = 0, n50 = 0, n20 = 0, n10 = 0, n5 = 0, n2 = 0;
    int m100 = 0, m50 = 0, m20 = 0, m10 = 0, m5 = 0, m2 = 0;
    cin >> valor;
    valor += 0.001;

    n100 = valor / 100;
    valor -= n100 * 100;
    n50 = valor / 50;
    valor -= n50 * 50;
    n20 = valor / 20;
    valor -= n20 * 20;
    n10 = valor / 10;
    valor -= n10 * 10;
    n5 = valor / 5;
    valor -= n5 * 5;
    n2 = valor / 2;
    valor -= n2 * 2;

    m100 = valor / 1;
    valor -= m100 * 1;
    m50 = valor / 0.5;
    valor -= m50 * 0.5;
    m20 = valor / 0.25;
    valor -= m20 * 0.25;
    m10 = valor / 0.1;
    valor -= m10 * 0.1;
    m5 = valor / 0.05;
    valor -= m5 * 0.05;
    m2 = valor / 0.01;
    valor -= m2 * 0.01;

    cout << "NOTAS:" << "\n";
    cout << n100 << " nota(s) de R$ 100.00" << "\n";
    cout << n50 << " nota(s) de R$ 50.00" << "\n";
    cout << n20 << " nota(s) de R$ 20.00" << "\n";
    cout << n10 << " nota(s) de R$ 10.00" << "\n";
    cout << n5 << " nota(s) de R$ 5.00" << "\n";
    cout << n2 << " nota(s) de R$ 2.00" << "\n";
    cout << "MOEDAS:" << "\n";
    cout << m100 << " moeda(s) de R$ 1.00" << "\n";
    cout << m50 << " moeda(s) de R$ 0.50" << "\n";
    cout << m20 << " moeda(s) de R$ 0.25" << "\n";
    cout << m10 << " moeda(s) de R$ 0.10" << "\n";
    cout << m5 << " moeda(s) de R$ 0.05" << "\n";
    cout << m2 << " moeda(s) de R$ 0.01" << "\n";
    
    return 0;
}