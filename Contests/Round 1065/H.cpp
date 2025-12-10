// Codeforces Round 1065: Problem H

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int INF = 1e18;

struct Tree {
    int n;
    vector<int> a;
    Tree(int _n) : n(_n), a(2 * n, 0) {}
    void u(int pos, int val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = max(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int res = -INF;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = max(res, a[l++]);
            if (r & 1) res = max(res, a[--r]);
        }
        return res;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    // cout << n << ' ' << m << ' ';
    Tree dp(m + 1);
    for (int i = 2; i <= n; i++) {
        for (int j = (m - i - (n - i)) / i * i; j >= 0; j -= i) {
            int c = i + j, v = 0;
            while (c % i == 0) c /= i, v++;
            dp.u(j, dp.q(0, j + 1) + v);
        }
        // for (auto x : dp.a) cout << x << ' ';
        // cout << '\n';
    }
    cout << dp.q(0, m + 1) << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}