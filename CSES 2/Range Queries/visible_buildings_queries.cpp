// CSES Range Queries: Visible Buildings Queries

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Tree {
    int n;
    vector<vector<int>> a;
    vector<int> f(vector<int> &x, vector<int> &y) {
        int lx = x.size(), ly = y.size();
        vector<int> res;
        int i = 0, j = 0;
        while (i < lx && j < ly) res.push_back(x[i] < y[j] ? x[i++] : y[j++]);
        while (i < lx) res.push_back(x[i++]);
        while (j < ly) res.push_back(y[j++]);
        return res;
    }
    Tree(vector<int> &in) {
        n = in.size(), a.assign(2 * n, {});
        for (int i = 0; i < n; i++) a[i + n] = {in[i]};
        for (int i = n - 1; i >= 1; i--) a[i] = f(a[2 * i], a[2 * i + 1]);
    }
    int find(vector<int> &v, int k) {
        return upper_bound(v.begin(), v.end(), k) - v.begin();
    }
    int q(int l, int r, int k) {
        int ans = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans += find(a[l++], k);
            if (r % 2) ans += find(a[--r], k);
        }
        return ans;
    }
};

int32_t main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> low(n);
    stack<pair<int, int>> Q;
    Q.emplace(1e18, -1);
    for (int i = 0; i < n; i++) {
        while (a[i] > Q.top().f) Q.pop();
        low[i] = Q.top().s;
        Q.emplace(a[i], i);
    }
    Tree seg(low);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << seg.q(l, r, l - 1) << '\n';
    }
}