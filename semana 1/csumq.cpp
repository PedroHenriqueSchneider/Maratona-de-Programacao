#include <iostream>
using namespace std;

int main() {
	int numbers_integers, numbers_queries, number, i , j, somador = 0;

    cin >> numbers_integers;

    int numbers[numbers_integers];

    for(int k = 0; k < numbers_integers; k++) {
        cin >> number;
        numbers[k] = number;
    }

    cin >> numbers_queries;

    for(int k = 0; k < numbers_queries; k++) {
        cin >> i >> j;
        for(int u = i; u <= j; u++) {
            somador += numbers[u];
        }
        cout << somador << endl;
        somador = 0;
    }

    

	return 0;
}