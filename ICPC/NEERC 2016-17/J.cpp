// NEERC 2016-17: Problem J

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int N = 100, M = 100;
const int INF = 1e18;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    // dp[index][# of bottles][capacity] = max initial amount
    // max -> dp[i+1][#+1][cap+cur_cap] = dp[index][# of bottles][capacity]
    // + amount
    // max -> dp[i+1][#][cap] = dp[index][# of bottles][capacity]
    // choose from -> capacity >= total amount

    /*
    dp[index][capacity] = max of -> {-# of bottles, initial amount}
    max -> dp[i+1][cap+cur_cap] =
        {dp[index][capacity].f - 1, dp[index][capacity].s + amount}
    max -> dp[i+1][cap] = dp[index][capacity]
    choose from -> capacity >= total amount
    */

    int n;
    cin >> n;
    vector<pair<int, int>> b(n);
    for (auto &x : b) cin >> x.f;
    for (auto &x : b) cin >> x.s;
    vector<pair<int, int>> dp(N * M + 1, {-INF, 0});
    dp[0] = {0, 0};
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> ndp(N * M + 1, {-INF, 0});
        for (int c = 0; c <= N * M; c++) {
            if (c + b[i].s <= N * M) {
                pair<int, int> nxt = {dp[c].f - 1, dp[c].s + b[i].f};
                ndp[c + b[i].s] = max(ndp[c + b[i].s], nxt);
            }
            ndp[c] = max(ndp[c], dp[c]);
        }
        swap(dp, ndp);
    }
    int tot = 0;
    for (int i = 0; i < n; i++) tot += b[i].f;
    pair<int, int> ans = {-INF, 0};
    for (int i = tot; i <= N * M; i++) {
        ans = max(ans, dp[i]);
    }
    cout << -ans.f << ' ' << tot - ans.s << '\n';
}