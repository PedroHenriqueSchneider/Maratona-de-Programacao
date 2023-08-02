#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {

    vector <int> A;
    
    int n = 0, num = 0, sumB = 0, sumC = 0, i = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> num;
        A.push_back(num);
    }

    sort(A.begin(), A.end());

    while(A[i] < 0) {
        sumC += A[i];
        i++;
    }

    for(int j = i; j < n; j++) {
        sumB += A[j];
    }

    cout << sumB - sumC << "\n";
    return 0;
}