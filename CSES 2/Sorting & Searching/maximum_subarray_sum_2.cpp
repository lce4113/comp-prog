// CSES Sorting & Searching: Movie Festival II

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Tree {
    int unit = 1e18;
    vector<int> a;
    int n;
    int f(int x, int y) { return min(x, y); }
    Tree(int _n) : a(2 * _n, unit), n(_n) {}
    void u(int pos, int val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int ra = unit, rb = unit;
        for (l += n, r += n; r > l; r /= 2, l /= 2) {
            if (l % 2) ra = f(ra, a[l++]);
            if (r % 2) rb = f(a[--r], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    Tree seg(n + 1);
    int c = 0, ans = -1e18;
    seg.u(0, 0);
    for (int i = 0; i < n; i++) {
        c += a[i];
        seg.u(i + 1, c);
        if (i - l + 2 > 0) {
            auto x = c - seg.q(max(0ll, i - r + 1), i - l + 2);
            ans = max(x, ans);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}