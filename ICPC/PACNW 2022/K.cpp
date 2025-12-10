// ICPC 2022 Pacific Northwest Regionals
// Problem K

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 998244353;

int binexp(int a, int b) {
    int res = 1;
    for (; b; a *= a, a %= MOD, b /= 2)
        if (b % 2) res *= a, res %= MOD;
    return res;
}

vector<int> red(int n, int l) {
    vector<int> res;
    for (int i = 0; i < l; i++) res.push_back(n % 3), n /= 3;
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a) cin >> x;

    int qs = 0;
    for (auto x : a)
        for (auto y : x) qs += y == '?';

    map<char, int> mp;
    mp['I'] = 0, mp['C'] = 1, mp['P'] = 2;

    int N = binexp(3, m + 1);
    vector<int> dp(N, 1);
    for (int i = 0; i < N; i++) {
        auto ter = red(i, m + 1);
        for (int j = 0; j < m; j++) {
            if (a[0][j] != '?' && mp[a[0][j]] != ter[j]) dp[i] = 0;
        }
        if (a[1][0] != '?' && mp[a[1][0]] != ter.back()) dp[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 1 && j == 0) continue;
            vector<int> ndp(N);
            for (int k = 0; k < N; k++) {
                auto ter = red(k, m + 1);
                for (int l = 0; l < 3; l++) {
                    if (a[i][j] != '?' && l != mp[a[i][j]]) continue;
                    if (j != 0 && ter[0] == 0 && ter[1] == 1 && ter[m] == 2 &&
                        l == 1)
                        continue;
                    int nk = k / 3 + binexp(3, m) * l;
                    ndp[nk] += dp[k], ndp[nk] %= MOD;
                }
            }
            dp = ndp;
            // for (auto x : dp) cout << x << ' ';
            // cout << '\n';
        }
    }

    int ans = binexp(3, qs);
    for (auto x : dp) ans += MOD - x, ans %= MOD;
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}