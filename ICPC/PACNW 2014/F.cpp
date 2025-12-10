// ICPC Pacific Northwest Regional 2014
// Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXB = 35;
const int MOD = 1e9 + 9;
int n, m;

vector<vector<int>> arr(int b) {
    vector<vector<int>> res(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2; j++) {
            if (b % 2) res[i][j] = 1;
            b /= 2;
        }
    }
    return res;
}

bool test1(int b) {
    auto cols = arr(b);
    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 8; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 || nx >= m) continue;
                if (ny < 0 || ny >= 2) continue;
                if (cols[i][j] && cols[nx][ny]) return 0;
            }
        }
    }
    // for (auto x : cols) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';
    return 1;
}

bool test_pair(int b1, int b2) {
    auto cols1 = arr(b1), cols2 = arr(b2);
    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 8; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 || nx >= m) continue;
                if (ny < 0 || ny >= 4) continue;
                int p1 = j < 2 ? cols1[i][j] : cols2[i][j - 2];
                int p2 = ny < 2 ? cols1[nx][ny] : cols2[nx][ny - 2];
                if (p1 && p2) return 0;
            }
        }
    }
    return 1;
}

bool is_one(int x) {
    auto cols = arr(x);
    for (int i = 0; i < m; i++) {
        if (cols[i][1]) return 0;
    }
    return 1;
}

void solve() {
    cin >> m >> n;

    vector<int> types;
    for (int i = 0; i < (1 << 2 * m); i++) {
        if (test1(i)) types.push_back(i);
    }

    vector<pair<int, int>> val_pairs;
    int N = types.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (test_pair(types[i], types[j])) {
                val_pairs.push_back({i, j});
            }
        }
    }

    vector<vector<vector<int>>> dp(MAXB + 1,
                                   vector<vector<int>>(N, vector<int>(N)));
    for (auto x : val_pairs) dp[2][x.f][x.s]++;
    for (int e = 3; e <= MAXB; e++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (auto x : val_pairs) {
                    dp[e][i][j] += dp[e - 1][i][x.f] * dp[e - 1][x.s][j];
                    dp[e][i][j] %= MOD;
                }
            }
        }
    }

    vector<vector<int>> ans(N, vector<int>(N));
    int first = true;
    for (int c = n / 4, e = 2; c; c /= 2, e++) {
        if (c % 2 == 0) continue;
        if (first) {
            ans = dp[e];
            first = false;
            continue;
        }
        vector<vector<int>> nans(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (auto x : val_pairs) {
                    nans[i][j] += ans[i][x.f] * dp[e][x.s][j];
                    nans[i][j] %= MOD;
                }
            }
        }
        ans = nans;
        first = false;
    }

    if ((n / 2) % 2) {
        if (first) {
            for (int i = 0; i < N; i++) ans[i][i] = 1;
            first = false;
        } else {
            vector<vector<int>> nans(N, vector<int>(N));
            for (int i = 0; i < N; i++) {
                for (auto x : val_pairs) {
                    nans[i][x.s] += ans[i][x.f];
                    nans[i][x.s] %= MOD;
                }
            }
            ans = nans;
        }
    }

    if (n % 2) {
        if (first) {
            for (int i = 0; i < N; i++) {
                if (is_one(types[i])) ans[i][i] = 1;
            }
            first = false;
        } else {
            vector<vector<int>> nans(N, vector<int>(N));
            for (int i = 0; i < N; i++) {
                for (auto x : val_pairs) {
                    if (is_one(types[x.s])) {
                        nans[i][x.s] += ans[i][x.f];
                        nans[i][x.s] %= MOD;
                    }
                }
            }
            ans = nans;
        }
    }

    int sum = 0;
    for (auto x : ans) {
        for (auto y : x) sum += y, sum %= MOD;
    }
    cout << sum << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}