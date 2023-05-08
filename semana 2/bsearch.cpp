#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bsearch(const vector<int>& v, int elemento);

int main()
{
    int N = 0, Q = 0;

    scanf("%d %d", &N, &Q);

    vector<int> numbers(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &numbers[i]);
    }

    for(int i = 0; i < Q; i++) {
        int numero;
        scanf("%d", &numero);
        printf("%d\n", bsearch(numbers, numero));
    }

    return 0;
}

int bsearch(const vector<int>& v, int elemento)
{
    int inicio = 0;
    int fim = v.size() - 1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;

        if (v[meio] == elemento)
        {
            // Procurando pelo índice da primeira ocorrência
            while (meio > 0 && v[meio-1] == elemento)
            {
                meio--;
            }
            return meio;
        }
        else if (v[meio] < elemento)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    return -1;
}
