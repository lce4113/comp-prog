// CSES Range Queries: Static Range Minimum Queries

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Tree {
    int n;
    vector<int> a;
    static constexpr int unit = 1e18;
    int f(int x, int y) { return min(x, y); }
    Tree(int _n) : n(_n), a(2 * _n, unit) {}
    void u(int pos, int val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int ra = unit, rb = unit;
        for (l += n, r += n; l < r; r /= 2, l /= 2) {
            if (l % 2) ra = f(ra, a[l++]);
            if (r % 2) rb = f(a[--r], rb);
        }
        return f(ra, rb);
    }
};

int32_t main() {
    int n, q;
    cin >> n >> q;
    Tree seg(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        seg.u(i, x);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << seg.q(l - 1, r) << '\n';
    }
}