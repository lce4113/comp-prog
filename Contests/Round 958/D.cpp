// Codeforces Round 958: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define double long double
#define f first
#define s second

int n, N;
map<int, int> a;
map<int, vector<int>> adj;
map<int, vector<int>> dp;

vector<int> rec(int v, int p) {
    if (dp.count(v)) return dp[v];

    vector<int> ans(N + 1);
    for (int i = 1; i <= N; i++) ans[i] = i * a[v];
    for (auto c : adj[v]) {
        if (c == p) continue;
        vector<int> ca = rec(c, v);
        vector<pair<int, int>> cai;
        for (int i = 1; i <= N; i++) cai.push_back({ca[i], i});
        sort(cai.begin(), cai.end());
        for (int j = 1; j <= N; j++) {
            ans[j] += cai[0].s == j ? cai[1].f : cai[0].f;
        }
    }

    dp[v] = ans;
    return ans;
}

void solve() {
    a.clear();
    adj.clear();
    dp.clear();
    cin >> n;
    N = log2(n) + 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> ans = rec(0, -1);

    // for (auto x : dp) {
    //     cout << x.f + 1 << ": ";
    //     for (auto y : x.s) cout << y << ' ';
    //     cout << '\n';
    // }

    int mn = 1e18;
    for (int i = 1; i <= N; i++) mn = min(mn, ans[i]);
    cout << mn << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}