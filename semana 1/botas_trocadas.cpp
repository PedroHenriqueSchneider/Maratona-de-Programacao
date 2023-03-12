#include <iostream>
using namespace std;

int main()
{
    // Seu código vai aqui
    int N, M, contador = 0;
    char L;

    cin >> N;

    int numeros[N];
    char pares[N];

    for (int i = 0; i < N; i++)
    {
        cin >> M >> L;
        numeros[i] = M;
        pares[i] = L;
    }

    for(int k = 0; k < N; k++) {
        for(int j = 0; j < N; j++) {
            if(numeros[k] == numeros[j]) {
                if(pares[k] != pares[j]) {
                    pares[k] = 'c';
                    pares[j] = 'c';
                    contador++;
					numeros[k] = 0;
					numeros[j] = 0;
                }
            }
        }
    }

    cout << contador;
    return 0;
}
