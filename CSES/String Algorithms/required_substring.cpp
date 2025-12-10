// CSES String Algorithms: Required Substring

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int P = 53;
const int MAXN = 100;

vector<int> pfs(1, 0), ps(MAXN + 1, 1);

int hsh(int h, int v) { return (h * P + v) % MOD; }
int hi(int l, int r) { return (pfs[r] - pfs[l] * ps[r - l] % MOD + MOD) % MOD; }

int binexp(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= MAXN; i++) ps[i] = ps[i - 1] * P % MOD;

    int m;
    cin >> m;
    string a;
    cin >> a;
    int n = a.size();
    for (auto x : a) pfs.push_back(hsh(pfs.back(), x - 'A'));
    vector<vector<int>> nxt(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < 26; v++) {
            bool ok = 0;
            for (int l = i, r = 0; l >= 0; l--, r++) {
                // cout << l << ' ' << r << ' ' << i << '\n';
                if (hi(0, l + 1) == hsh(hi(r, i), v)) {
                    nxt[i][v] = l + 1;
                    ok = 1;
                    break;
                }
            }
            if (!ok) nxt[i][v] = 0;
        }
    }

    vector<int> dp(n);
    dp[0] = 1;
    for (int M = m; M--;) {
        vector<int> ndp(n);
        for (int i = 0; i < n; i++) {
            for (int v = 0; v < 26; v++) {
                if (nxt[i][v] == n) continue;
                ndp[nxt[i][v]] += dp[i], ndp[nxt[i][v]] %= MOD;
            }
        }
        dp = ndp;
    }

    int ans = binexp(26, m);
    for (auto x : dp) ans += MOD - x, ans %= MOD;
    cout << ans << '\n';
}