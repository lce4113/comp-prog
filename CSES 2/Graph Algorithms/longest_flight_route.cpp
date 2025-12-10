// CSES Graph Algorithms: Longest Flight Route

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> ins(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        ins[v]++;
    }

    queue<int> Q;
    for (int i = 0; i < n; i++)
        if (ins[i] == 0) Q.push(i);
    vector<int> dp(n, -1), p(n, -1);
    dp[0] = 1;
    bool ok = 0;
    while (Q.size()) {
        auto c = Q.front();
        Q.pop();
        if (c == 0) ok = 1;
        for (auto x : adj[c]) {
            if (ok && dp[c] != -1 && dp[c] + 1 > dp[x]) {
                dp[x] = dp[c] + 1;
                p[x] = c;
            }
            ins[x]--;
            if (ins[x] == 0) Q.push(x);
        }
    }

    if (p[n - 1] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> ans;
    int c = n - 1;
    ans.push_back(c);
    while (c != 0) {
        c = p[c];
        ans.push_back(c);
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x + 1 << ' ';
    cout << '\n';
}
