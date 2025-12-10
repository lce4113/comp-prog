#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using pii = pair<int32_t, int32_t>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<int64_t>> a(n, vector<int64_t>(n));
    vector<vector<pii>> occ(k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            --a[i][j];
            occ[a[i][j]].emplace_back(i, j);
        }
    }

    constexpr int64_t INF = 1e18;
    vector<vector<int64_t>> dp(n, vector<int64_t>(n, INF));

    for (const auto& [x, y] : occ[0]) {
        dp[x][y] = 0;
    }

    for (int i = 1; i < k; ++i) {
        vector<int64_t> x_score(n, INF), y_score(n, INF);
        for (const auto& [x, y] : occ[i - 1]) {
            x_score[x] = min(x_score[x], dp[x][y]);
            y_score[y] = min(y_score[y], dp[x][y]);
        }

        for (const auto& [x, y] : occ[i]) {
            int64_t& cur = dp[x][y];
            for (int px = 0; px < n; ++px) {
                cur = min(cur, x_score[px] + (px - x) * (px - x));
            }
            for (int py = 0; py < n; ++py) {
                cur = min(cur, y_score[py] + (py - y) * (py - y));
            }
        }
    }

    int64_t ans = INF;
    for (auto& [x, y] : occ[k - 1]) {
        ans = min(ans, dp[x][y]);
    }

    cout << (ans == INF ? -1LL : ans) << '\n';

    return 0;
}
