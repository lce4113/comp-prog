// Codeforces Round 974: Problem D

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    vector<pair<int, int>> p;
    while (k--) {
        int l, r;
        cin >> l >> r;
        p.push_back({max(l - d + 1, 1), 1});
        if (r + 1 <= n) p.push_back({r + 1, -1});
    }
    sort(p.begin(), p.end());
    // for (auto x : p) cout << x.f << ' ' << x.s << '\n';
    vector<int> jbs(n);
    int curr = 0, mx = -1, mn = 1e9, m, b;
    for (int i = 1, j = 0; i <= n + 1 - d; i++) {
        while (j < (int)p.size() && p[j].f == i) curr += p[j].s, j++;
        jbs[i - 1] = curr;
        if (curr > mx) mx = curr, b = i;
        if (curr < mn) mn = curr, m = i;
    }
    // for (auto x : jbs) cout << x << ' ';
    // cout << '\n';
    cout << b << ' ' << m << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}