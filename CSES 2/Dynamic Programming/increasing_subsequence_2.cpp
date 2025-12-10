// CSES Dynamic Programming: Increasing Subsequence II

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;

struct Tree {
    int n;
    vector<int> a;
    int f(int x, int y) { return (x + y) % MOD; }
    Tree(int _n) : n(_n), a(2 * _n) {}
    void u(int pos, int val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int ra = 0, rb = 0;
        for (l += n, r += n; r > l; l /= 2, r /= 2) {
            if (l % 2) ra = f(ra, a[l++]);
            if (r % 2) rb = f(a[--r], rb);
        }
        return f(ra, rb);
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        p.push_back({a[i], -i});
    }
    sort(p.rbegin(), p.rend());
    Tree seg(n);
    for (auto [x, i] : p) {
        seg.u(-i, 1 + seg.q(-i, n));
    }
    cout << seg.q(0, n) << '\n';
}
