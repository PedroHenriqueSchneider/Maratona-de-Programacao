#include <iostream>
#include <vector>
#include <bitset>

const int maxn = 21;

std::bitset<maxn> bad[maxn];

int main()
{
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;

        u--;
        v--;

        bad[u][v] = true;
        bad[v][u] = true;
    }

    int ans = 0;

    for (int S = 1; S < (1 << n); S++)
    {
        bool isValid = true;

        for (int i = 0; i < n; i++)
        {
            if (S & (1 << i))
            {
                if ((bad[i] & std::bitset<maxn>(S)).any())
                {
                    isValid = false;
                    break;
                }
            }
        }

        if (isValid)
        {
            ans++;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}