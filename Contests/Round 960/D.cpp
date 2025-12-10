// Codeforces Round 960: Problem D
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
    for (auto &x : a) x++, x /= 2;

    vector<int> pfs2(1, 0), p1;
    for (auto x : a) pfs2.push_back(pfs2.back() + (x != 2));
    // for (auto x : pfs2) cout << x << ' ';
    // cout << '\n';
    for (int i = 0; i < n; i++)
        if (a[i] == 1) p1.push_back(i);

    int ans = 0;
    for (auto x : a) ans += (x != 0);

    for (int i = 1; i < p1.size(); i++) {
        // cout << p1[i - 1] << ' ' << p1[i] << '\n';
        if (pfs2[p1[i]] == pfs2[p1[i - 1] + 1] && (p1[i] - p1[i - 1]) % 2) {
            ans--, i++;
        }
    }

    cout << ans << '\n';
}
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}