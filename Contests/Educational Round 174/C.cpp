// Codeforces Educational Round 174
// Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), dp(n);
    for (auto &x : a) cin >> x;
    int c1 = 0, c2 = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) c1++, c1 %= MOD;
        if (a[i] == 2) c2 += c2, c2 %= MOD, c2 += c1, c2 %= MOD;
        if (a[i] == 3) ans += c2, ans %= MOD;
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}