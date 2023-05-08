#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long int n, m;
    long long int esq = 0, meio, partes_cortadas, altura_maxima;
    cin >> n >> m;

    vector<long long int> alturas(n);

    long long int maior_altura = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> alturas[i];
        if (alturas[i] > maior_altura)
        {
            maior_altura = alturas[i];
        }
    }

    long long int dir = maior_altura;

    while (esq <= dir)
    {
        meio = (esq + dir) / 2;
        partes_cortadas = 0;

        for (int i = 0; i < n; i++)
        {
            if (alturas[i] > meio)
            {
                partes_cortadas += alturas[i] - meio;
            }
        }

        if (partes_cortadas >= m)
        {
            altura_maxima = meio;
            esq = meio + 1;
        }
        else
        {
            dir = meio - 1;
        }
    }

    cout << altura_maxima << endl;

    return 0;
}
