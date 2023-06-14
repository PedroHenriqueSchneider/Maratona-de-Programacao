#include <iostream>

using namespace std;

int main(){
	// Seu código vai aqui
    int N, num;
    bool l = false;
    bool l2 = false;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
   	 cin >> num;
   	 if(num == 1) {
   		 if(l == false)
   			 l = true;
   		 else
   			 l = false;
   	 }
   	 if(num == 2)
   	 {
   		 if(l == false)
   			 l = true;
   		 else
   			 l = false;
   		 if(l2 == false)
   			 l2 = true;
   		 else
   			 l2 = false;
   	 }
    }
    if(l == true) {
   	 cout << 1 << "\n";    
    }
    else
   	 cout << 0 << "\n";
    if(l2 == true)
   	 cout << 1 << "\n";
    else
   	 cout << 0 << "\n";
    
	return 0;
}
