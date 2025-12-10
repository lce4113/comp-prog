// CSES Geometry: Lines and Queries I

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int N = 1e5;

struct Line {
    int a, b; // a*x+b
    int get(int x) { return a * x + b; }
};

struct LCT {
    int n;
    vector<Line> lct;
    LCT(int _n) { n = 1 << (1 + __lg(_n)), lct.assign(2 * n, {0, -INF}); }
    void add(Line l) { add(l, 1, 0, n); }
    void add(Line l, int i, int lo, int hi) {
        if (i >= 2 * n) return;
        if (hi == -1) hi = n;
        int mid = (lo + hi) / 2;
        if (lct[i].get(mid) < l.get(mid)) swap(lct[i], l);
        if (lct[i].a < l.a) {
            add(l, 2 * i + 1, mid, hi);
        } else {
            add(l, 2 * i, lo, mid);
        }
    }
    int q(int x) {
        int ans = -INF;
        for (int i = x + n; i; i /= 2) {
            ans = max(ans, lct[i].get(x));
        }
        return ans;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int q;
    cin >> q;
    LCT L(N + 1);
    while (q--) {
        int tp, a, b, x;
        cin >> tp;
        if (tp == 1) {
            cin >> a >> b;
            L.add({a, b});
        } else {
            cin >> x;
            cout << L.q(x) << '\n';
        }
    }
}