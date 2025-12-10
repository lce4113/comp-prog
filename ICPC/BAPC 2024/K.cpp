// BAPC 2024: Problem K

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
const int MOD = 1e9 + 7;
const pair<int, int> P = {37, 53};
const int MAXN = 5000;

vector<pair<int, int>> pfs(1, {0, 0});
vector<pair<int, int>> ps(MAXN + 1, {1, 1});

pair<int, int> hsh(pair<int, int> h, int v) {
    return {(h.f * P.f + v) % MOD, (h.s * P.s + v) % MOD};
}
pair<int, int> hi(int l, int r) {
    return {(pfs[r].f - pfs[l].f * ps[r - l].f % MOD + MOD) % MOD,
            (pfs[r].s - pfs[l].s * ps[r - l].s % MOD + MOD) % MOD};
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= MAXN; i++) ps[i].f = ps[i - 1].f * P.f % MOD;
    for (int i = 1; i <= MAXN; i++) ps[i].s = ps[i - 1].s * P.s % MOD;

    string a;
    cin >> a;
    for (auto x : a) pfs.push_back(hsh(pfs.back(), x));
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n + 1));
    int ans = n + 1;
    for (int l = 1; l <= n; l++) {
        map<pair<int, int>, vector<int>> mp;
        for (int i = 0; i + l <= n; i++) {
            pair<int, int> H = hi(i, i + l);
            auto it = upper_bound(mp[H].begin(), mp[H].end(), i - l);
            if (it == mp[H].begin()) {
                dp[i][l] = 1;
            } else {
                it--;
                dp[i][l] = 1 + dp[*it][l];
            }
            mp[H].push_back(i);
            ans = min(ans, n - (dp[i][l] - 1) * (l - 1) + 1);
        }
    }
    cout << ans << '\n';
}