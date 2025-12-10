// Codeforces Round 1015: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;
const int MAXN = 1e4;

vector<int> fact(MAXN + 1, 1);
vector<int> fact_inv(MAXN + 1, 1);

int binexp(int a, int b = MOD - 2) {
    int ans = 1;
    for (; b; a *= a, a %= MOD, b /= 2) {
        if (b % 2) ans *= a, ans %= MOD;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> np(1, 0);
    for (auto x : a) np.push_back(np.back() + (x == -1));
    vector<int> mp(1, n), rmp(1, n);
    for (auto x : a) mp.push_back(x == -1 ? mp.back() : min(x, mp.back()));
    reverse(a.begin(), a.end());
    for (auto x : a) rmp.push_back(x == -1 ? rmp.back() : min(x, rmp.back()));

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int y = min(mp[i], rmp[n - 1 - j]);
            int c1 = np[j + 1] - np[i];
            // cout << i << ' ' << j << ' ' << y << ' ' << c1 << '\n';
            dp[y][c1]++, dp[y][c1] %= MOD;
        }
    }

    for (int k = n - 1; k >= 0; k--) {
        for (int i = 0; i <= n; i++) {
            dp[k][i] += dp[k + 1][i], dp[k][i] %= MOD;
        }
    }

    vector<int> fixed(n, 0);
    for (auto x : a) {
        if (x == -1) continue;
        fixed[x]++;
    }
    for (int i = 1; i < n; i++) fixed[i] += fixed[i - 1];

    // for (auto x : fixed) cout << x << ' ';
    // cout << '\n';

    int ans = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i <= n; i++) {
            int c2 = k - fixed[k - 1];
            if (i < c2) continue;
            // cout << i << ' ' << k << ' ' << dp[k][i] << ' ' << fixed[k - 1]
            //      << '\n';
            int c = fact[i] * fact_inv[c2] % MOD;
            c *= fact_inv[i - c2], c %= MOD;
            c *= fact[c2], c %= MOD;
            c *= fact[np[n] - c2], c %= MOD;
            c *= dp[k][i], c %= MOD;
            // cout << c << '\n';
            ans += c, ans %= MOD;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i, fact[i] %= MOD;
    for (int i = 1; i <= MAXN; i++) fact_inv[i] = binexp(fact[i]);

    int t;
    cin >> t;
    while (t--) solve();
}