// CSES Range Queries: Subarray Sum Queries

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
        int k, v;
        cin >> k >> v;
        k--;
        seg.u(k, v);
        cout << seg.ans() << '\n';
    }
}