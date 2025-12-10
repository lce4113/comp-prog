// Codeforces Round 999: Problem E

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    vector<pair<int, int>> masks;
    for (int i = 1; i < (1 << m); i++) {
        int msk = (1 << 30) - 1, tot = __builtin_popcount(i);
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) msk &= b[j];
        }
        masks.push_back({msk, tot});
    }

    vector<int> sub;
    for (auto x : a) {
        vector<int> mvals(m + 1, x);
        for (auto c : masks) {
            mvals[c.s] = min(mvals[c.s], x & c.f);
        }
        for (int i = 0; i < m; i++) sub.push_back(mvals[i] - mvals[i + 1]);
    }

    sort(sub.rbegin(), sub.rend());

    long long ans = 0;
    for (auto x : a) ans += x;
    for (int i = 0; i < k && i < (int)sub.size(); i++) ans -= sub[i];

    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}