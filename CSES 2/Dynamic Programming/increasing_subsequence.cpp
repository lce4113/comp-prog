// CSES Dynamic Programming: Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Tree {
    static constexpr int unit = 0;
    int n;
    vector<int> a;
    int f(int x, int y) { return max(x, y); }
    Tree(int _n) : n(_n), a(2 * _n, unit) {}
    void u(int pos, int val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int ra = unit, rb = unit;
        for (l += n, r += n; r > l; l /= 2, r /= 2) {
            if (l % 2) ra = f(ra, a[l++]);
            if (r % 2) rb = f(a[--r], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) p.push_back({a[i], -i});
    sort(p.rbegin(), p.rend());
    Tree dp(n);
    for (auto [x, i] : p) {
        dp.u(-i, dp.q(-i + 1, n) + 1);
    }
    cout << dp.q(0, n) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}