// CSES Range Queries: Prefix Sum Queries

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Tree {
    typedef pair<int, int> T;
    static constexpr T unit = {0, 0};
    int n;
    vector<T> a;
    T f(T x, T y) { return {max(x.s + y.f, x.f), x.s + y.s}; }
    Tree(int _n) : n(_n), a(2 * _n, unit) {}
    void u(int pos, T val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    T q(int l, int r) {
        T ra = unit, rb = unit;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
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
        seg.u(i, {max(0ll, x), x});
    }

    while (q--) {
        char t;
        cin >> t;
        if (t == '1') {
            int k, x;
            cin >> k >> x;
            seg.u(--k, {max(0ll, x), x});
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.q(--l, r).f << '\n';
        }
    }
}