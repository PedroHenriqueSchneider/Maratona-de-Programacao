#include <iostream>
 
using namespace std;
 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     
     int n1, n2, n3, aux;
     cin >> n1 >> n2 >> n3;
     
     int n[3];
     
     n[0] = n1;
     n[1] = n2;
     n[2] = n3;
     
     for(int i = 0; i < 3; i++) {
         for(int j = i + 1; j < 3; j++) {
                if(n[i] > n[j]) {
                    aux = n[i];
                    n[i] = n[j];
                    n[j] = aux;
                }
         }
     }
     
     cout << n[0] << "\n" << n[1] << "\n" << n[2] << "\n" << "\n";
     
     cout << n1 << "\n" << n2 << "\n" << n3 << "\n";
     
    return 0;
}