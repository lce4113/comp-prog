// Codeforces Round #967: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
#define ll long long

int n, k, p;

int binexp(int a, int b = p - 2) {
    int ans = 1;
    for (; b; a = (a * a) % p) {
        if (b % 2) ans = (ans * a) % p;
        b >>= 1;
    }
    return ans;
}

void solve() {
    cin >> n >> k >> p;

    vector<int> dp(k + 1, 1);
    for (int j = 2, e = 2; j <= n; j++, e = (e * 2) % p) {
        vector<int> binom(k + 1, 1);
        for (int x = 1; x <= k; x++) {
            binom[x] = binom[x - 1];
            binom[x] = (binom[x] * (e - 2 + x)) % p;
            binom[x] = (binom[x] * binexp(x)) % p;
        }
        vector<int> dpn(k + 1, 0);
        for (int i = 1; i <= k; i++) {
            int sm = 0;
            for (int l = i, c = 0; l > i / 2; l--, c++) {
                sm = (sm + dp[l] * binom[c]) % p;
            }
            dpn[i] = (dpn[i - 1] + 2 * sm) % p;
        }
        dp = dpn;
    }
    cout << dp[k] << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}