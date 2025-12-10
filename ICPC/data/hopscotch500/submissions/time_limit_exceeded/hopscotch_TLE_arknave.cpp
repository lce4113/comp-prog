#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;

inline ll score(const pll& a, const pll& b) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;

    return min(dx * dx, dy * dy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vl> a(n, vl(n));
    vector<vector<pll>> occ(k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            --a[i][j];
            occ[a[i][j]].emplace_back(i, j);
        }
    }

    constexpr ll INF = 1e18;
    vector<vl> dp(n, vl(n, INF));

    for (const auto& p : occ[0]) {
        dp[p.first][p.second] = 0;
    }

    for (int i = 1; i < k; ++i) {
        for (const auto& p : occ[i - 1]) {
            for (const auto& q : occ[i]) {
                dp[q.first][q.second] = min(dp[q.first][q.second], dp[p.first][p.second] + score(p, q));
            }
        }
    }

    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cerr << dp[i][j] << ' ';
        }
        cerr << '\n';
    }
    cerr << '\n';
    */

    ll ans = INF;
    for (auto& p : occ[k - 1]) {
        ans = min(ans, dp[p.first][p.second]);
    }

    cout << (ans == INF ? -1LL : ans) << '\n';

    return 0;
}
