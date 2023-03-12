#include <iostream>

using namespace std;

int main()
{
    // Seu código vai aqui
    int N, numero, soma_linhas = 0, soma_colunas = 0, soma_diagonais = 0;
    cin >> N;
    int quadrado[N][N];
    int contador = N;

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            cin >> numero;
            quadrado[i][k] = numero;
        }
    }
    numero = 0;

    for (int i = 0; i < N; i++)
    {
        soma_linhas = 0;
        soma_colunas = 0;
        for (int j = 0; j < N; j++)
        {
            soma_linhas += quadrado[i][j];
            soma_colunas += quadrado[j][i];
        }
        if(soma_linhas != soma_colunas) {
            cout << ("-1\n");
            exit(0);
        }
    }
    for (int j = 0; j < N; j++)
    {
        soma_diagonais += quadrado[j][j];
    }
    numero = soma_diagonais;
    soma_diagonais = 0;
    for (int j = 0; j < N; j++)
    {
        soma_diagonais += quadrado[j][contador-1];
        contador--;
    }

    if(soma_diagonais != numero) {
         cout << "-1\n";
         exit(0);
    }
    else if(soma_diagonais == soma_colunas && soma_diagonais == soma_linhas) {
        cout << soma_diagonais << endl;
        exit(0);
    }

    else {
        cout << "-1\n";
        exit(0);
    }

    return 0;
}
