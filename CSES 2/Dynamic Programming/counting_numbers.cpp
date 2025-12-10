// CSES Dynamic Programming: Counting Numbers

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int binexp(int a, int b) {
    int res = 1;
    for (; b; a *= a, b /= 2)
        if (b % 2) res *= a;
    return res;
}

vector<int> d(int n) {
    vector<int> res;
    while (n) res.push_back(n % 10), n /= 10;
    reverse(res.begin(), res.end());
    return res;
}

int cnt(int n) {
    if (n == -1) return 0;
    if (n == 0) return 1;
    vector<int> ds = d(n);
    int N = ds.size();
    vector<vector<pair<int, int>>> dp(N, vector<pair<int, int>>(10));
    for (int i = 1; i < ds[0]; i++) dp[0][i] = {1, 0};
    dp[0][ds[0]] = {0, 1};
    for (int i = 1; i < N; i++) {
        int sm1 = 0, sm2 = 0;
        for (auto x : dp[i - 1]) sm1 += x.f, sm2 += x.s;
        for (int j = 0; j < 10; j++) {
            dp[i][j].f = sm1 - dp[i - 1][j].f;
            if (j < ds[i]) dp[i][j].f += sm2 - dp[i - 1][j].s;
        }
        dp[i][ds[i]].s = sm2 - dp[i - 1][ds[i]].s;
    }
    int ans = 0;
    for (auto x : dp.back()) ans += x.f + x.s;
    ans += cnt(binexp(10, N - 1) - 1);
    return ans;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int l, r;
    cin >> l >> r;
    cout << cnt(r) - cnt(l - 1) << '\n';
}
