#include <iostream>
#include <cmath>
using namespace std;

// w é o número de pebbles de um certo tipo i 
// 

int main() {
    int n = 0, k = 0, dias = 0;
    cin >> n >> k;

    int bolso = 0;

    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        bolso += ceil((double)w/k); // double pra não dar conflito
    }

    dias = ceil((double)bolso/2);
    cout << dias << endl;

    return 0;
}
