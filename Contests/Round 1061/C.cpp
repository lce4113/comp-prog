// Codeforces Round 1061: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    // for (auto x : a) cout << x << ' ';
    // cout << '\n';
    vector<int> cnt(4 * n + 1, 0), pfs(1, 0);
    for (auto x : a) cnt[x]++;
    for (auto x : cnt) pfs.push_back(pfs.back() + x);
    for (int i = n; i >= 0; i--) {
        // cout << i << ' ' << pfs[3 * i] << ' ' << cnt[i] + cnt[2 * i] << '\n';
        if (pfs[4 * i] - cnt[i] - cnt[2 * i] - cnt[3 * i] <= k) {
            cout << i << '\n';
            return;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}