#include <iostream>

using namespace std;

int main()
{
    // Seu código vai aqui
    // peso do cruzamento: a soma de todos os elementos que estejam na linha i ou na coluna j, mas não nas duas
    // exclui da conta o elemento do matriz[i][j] e matriz[j][i]

    int N = 0, numero = 0;

    cin >> N;

    int tabuleiro[N][N];

    int soma_linha[N], soma_coluna[N], soma_maxima_linha = 0, soma_maxima_coluna = 0, peso_maximo = 0;

    for (int k = 0; k < N; k++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> numero;
            tabuleiro[k][j] = numero;
        }
    }

    for(int i = 0; i < N; i++) {
        soma_linha[i] = 0;
        soma_coluna[i] = 0;
    }

    for (int k = 0; k < N; k++)
    {
        for (int j = 0; j < N; j++)
        {
                soma_linha[k] += tabuleiro[k][j];
                soma_coluna[k] += tabuleiro[j][k];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int k = 0 ; k < N; k++) {
            soma_maxima_linha = soma_linha[i];
            soma_maxima_linha -= tabuleiro[i][k];
            soma_maxima_coluna = soma_coluna[k];
            soma_maxima_coluna -= tabuleiro[i][k];
            if(soma_maxima_coluna + soma_maxima_linha > peso_maximo) {
                peso_maximo = soma_maxima_coluna + soma_maxima_linha;
            }
        }
    }

    printf("%d\n", peso_maximo);

    return 0;
}
