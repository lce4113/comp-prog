// Codeforces Round 1030: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        Q;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= 60; i++) {
            if (((1ll << i) & a[j]) == 0) Q.push({i, j});
        }
    }
    while (1) {
        auto [i, j] = Q.top();
        Q.pop();
        if (k < (1ll << i)) break;
        a[j] += (1ll << i);
        k -= (1ll << i);
    }
    // for (auto x : a) cout << x << ' ';
    // cout << '\n';
    int tot = 0;
    for (auto x : a) tot += __builtin_popcountll(x);
    cout << tot << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}