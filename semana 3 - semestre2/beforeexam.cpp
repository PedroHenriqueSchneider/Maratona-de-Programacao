#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {


    int d, sumTime;

    cin >> d >> sumTime;

    vector<int> minTime(d);

    vector<int> maxTime(d);

    for (int i = 0; i < d; i++) {
        cin >> minTime[i] >> maxTime[i];
    }

    int sum = 0;

    for (int i = 0; i < d; i++) {
        sum += minTime[i];
    }

    if (sum > sumTime) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> schedule(d);

    for (int i = 0; i < d; i++) {
        schedule[i] = minTime[i];
        sumTime -= minTime[i];
    }

    for (int i = 0; i < d; i++) {
        int diff = maxTime[i] - minTime[i];
        if (diff <= sumTime) {
            schedule[i] += diff;
            sumTime -= diff;
        } else {
            schedule[i] += sumTime;
            sumTime = 0;
        }
    }

    if (sumTime > 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    for (int i = 0; i < d; i++) {
        cout << schedule[i] << " ";
    }

    cout << endl;

    return 0;
}