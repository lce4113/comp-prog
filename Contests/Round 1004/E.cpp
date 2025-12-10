// Codeforces Round 1004: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]].push_back(i);
    }

    if (mp[0].size() == 0) {
        cout << n << '\n';
        return;
    }

    int ans = n - mp[0].size();
    int L = mp[0][0], lst = -1;
    for (auto x : mp) {
        if (x.f != lst + 1) break;
        int rs = x.s.end() - lower_bound(x.s.begin(), x.s.end(), L);
        int ls = x.s.size() - rs;
        if (ls > 1 || (rs > 0 && ls > 0)) {
            cout << ans << '\n';
            return;
        }
        L = min(L, x.s[0]);
        lst = x.f;
    }
    cout << ans + 1 << '\n';

    // int N = mp.size();

    // vector<int> f(N, 0), b(N, 0);
    // int L = n, lst = -1, j = 0;
    // for (auto x : mp) {
    //     if (x.f != lst + 1) L = 0;
    //     int len = x.s.size();
    //     auto it = upper_bound(x.s.begin(), x.s.end(), L);
    //     int rs = x.s.end() - it;
    //     if (rs <= 1) {
    //         L = min(L, *(--it));
    //         f[j] = 1;
    //     } else {
    //         f[j] = rs;
    //     }
    //     b[j] = len;
    //     lst = x.f;
    //     j++;
    // }

    // // for (auto x : f) cout << x << ' ';
    // // cout << '\n';
    // // for (auto x : b) cout << x << ' ';
    // // cout << '\n';

    // vector<int> fpfs(1, 0), bpfs(N + 1, 0);
    // for (auto x : f) fpfs.push_back(fpfs.back() + x);
    // for (int i = N - 1; i >= 0; i--) bpfs[i] = bpfs[i + 1] + b[i];

    // // for (auto x : fpfs) cout << x << ' ';
    // // cout << '\n';
    // // for (auto x : bpfs) cout << x << ' ';
    // // cout << '\n';

    // int ans = fpfs[N];
    // for (int i = 0; i < N; i++) {
    //     ans = max(ans, fpfs[i] + bpfs[i + 1]);
    // }
    // cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}
