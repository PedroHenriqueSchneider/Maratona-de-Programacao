#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int soma_maxima = arr[0], soma_atual = arr[0];

        for (int i = 1; i < n; i++) {
            soma_atual = max(arr[i], soma_atual + arr[i]); // pega o maior entre o elemento atual do array e a soma atual mais o elemento do array 
            soma_maxima = max(soma_maxima, soma_atual); // maior entre a soma maxima e a soma atual
        }

        cout << soma_maxima << endl;
    }

    return 0;
}
