// CSES Advanced Graph Problems: Bus Companies

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for (auto &x : c) cin >> x;

    vector<vector<int>> nums(n), bs(m);
    map<pair<int, int>, vector<array<int, 3>>> adj;
    for (int i = 0; i < m; i++) {
        int N;
        cin >> N;
        vector<int> B(N);
        for (auto &b : B) cin >> b;
        for (int j = 1; j < N; j++) {
            adj[{B[0], i}].push_back({B[j], i, 0});
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        Q;
    vector<int> dst(n, -1);
    dst[0] = 0;
    Q.push({0, 0});
    while (Q.size()) {
        auto [d, v] = Q.top();
        Q.pop();
        if (d != dst[v]) continue;
        for (auto [to, w] : cs[v]) {
        }
    }
}