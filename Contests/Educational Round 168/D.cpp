// Codeforces Educational Round 168: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

map<int, vector<int>> adj;
map<int, int> val;

int rec(int n) {
    if (adj[n].size() == 0) return val[n];
    int mn = 1e18;
    for (auto x : adj[n]) mn = min(mn, rec(x));
    return min(mn, (val[n] + mn) / 2);
}

void solve() {
    int n;
    cin >> n;
    adj.clear();
    val.clear();
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        val[i] = x;
    }
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
        // cout << x << ' ' << i << '\n';
    }
    // for (auto x : adj) {
    //     cout << x.f << ':';
    //     for (auto y : x.s) cout << y << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';
    int mn = 1e18;
    for (auto x : adj[1]) mn = min(mn, rec(x));
    cout << val[1] + mn << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}