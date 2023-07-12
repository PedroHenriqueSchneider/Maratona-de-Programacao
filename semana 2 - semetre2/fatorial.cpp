#include <iostream>
 
using namespace std;
 
int fatorial(int num);
 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     
     int n = 0;
     cin >> n;
     cout << fatorial(n) << "\n";
 
    return 0;
}

int fatorial(int num) {
    if(num == 1) {
        return 1;
    }
    return num * fatorial(num-1);
}