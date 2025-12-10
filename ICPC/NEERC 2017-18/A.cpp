// NEERC 2017-18: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
const int INF = 1e18;

int N = 0;
map<int, int> mp, mpr;

struct Tree {
    int n;
    vector<set<pair<int, array<int, 3>>>> a;
    Tree(int _n) : n(_n), a(2 * _n) {}
    void u(int l, int r, array<int, 3> i) {
        // cout << l << ' ' << r << ' ';
        // for (auto x : i) cout << x << ' ';
        // cout << '\n';
        for (a[l += n].insert({r, i}); l; l /= 2) {
            a[l].insert({r, i});
        }
        // cout << "NEW\n";
        // for (auto x : a) {
        //     for (auto y : x) {
        //         cout << y.f << ": ";
        //         for (auto z : y.s) cout << z << ' ';
        //         cout << '\n';
        //     }
        //     cout << '\n';
        // }
    }
    void rem(int l, int r, array<int, 3> i) {
        for (a[l += n].erase({r, i}); l; l /= 2) {
            a[l].erase({r, i});
        }
    }
    vector<array<int, 3>> get(set<pair<int, array<int, 3>>> &v, int val) {
        vector<array<int, 3>> res;
        array<int, 3> big = {INF, INF, INF};
        auto it = v.lower_bound({val, big});
        while (it != v.end()) {
            res.push_back(it->s);
            it++;
        }
        return res;
    }
    vector<array<int, 3>> q(int l, int r, int val) {
        vector<array<int, 3>> res;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) {
                auto c = get(a[l++], val);
                res.insert(res.end(), c.begin(), c.end());
            }
            if (r % 2) {
                auto c = get(a[--r], val);
                res.insert(res.end(), c.begin(), c.end());
            }
        }
        return res;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<array<int, 3>> es(n);
    for (auto &x : es) {
        for (auto &y : x) cin >> y;
        if (x[0] == 1) {
            mp[x[1] - x[2]];
            mp[x[1] + x[2]];
        } else {
            mp[x[1]];
        }
    }
    for (auto &x : mp) {
        x.s = N++;
        // cout << x.f << ' ' << x.s << '\n';
    }
    Tree seg(N);
    for (int j = 0; j < es.size(); j++) {
        auto [tp, x, y] = es[j];
        if (tp == 1) {
            seg.u(mp[x - y], mp[x + y], {x, y, j + 1});
        } else {
            // tx, ty, i
            vector<array<int, 3>> v = seg.q(0, mp[x], mp[x]);
            bool ok = 0;
            for (auto [tx, ty, i] : v) {
                // cout << tx << ' ' << ty << ' ' << i << '\n';
                if ((x - tx) * (x - tx) + (y - ty) * (y - ty) < ty * ty) {
                    seg.rem(mp[tx - ty], mp[tx + ty], {tx, ty, i});
                    cout << i << '\n';
                    ok = 1;
                    break;
                }
            }
            if (!ok) cout << "-1\n";
        }
    }
}