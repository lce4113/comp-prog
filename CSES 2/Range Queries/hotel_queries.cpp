// CSES Range Queries: Hotel Queries

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Tree {
    int n;
    vector<int> a;
    static constexpr int unit = 0;
    int f(int x, int y) { return max(x, y); }
    Tree(int _n) : n(_n), a(2 * _n, unit) {
        n = 1 << (1 + __lg(_n));
        a.assign(2 * n, unit);
    }
    int get(int pos) { return a[pos + n]; }
    void u(int pos, int val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int walk(int k, int i = 1) {
        if (i >= n) return i - n;
        if (k > a[i * 2]) return walk(k, i * 2 + 1);
        return walk(k, i * 2);
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
        int r;
        cin >> r;
        if (seg.a[1] < r) {
            cout << "0 ";
            continue;
        }
        int i = seg.walk(r);
        cout << i + 1 << ' ';
        seg.u(i, seg.get(i) - r);
    }
    cout << '\n';
}
