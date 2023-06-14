#include <iostream>

using namespace std;

int fib(int num);

int main(){
	
    int n = 0;
    cin >> n;

    cout << fib(n) << "\n";
    
	return 0;
}

int fib(int num) {
    if(num == 1 || num == 0) {
        return 1;
    }
    return fib(num-1) + fib(num-2);
}



