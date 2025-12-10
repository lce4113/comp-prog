// CSES Range Queries: Distinct Values Queries II

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Tree {
    static constexpr int unit = 1e18;
    int n;
    vector<int> a;
    int f(int x, int y) { return min(x, y); }
    Tree(int _n) : n(_n), a(2 * _n, unit) {}
    void u(int pos, int val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int ans = unit;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans = f(ans, a[l++]);
            if (r % 2) ans = f(ans, a[--r]);
        }
        return ans;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, set<int>> mp;
    for (int i = 0; i < n; i++) mp[a[i]].insert(i);
    Tree seg(n);
    for (auto &[_, v] : mp) {
        v.insert(n);
        for (auto j = v.begin(), i = j++; j != v.end(); i++, j++) {
            seg.u(*i, *j);
        }
    }

    while (q--) {
        char t;
        cin >> t;
        if (t == '1') {
            int k, v;
            cin >> k >> v;
            k--;
            if (a[k] == v) continue;
            mp[v].insert(n);

            // for (auto x : mp) {
            //     cout << x.f << ": ";
            //     for (auto y : x.s) cout << y << ' ';
            //     cout << '\n';
            // }

            auto it = mp[a[k]].lower_bound(k), it2 = it;
            if (it != mp[a[k]].begin()) {
                int prev = *(--it), next = *(++it2);
                seg.u(prev, next);
            }
            mp[a[k]].erase(k);

            mp[v].insert(k);
            it = mp[v].upper_bound(k);
            int next = *it, curr = *(--it);
            seg.u(curr, next);
            if (it != mp[v].begin()) {
                int prev = *(--it);
                seg.u(prev, curr);
            }

            a[k] = v;
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << (seg.q(l, r) < r ? "NO\n" : "YES\n");
        }
    }
}