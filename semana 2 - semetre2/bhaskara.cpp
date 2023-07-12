#include <bits/stdc++.h>
 
using namespace std;

int main() {

    double a = 0, b = 0, c = 0, delta = 0, x1 = 0, x2 = 0;

    cin >> a >> b >> c;

    if(a == 0) {
        cout << "Impossivel calcular" << "\n";
        return 0;
    }

    else {
        delta = (b*b)-4*((a)*c);
            if(delta == 0) {
                x1 = (-b + sqrt(delta)) / 2*a;
                x2 = x1;
            }
            else if(delta < 0) {
                cout << "Impossivel calcular" << "\n";
                return 0;
            }
            else{

                x1 = (-1 * (b) + sqrt(delta)) / (2*a);
                x2 = (-1*(b) - sqrt(delta)) / (2*a);
            }
    }

    printf("R1 = %.5f\n", x1);
    printf("R2 = %.5f\n", x2);    

    return 0;
}