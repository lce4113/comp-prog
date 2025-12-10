// Meta Hacker Cup 2025 Round 1: Problem A2

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int l = 0, r = 1e9;
    while (r - l > 1) {
        int m = (l + r) / 2;
        vector<bool> vis(n);
        queue<int> Q;
        for (int i = 0; i < n; i++)
            if (a[i] <= m) Q.push(i), vis[i] = 1;
        while (Q.size()) {
            int v = Q.front();
            Q.pop();
            if (v - 1 >= 0 && !vis[v - 1] && abs(a[v] - a[v - 1]) <= m) {
                Q.push(v - 1), vis[v - 1] = 1;
            }
            if (v + 1 < n && !vis[v + 1] && abs(a[v] - a[v + 1]) <= m) {
                Q.push(v + 1), vis[v + 1] = 1;
            }
        }
        bool ok = 1;
        for (auto x : vis) ok &= x;
        if (ok) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}