// CSES Geometry: Lines and Queries II

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int B = 20;
int n = 1 << B;
vector<pair<int, int>> v(2 * n);

struct Line {
    int a, b; // a*x+b
    int get(int x) { return a * x + b; }
};
struct LCT {
    vector<Line> lct;
    LCT() : lct(2 * n, {0, -INF}) {}
    void add(Line l, int L, int R) {
        for (L += n, R += n; L < R; L /= 2, R /= 2) {
            if (L % 2) add(l, L++);
            if (R % 2) add(l, --R);
        }
    }
    void add(Line l, int i) {
        if (i >= 2 * n) return;
        auto [lo, hi] = v[i];
        int mid = (lo + hi) / 2;
        if (lct[i].get(mid) < l.get(mid)) swap(l, lct[i]);
        if (lct[i].a < l.a) {
            add(l, 2 * i + 1);
        } else {
            add(l, 2 * i);
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

    for (int i = 0; i < n; i++) {
        v[i + n] = {i, i + 1};
    }
    for (int i = n - 1; i >= 1; i--) {
        v[i] = {v[2 * i].first, v[2 * i + 1].second};
    }

    int q;
    cin >> q;
    LCT L;
    while (q--) {
        int tp, a, b, l, r, x;
        cin >> tp;
        if (tp == 1) {
            cin >> a >> b >> l >> r;
            L.add({a, b}, l, r + 1);
        } else {
            cin >> x;
            int ans = L.q(x);
            if (ans == -INF) {
                cout << "NO\n";
            } else {
                cout << ans << '\n';
            }
        }
    }
}