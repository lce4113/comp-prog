#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> u(m), v(m), w(m);
    for (int i = 0; i < m; i++) {
        std::cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
    }

    int lo = -1, hi = 1E9;

    while (lo < hi) {
        int x = (lo + hi + 1) / 2;
        bool ok = false;
        std::vector<int> dp(n);
        for (int t = 1; t < 2 * k; t++) {
            std::vector g(n, -inf);
            for (int i = 0; i < m; i++) {
                g[v[i]] = std::max(g[v[i]], dp[u[i]] + (w[i] >= x ? 1 : -1));
            }
            dp = std::move(g);
            if (t >= k && *std::max_element(dp.begin(), dp.end()) > 0) {
                ok = true;
                break;
            }
        }
        if (ok) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    std::cout << lo << "\n";

    return 0;
}