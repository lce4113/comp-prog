// CSES Range Queries: Salary Queries

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Tree {
    int n;
    vector<int> a;
    int f(int x, int y) { return x + y; }
    Tree(int _n) : n(_n), a(2 * _n) {}
    void u(int pos, int val) {
        for (a[pos += n] += val; pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int ra = 0, rb = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ra = f(ra, a[l++]);
            if (r % 2) rb = f(a[--r], rb);
        }
        return f(ra, rb);
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int, int> mp;
    for (auto &x : a) {
        cin >> x;
        mp[x] = 1;
    }
    vector<pair<char, pair<int, int>>> qs(q);
    for (auto &[t, x] : qs) {
        cin >> t >> x.f >> x.s;
        if (t == '!') mp[x.s] = 1;
    }
    int N = 0;
    for (auto &[x, v] : mp) v = N++;

    Tree seg(N);
    for (auto x : a) seg.u(mp[x], 1);

    for (auto [t, rng] : qs) {
        if (t == '!') {
            rng.f--;
            seg.u(mp[a[rng.f]], -1);
            seg.u(mp[rng.s], 1);
            a[rng.f] = rng.s;
        } else {
            int l = mp.lower_bound(rng.f)->s;
            int r = (--mp.upper_bound(rng.s))->s;
            cout << seg.q(l, r + 1) << '\n';
        }
    }
}