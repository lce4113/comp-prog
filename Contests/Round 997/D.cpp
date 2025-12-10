// Codeforces Round 997: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

// const int MAXN = 2e5;
// vector<int> fact(MAXN + 1, 1);

// int choose(int n, int r) { return fact[n] / fact[r] / fact[n - r]; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int ans = 0;
    for (int i = 1; i <= 10; i++) {
        // map<int, int> mpg, mpl;
        // map<int, int> pfs;
        // int cg = 0, cl = 0;
        // mpg[cg]++, mpl[cl]++;
        // for (int j = 0; j < n; j++) {
        //     cl += (a[j] < i);
        //     cl -= (a[j] >= i);
        //     cg += (a[j] > i);
        //     cg -= (a[j] <= i);
        //     mpg[cg]++, mpl[cl]++;
        // }

        vector<int> pfs(1, 0);
        for (auto x : a) pfs.push_back(pfs.back() + (x >= i) - (x < i));

        // for (auto x : pfs) cout << x << ' ';
        // cout << '\n';

        map<int, int> mp;
        vector<int> prev;
        for (int j = n - 1; j >= 0; j--) {
            prev.push_back(pfs[j + 1]);
            if (a[j] == i) {
                for (auto x : prev) mp[x]++;
                prev.clear();
            }
            ans += mp[pfs[j]];
        }
        // cout << ans << '\n';
    }

    ans = n * (n + 1) / 2 - ans;
    cout << ans << '\n';

    // vector<int> cnt(10, 0), pfs(1, 0);
    // for (auto x : a) cnt[x - 1]++;
    // for (auto x : cnt) pfs.push_back(pfs.back() + x);

    // for (int i = 0; i < 10; i++) {
    //     for (int j = 2; j <= cnt[i]; j++) {
    //         if (j % 2 == 0) {
    //             int l = pfs[i] + 1;
    //             int r = pfs[10] - pfs[i + 1] + 1;
    //             ans += choose(cnt[i], j) * min(l, r);
    //             cout << l << ' ' << r << '\n';
    //         } else {
    //             int l = pfs[i] + 1;
    //             int r = pfs[10] - pfs[i + 1] + 1;
    //             cout << l << ' ' << r << '\n';
    //             ans += choose(cnt[i], j) * max(0ll, min(l - 1, r));
    //             ans += choose(cnt[i], j) * max(0ll, min(l, r - 1));
    //         }
    //     }
    // }

    // cout << ans << '\n';
}

int32_t main() {
    // for (int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i;

    int t = 1;
    cin >> t;
    while (t--) solve();
}