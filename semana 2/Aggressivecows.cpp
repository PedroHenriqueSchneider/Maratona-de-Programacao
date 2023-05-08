#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int aloca(const vector<int>& estab, int vacas, int dist);

int maiordist(const vector<int>& estab, int vacas);

int maiordist(const vector<int>& estab, int vacas) {
    int ini = 1, fim = estab[estab.size()-1]-estab[0], resultado = -1;
    
    while (ini <= fim) {

        int meio = ini + (fim - ini) / 2;

        if (aloca(estab, vacas, meio) == 1) {

            resultado = meio;
            ini = meio + 1;

        } else {

            fim = meio - 1;

        }
    }
    return resultado;
}

int aloca(const vector<int>& estab, int vacas, int dist) {

    int pos = estab[0], vaca = 1;
    
    for (int i = 1; i < estab.size(); i++) {

        if (estab[i] - pos >= dist) {

            pos = estab[i];
            vaca++;

        }
        if (vaca == vacas) {

            return 1;

        }
    }
    return -1;
}

int main() {
    int t = 0, n = 0, c = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {

        cin >> n >> c;

        vector<int> estab(n);
        for (int i = 0; i < n; i++) {
            cin >> estab[i];
        }

        sort(estab.begin(), estab.end());

        cout << maiordist(estab, c) << endl;
    }

    return 0;
}
