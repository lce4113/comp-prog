// CSES Mathematics: Sum of Divisors

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int range_sum(int r) { return r * (r + 1) / 2; }

int32_t main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= n; i++) {
        ans += (n / i - i) * i, ans %= MOD;
        ans += range_sum((n / i) % MOD) - range_sum(i - 1), ans %= MOD;
    }
    cout << ans << '\n';
}
