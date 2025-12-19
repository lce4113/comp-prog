// CSES Range Queries: Missing Coin Sum Queries

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e5;
vector<ll> a[2 * N];

struct Tree {
    int n;
    Tree(int *v, int _n) : n(_n) {
        for (int i = n; i < 2 * n; i++) {
            a[i] = {v[i - n]};
        }
        for (int i = n - 1; i >= 1; i--) {
            a[i].resize(a[2 * i].size() + a[2 * i + 1].size());
            merge(a[2 * i].begin(), a[2 * i].end(), a[2 * i + 1].begin(),
                  a[2 * i + 1].end(), a[i].begin());
            clean(a[i]);
        }
    }
    void clean(vector<ll> &v) {
        vector<ll> c = {v[0], v[1]};
        ll tot = v[0] + v[1];
        for (int j = 2; j < v.size(); j++) {
            if (c.back() + v[j] <= tot - c.back() + 1) {
                c.back() += v[j];
            } else {
                c.push_back(v[j]);
            }
            tot += v[j];
        }
        swap(v, c);
    }
    ll q(int l, int r) {
        vector<int> is;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) is.push_back(l), l++;
            if (r & 1) r--, is.push_back(r);
        }

        vector<int> pos(is.size());
        priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                       greater<pair<ll, int>>>
            Q;
        for (int i = 0; i < is.size(); i++) Q.push({a[is[i]][0], i});
        ll tot = 0;
        while (Q.size()) {
            auto [val, i] = Q.top();
            Q.pop();

            if (val > tot + 1) return tot + 1;
            tot += val;

            pos[i]++;
            if (pos[i] < a[is[i]].size()) Q.push({a[is[i]][pos[i]], i});
        }
        return tot + 1;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    int v[n];
    for (auto &x : v) cin >> x;
    Tree seg(v, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << seg.q(l, r) << '\n';
    }
}