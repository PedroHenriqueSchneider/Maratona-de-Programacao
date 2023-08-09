#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int num = 0, positivo = 0, fim = 0, position = 0, contem = 0;
    vector <int> numero;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> num;
        numero.push_back(num);
        if(num == 5 || num == 0) {
            if(num == 0) {
                contem = 1;
            }
            positivo = 1;
        }
    }

    if(positivo == 0) {
        cout << -1 << "\n";
        return 0;
    }
    else{
        if(numero[n-1] > 5) {
            for(int i = 0; i < n; i++) {
                if(numero[i] == 5) {
                    numero[i] = numero[n-1];
                    numero[n-1] = 5;
                    break;
                }
                else if(numero[i] == 0) {
                    numero[i] = numero[n-1];
                    numero[n-1] = 0;
                    break;
                }
            }
        } else{
            if(contem == 1) {
                for(int i = 0; i < n; i++) {
                    if(numero[i] == 0) {
                        numero[i] = numero[n-1];
                        numero[n-1] = 0;
                        break;  
                    }
                }
            }
            else {
                for(int i = n-2; i > 0; i--) {
                    if(numero[i] == 5) {
                        numero[i] = numero[n-1];
                        numero[n-1] = 5; 
                        break;
                    }
                }
            }
        }

        for(int j = 0; j < n-1; j++) {
            cout << numero[j] << " ";
        }
        cout << numero[n-1];
        cout << "\n";
    }

    return 0;

}