// Codeforces Round 998: Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 998244353;
const int MAXK = 1e5, MAXF = 20;

vector<int> sieve(MAXK + 1), P;
vector<vector<int>> dp(MAXK + 1, vector<int>(MAXF + 1));

int binexp(int a, int b = MOD - 2) {
    int ans = 1;
    for (; b; a *= a, a %= MOD) {
        if (b % 2) ans *= a, ans %= MOD;
        b /= 2;
    }
    return ans;
}

map<int, int> pf(int n) {
    map<int, int> ps;
    while (n > 1) {
        ps[sieve[n]]++;
        n /= sieve[n];
    }
    return ps;
}

int ncr(int n, int r) {
    int ans = 1;
    for (int i = n - r + 1; i <= n; i++) ans *= i, ans %= MOD;
    for (int i = 2; i <= r; i++) ans *= binexp(i), ans %= MOD;
    return ans;
}

void solve() {
    int k, n;
    cin >> k >> n;

    cout << n << ' ';
    for (int c = 2; c <= k; c++) {
        auto pfk = pf(c);
        int tot = 0, ans = 0;
        for (auto x : pfk) tot += x.s;
        for (int j = 1; j <= tot; j++) {
            int perm = dp[c][j];
            perm *= ncr(n + 1, j + 1), perm %= MOD;
            ans += perm, ans %= MOD;
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

int32_t main() {
    for (int i = 2; i <= MAXK; i++) {
        if (sieve[i] == 0) sieve[i] = i, P.push_back(i);
        for (int j = 0; i * P[j] <= MAXK; j++) {
            sieve[i * P[j]] = P[j];
            if (P[j] == sieve[i]) break;
        }
    }

    vector<vector<int>> div(MAXK);
    for (int i = 2; i <= MAXK; i++) {
        for (int j = 2; i * j <= MAXK; j++) div[i * j].push_back(i);
    }

    for (int k = 1; k <= MAXK; k++) dp[k][1] = 1;
    for (int l = 2; l <= MAXF; l++) {
        for (int k = 2; k <= MAXK; k++) {
            for (auto x : div[k]) dp[k][l] += dp[x][l - 1];
        }
    }

    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}