#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N > 1) {
        for (int i = 2; i * i <= N; i++) {
            if (N % i == 0 && N / i > 1) {
                cout << 'S' << endl;
                return 0;
            }
        }
    }
    cout << 'N' << endl;
    return 0;
}
