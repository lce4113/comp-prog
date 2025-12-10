#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

/**
 * Range Editing
 *
 * Consider a set of operations that make up the answer. Note that the
 * intervals can mostly be applied left to right. Intervals are always nested
 * or disjoint. Let solve(l, r) be the minimum number of operations to solve
 * l to r with the base value being a[l].
 */
int main() {
    int32_t n;
    std::cin >> n;

    // add an extra 0 at the start to signify base value is 0
    std::vector<int64_t> a{0};
    for (auto i = 0; i < n; ++i) {
        int64_t x;
        std::cin >> x;
        // constant factor improvement, but why not
        if (x != a.back())
            a.push_back(x);
    }

    n = a.size();
    constexpr int32_t INF = 1e9;
    std::vector<std::vector<int32_t>> dp(n + 1, std::vector<int32_t>(n + 1, INF));

    std::fill(dp[1].begin(), dp[1].end(), 0);
    for (int32_t len = 2; len <= n; ++len) {
        for (int32_t i = 0; i + len <= n; ++i) {
            for (int32_t j = i + 1; j < i + len; ++j) {
                dp[len][i] = std::min(dp[len][i], (a[i] != a[j]) + dp[j - i][i] + dp[len - (j - i)][j]);
            }
        }
    }

    std::cout << dp[n][0] << '\n';

    return 0;
}
