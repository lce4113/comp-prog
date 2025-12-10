// CSES Tree Algorithms: Subordinates

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

vector<vector<int>> adj;
vector<int> ans;

int dfs(int v, int p) {
    for (auto c : adj[v]) {
        if (c == p) continue;
        ans[v] += dfs(c, v);
    }
    return ans[v];
}

int32_t main() {
    int n;
    cin >> n;
    adj.assign(n, {});
    ans.assign(n, 1);
    vector<int> a(n - 1);
    for (auto &x : a) {
        cin >> x;
        x--;
    }
    for (int i = 0; i < n - 1; i++) {
        adj[a[i]].push_back(i + 1);
    }
    dfs(0, 0);
    for (auto x : ans) cout << x - 1 << ' ';
    cout << '\n';
}