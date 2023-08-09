#include <iostream>
using namespace std;

int main()
{
    int n, t;

    cin >> n >> t;

    if (t == 0)
    {
        cout << n << endl;
    }
    else
    {
        int x = 1;

        // Loop para calcular x usando o produto dos números (n - i) para i de 0 a t
        for (int i = 0; i <= t; i++)
        {
            x *= (n - i);
        }

        if (t == 2)
        {
            x /= 6;
        }

        cout << x << endl;
    }

    return 0;
}