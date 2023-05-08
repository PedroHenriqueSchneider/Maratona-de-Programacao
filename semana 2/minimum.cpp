#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> numeros;

    int qtd_numeros = 0, tam_vetor = 0, numero = 0, maior = 0, soma = 0;

    cin >> qtd_numeros;

    for (int i = 0; i < qtd_numeros; i++)
    {
        soma = 0;
        cin >> tam_vetor;
        numeros.clear();
        for (int k = 0; k < tam_vetor; k++)
        {
            cin >> numero;
            numeros.push_back(numero);
        }
        sort(numeros.begin(), numeros.end());

        maior = numeros[0];

        for (int j = 0; j < tam_vetor; j++)
        {
            numeros[j] -= soma;
            soma += numeros[j];

            if(numeros[j] > maior) {
                maior = numeros[j];
            }
        }
        cout << maior << "\n";
        
    }
    return 0;
}