#include <bits/stdc++.h>
using namespace std;

void solve() {
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    vector<int> dist(f + 1, -1);
    queue<int> Q;
    dist[s] = 0;
    Q.push(s);
    while (Q.size()) {
        int curr = Q.front();
        Q.pop();
        if (curr + u <= f && dist[curr + u] == -1) {
            dist[curr + u] = dist[curr] + 1;
            Q.push(curr + u);
        }
        if (curr - d <= f && dist[curr - d] == -1) {
            dist[curr - d] = dist[curr] + 1;
            Q.push(curr - d);
        }
    }
    if (dist[g] == -1)
        cout << "use the stairs\n";
    else
        cout << dist[g] << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}