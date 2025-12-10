#include <bits/stdc++.h>
using namespace std;

#define int long long
const int C = pow(3, 10);

vector<int> D(int n) {
    vector<int> res;
    while (n) {
        res.push_back(n % 10);
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int calc(int n) {
    auto digs = D(n);
    // dp[ind][digit_cnt][pref_same]
    // C = 3^10 = total counts
    int dp[digs.size() + 1][C][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0][1] = 1;
    for (int i = 1; i <= digs.size(); i++) {
        for (int c = 0; c < C; c++) {
            int cd = c;
            for (int d = 0, pw = 1; d < 10; d++, pw *= 3, cd /= 3) {
                if (cd % 3 == 2) continue;
                int nxt = d == 0 && c == 0 ? c : c + pw;
                dp[i][nxt][0] += dp[i - 1][c][0];
                if (d < digs[i - 1]) dp[i][nxt][0] += dp[i - 1][c][1];
                if (d == digs[i - 1]) dp[i][nxt][1] += dp[i - 1][c][1];
            }
        }
    }
    int ans = 0;
    for (auto x : dp[digs.size()]) ans += x[0], ans += x[1];
    return ans;
}

int32_t main() {
    ifstream cin("exchange.in");
    ofstream cout("exchange.out");

    int l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << '\n';
}