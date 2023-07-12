#include <bits/stdc++.h>
using namespace std;

int main() {
    int val = 0;
    vector<int> par;
    vector<int> impar;

    for (int i = 0; i < 15; i++) {
        cin >> val;
        if (val % 2 == 0) {
            par.push_back(val);
            if (par.size() == 5) {
                for (int j = 0; j < 5; j++) {
                    cout << "par[" << j << "] = " << par[j] << "\n";
                }
                par.clear();
            }
        } else {
            impar.push_back(val);
            if (impar.size() == 5) {
                for (int j = 0; j < 5; j++) {
                    cout << "impar[" << j << "] = " << impar[j] << "\n";
                }
                impar.clear();
            }
        }
    }

    for (int j = 0; j < impar.size(); j++) {
        cout << "impar[" << j << "] = " << impar[j] << "\n";
    }

    for (int j = 0; j < par.size(); j++) {
        cout << "par[" << j << "] = " << par[j] << "\n";
    }

    return 0;
}
