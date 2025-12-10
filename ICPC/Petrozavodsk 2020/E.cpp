// Petrozavodsk 2020: Problem E

#include <bits/stdc++.h>
using namespace std;

// #define int long long
const int INF = 2e9 + 5;

struct Tree {
    int n;
    vector<int> a;
    Tree(int _n) : n(_n), a(2 * _n, -INF) {}
    void u(int pos, int val) {
        pos += n;
        for (a[pos] = max(a[pos], val); pos /= 2;) {
            a[pos] = max(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int ans = -INF;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans = max(ans, a[l++]);
            if (r % 2) ans = max(ans, a[--r]);
        }
        return ans;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    // y1, tp, y2, x1, x2, index
    vector<array<int, 6>> a;
    map<int, int> mp;
    for (int i = n; i--;) {
        int x, y, r;
        cin >> x >> y >> r;
        a.push_back({y - r, 0, y + r, x, 0, 0});
        mp[x];
    }
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2, ymn, ymx;
        cin >> x1 >> y1 >> x2 >> y2 >> ymn >> ymx;
        a.push_back({ymn, 1, ymx, x1, x2, i});
        mp[x1], mp[x2];
    }
    sort(a.begin(), a.end());
    int C = 0;
    for (auto &[_, x] : mp) x = C++;
    vector<string> ans(q);
    Tree seg(C);
    for (auto &[y1, tp, y2, x1, x2, index] : a) {
        x1 = mp[x1], x2 = mp[x2];
        if (tp == 0) {
            seg.u(x1, y2);
        } else {
            if (x1 > x2) swap(x1, x2);
            ans[index] = seg.q(x1, x2 + 1) >= y2 ? "NO" : "YES";
        }
    }
    for (auto x : ans) cout << x << '\n';
}