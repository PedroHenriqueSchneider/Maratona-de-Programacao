#include <iostream>
#include <map>

using namespace std;

int main() {

    int n = 0, num = 0;
    map <int, int> votos;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> num;

        if(votos.find(num) == votos.end()) {
            votos.insert(make_pair(num, 1));
        } else{
            votos.at(num) += 1;
        }
    }

    int element = 0, maior = 0;     

    for (const auto& x : votos) {
        if(x.second > maior) {
            maior = x.second;
            element = x.first;
        }
    }
    

    cout << element << "\n";

    return 0;
}