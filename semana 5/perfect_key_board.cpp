#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        vector<vector<int>> adj(26);
        vector<int> degree(26, 0);
        set<char> used;

        for (int i = 0; i < s.size() - 1; ++i) {
            int u = s[i] - 'a';
            int v = s[i + 1] - 'a';
            if (u != v) {
                adj[u].push_back(v);
                adj[v].push_back(u);
                degree[u]++;
                degree[v]++;
                used.insert(s[i]);
                used.insert(s[i + 1]);
            }
        }

        string result;
        queue<int> q;
        for (int i = 0; i < 26; ++i) {
            if (degree[i] > 2) {
                cout << "NO\n";
                goto next_case;
            }
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result += (char)(u + 'a');
            for (int v : adj[u]) {
                degree[v]--;
                if (degree[v] == 1) {
                    q.push(v);
                }
            }
        }

        if (result.size() != used.size()) {
            cout << "NO\n";
            goto next_case;
        }

        vector<bool> visited(26, false);
        string layout;
        for (char c : result) {
            layout += c;
            visited[c - 'a'] = true;
        }

        for (int i = 0; i < 26; ++i) {
            if (!visited[i]) {
                layout += (char)(i + 'a');
            }
        }

        cout << "YES\n" << layout << '\n';
        next_case:;
    }

    return 0;
}
