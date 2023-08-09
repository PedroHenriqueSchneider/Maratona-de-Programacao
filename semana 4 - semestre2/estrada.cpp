#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double solve(int t, int n, vector<double> x) {
    
    double soma = 0, max = 0;

    sort(x.begin(), x.end());

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            soma = (x[i] + x[i+1]) / 2.0; 
            max = soma;
        }
        else if(i == n-1) {
            soma = ((x[i] - x[i-1]) /2 + (t - x[i]));
        }
        else {
            soma = (x[i] - x[i-1]) / 2.0 + (x[i+1] - x[i]) / 2.0;
        }

        if(soma < max) {
            max = soma;
        }
    }

    return max;
}

int main() {
    int t, n;
    cin >> t >> n;
    vector<double> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << fixed << setprecision(2) << solve(t, n, x) << endl;
    return 0;
}
