#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(int q) {

    int num = 0, altura = 0;

    if(q == 1) {
        return 1;
    }

    for(int i = 1; num <= q; i++) { 

        num += i;
        altura = i;
    }
    return altura;
}

int main()
{
    int n = 0, q = 0, t = 0;

    cin >> n; 

    for(int i = 0; i < n; i++) {
        cin >> q;
        t = calc(q);
        if(t == 1)
            cout << 1 << '\n';
        else {
            t = t - 1;
            cout << t << '\n';
        }
    }
}
