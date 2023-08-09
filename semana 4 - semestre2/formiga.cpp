#include <bits/stdc++.h>
using namespace std;

const int MAX = 210;

int S, T, P;
int altura[MAX];
int distancia[MAX];
vector<int> adj[MAX];

// Função recursiva para realizar a busca e calcular as distâncias máximas
int busca(int k)
{
    if (distancia[k] == -1)
    {
        distancia[k] = 0;
        for (auto q : adj[k])
        {
            distancia[k] = max(1 + busca(q), distancia[k]);
        }
    }
    return distancia[k];
}

int main()
{
    int i, a, b;

    scanf("%d%d%d", &S, &T, &P);

    for (i = 0; i < S; i++)
        scanf("%d", &altura[i]);

    // Lendo as informações das trilhas e construindo as conexões no vetor de adjacência
    for (i = 0; i < T; i++)
    {
        scanf("%d%d", &a, &b);
        a--;
        b--;
        if (altura[a] > altura[b])
            adj[a].push_back(b);
        else if (altura[a] < altura[b])
            adj[b].push_back(a);
    }

    // Inicializando o array de distâncias com -1
    memset(distancia, -1, sizeof(distancia));

    printf("%d\n", busca(P - 1));

    return 0;
}