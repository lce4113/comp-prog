// Codeforces Round 1067: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int INF = 1e18;
// max sum, left suff, right suff, sum
using at = array<int, 4>;
array<int, 4> unit = {0, 0, 0, 0};

struct Tree {
    int n;
    vector<at> a;
    at cmb(at x, at y) {
        int mxsm = max(max(x[0], y[0]), x[2] + y[1]);
        int left = max(x[1], x[3] + y[1]);
        int right = max(y[2], y[3] + x[2]);
        int sum = x[3] + y[3];
        return {mxsm, left, right, sum};
    }
    Tree(int _n) : n(_n), a(2 * n) {}
    void u(int pos, int val) {
        int mx = max(0ll, val);
        for (a[pos += n] = {mx, mx, mx, val}; pos /= 2;) {
            a[pos] = cmb(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        at ra = unit, rb = unit;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ra = cmb(ra, a[l++]);
            if (r % 2) rb = cmb(a[--r], rb);
        }
        return cmb(ra, rb)[0];
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int mx = -INF;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
    }
    Tree seg(n);
    for (int i = 0; i < n; i++) {
        seg.u(i, a[i]);
    }
    if (k % 2 == 0) {
        cout << (mx < 0 ? mx : seg.q(0, n)) << '\n';
        return;
    }
    mx = -INF;
    for (int i = 0; i < n; i++) {
        mx = max(mx, max(a[i] + b[i], a[i] - b[i]));
    }
    if (mx < 0) {
        cout << mx << '\n';
        return;
    }
    int ans = seg.q(0, n);
    for (int i = 0; i < n; i++) {
        seg.u(i, max(a[i] + b[i], a[i] - b[i]));
        ans = max(ans, seg.q(0, n));
        seg.u(i, a[i]);
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}