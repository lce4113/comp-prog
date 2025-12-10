// CSES Range Queries: Distinct Values Queries

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Tree {
    int n;
    vector<vector<int>> a;
    void f(vector<int> &x, vector<int> &y, vector<int> &z) {
        z.assign(x.size() + y.size(), 0);
        merge(x.begin(), x.end(), y.begin(), y.end(), z.begin());
    }
    Tree(vector<int> &in) {
        n = in.size(), a.assign(2 * n, {});
        for (int i = 0; i < n; i++) a[i + n] = {in[i]};
        for (int i = n - 1; i >= 1; i--) f(a[2 * i], a[2 * i + 1], a[i]);
    }
    int count(vector<int> &v, int R) {
        return v.end() - upper_bound(v.begin(), v.end(), R);
    }
    int q(int l, int r, int R) {
        int ans = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans += count(a[l++], R);
            if (r % 2) ans += count(a[--r], R);
        }
        return ans;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }
    vector<int> a(n);
    for (auto &x : mp) {
        x.s.push_back(n);
        int m = x.s.size();
        for (int i = 0; i < m - 1; i++) a[x.s[i]] = x.s[i + 1];
    }
    Tree seg(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << seg.q(l, r, r - 1) << '\n';
    }
}