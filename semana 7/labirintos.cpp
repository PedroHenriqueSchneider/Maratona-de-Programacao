#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int startNode;
        cin >> startNode;

        int V, A;
        cin >> V >> A;

        vector<int> degree(V, 0);
        for (int i = 0; i < A; ++i) {
            int u, v;
            cin >> u >> v;
            degree[u]++;
            degree[v]++;
        }

        int oddCount = 0;
        for (int d : degree) {
            if (d % 2 != 0) {
                oddCount++;
            }
        }

        int movements = 2 * A; // Total movements is double the number of edges
        if (oddCount > 0) {
            // If there are odd degree vertices, add oddCount - 2
            movements += (oddCount - 2);
        }

        cout << movements << endl;
    }

    return 0;
}
