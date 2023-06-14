#include <iostream>

using namespace std;

int main(){
	// Seu código vai aqui
    int num  = 0, aux = 0;
    cin >> num;
    aux = num;
    
    while(num != 0) {
   	 cin >> num;
   	 if(num > aux) {
   		 aux = num;
   	 }
    }

    cout << aux << "\n";
	return 0;
}
