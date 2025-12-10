// CSES Range Queries: Subarray Sum Queries II

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct T {
    int sum, pref, suf, res;
    T(int s, int p, int su, int r) : sum(s), pref(p), suf(su), res(r) {}
    T(int n) : sum(n) { res = suf = pref = max(0ll, n); }
};

T f(T x, T y) {
    return {x.sum + y.sum, max(x.sum + y.pref, x.pref),
            max(x.suf + y.sum, y.suf), max(max(x.res, y.res), x.suf + y.pref)};
}

struct Tree {
    int n;
    vector<T> a;
    T unit = T(0);
    Tree(int _n) {
        n = 1 << (__lg(_n) + 1);
        a.assign(2 * n, unit);
    }
    void u(int pos, int val) {
        for (a[pos += n] = T(val); pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int ans() { return a[1].res; }
    int q(int l, int r) {
        T ra = unit, rb = unit;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ra = f(ra, a[l++]);
            if (r % 2) rb = f(a[--r], rb);
        }
        return f(ra, rb).res;
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
        l--;
        cout << seg.q(l, r) << '\n';
    }
}