// Codeforces Educational Round 183: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 30;
array<int, 2> dp[N + 1][N * (N - 1) / 2 + 1][N + 1];

void out(array<int, 2> c, int n) {
    vector<bool> flip(n - 1, 0);
    for (int i = n; i > 1; i--) {
        if (c[1] == 1) flip[i - 2] = 1;
        c = dp[i][c[0]][c[1]];
    }
    vector<int> res(n);
    iota(res.begin(), res.end(), 1);
    for (int i = 0; i < n - 1; i++) {
        int start = i;
        while (i < n - 1 && flip[i] == 1) i++;
        reverse(res.begin() + start,
                i + 1 == n ? res.end() : res.begin() + i + 1);
    }
    for (auto x : res) cout << x << ' ';
    cout << '\n';
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int j = 0; j <= N; j++) {
        if (dp[n][k][j][0] != -1) {
            out({k, j}, n);
            return;
        }
    }
    cout << "0\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    // dp[num][invs][since] = {-1,-1} / {invs, since}
    // dp[i+1][iv+s+a][0] = {iv,s}
    // dp[i+1][iv+a][s+1] = {iv,s}
    memset(dp, -1, sizeof(dp));
    dp[1][0][1] = {-2, -2};
    for (int i = 1; i < N; i++) {
        for (int iv = 0; iv <= N * (N - 1) / 2; iv++) {
            for (int s = 0; s <= N; s++) {
                if (dp[i][iv][s][0] == -1) continue;
                dp[i + 1][iv + i][1] = {iv, s};
                dp[i + 1][iv + (i - s)][s + 1] = {iv, s};
            }
        }
    }

    int t = 1;
    cin >> t;
    while (t--) solve();
}