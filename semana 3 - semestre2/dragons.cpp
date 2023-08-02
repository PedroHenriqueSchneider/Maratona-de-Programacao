#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;


int main() {

    int s = 0, n = 0, st = 0, bonus = 0;
    vector<pair<int, int>> ds;

    cin >> s >> n;

    for(int i = 0; i < n; i++) {
        cin >> st >> bonus;
        ds.push_back(make_pair(st, bonus));
    }
    sort(ds.begin(), ds.end());

    for(int i = 0; i < n; i++) {
        if(s > ds[i].first) {
            s += ds[i].second;
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;

}