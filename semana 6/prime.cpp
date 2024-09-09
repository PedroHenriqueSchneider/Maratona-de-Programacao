#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sieve_of_eratosthenes(int limit) {
    vector<bool> is_prime(limit + 1, true);
    vector<int> primes;

    is_prime[0] = is_prime[1] = false; // 0 e 1 não são primos
    for (int p = 2; p * p <= limit; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= limit; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

void segmented_sieve(int m, int n) {
    vector<bool> is_prime(n - m + 1, true);
    vector<int> primes = sieve_of_eratosthenes(sqrt(n));

    for (int prime : primes) {
        // Encontra o menor múltiplo de `prime` no intervalo [m, n]
        int start = max(prime * prime, (m + prime - 1) / prime * prime);
        for (int j = start; j <= n; j += prime) {
            is_prime[j - m] = false;
        }
    }

    for (int i = m; i <= n; ++i) {
        if (is_prime[i - m] && i > 1) {
            cout << i << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int m, n;
        cin >> m >> n;

        segmented_sieve(m, n);

        if (i < t - 1) {
            cout << endl; // linha em branco entre os casos de teste
        }
    }

    return 0;
}
