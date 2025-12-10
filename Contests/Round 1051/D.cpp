// Codeforces Round 1051: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
const int MOD = 1e9 + 7;

struct Tree {
    int n;
    vector<int> a;
    Tree(int _n) : n(_n), a(2 * _n) {}
    void u(int pos, int val) {
        pos += n;
        for (a[pos] = (a[pos] + val) % MOD; pos /= 2;) {
            a[pos] = (a[pos * 2] + a[pos * 2 + 1]) % MOD;
        }
    }
    int get(int pos) { return a[pos + n]; }
    int q(int l, int r) {
        int ans = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans += a[l++], ans %= MOD;
            if (r % 2) ans += a[--r], ans %= MOD;
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        a.push_back(x);
    }
    n++;
    vector<Tree> dpx(n, Tree(n)), dpy(n, Tree(n));
    dpx[0].u(0, 1), dpy[0].u(0, 1);
    for (int i = 1; i < n; i++) {
        vector<int> dp1(n), dp2(n);
        for (int j = 0; j <= a[i]; j++) {
            dp1[j] = dpy[j].q(0, a[i] + 1);
        }
        for (int j = a[i] + 1; j < n; j++) {
            dp2[j] = dpx[j].q(0, a[i] + 1);
        }
        for (int j = 0; j <= a[i]; j++) {
            // cout << dp1[j] << ' ';
            dpx[a[i]].u(j, dp1[j]);
            dpy[j].u(a[i], dp1[j]);
        }
        // cout << '\n';
        for (int j = a[i] + 1; j < n; j++) {
            // cout << dp2[j] << ' ';
            dpy[a[i]].u(j, dp2[j]);
            dpx[j].u(a[i], dp2[j]);
        }
        // cout << '\n';
        // for (auto x : dpx) {
        //     for (int i = 0; i < n; i++) cout << x.q(i, i + 1) << ' ';
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    int ans = 0;
    for (auto &d : dpx) ans += d.q(0, n), ans %= MOD;
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}