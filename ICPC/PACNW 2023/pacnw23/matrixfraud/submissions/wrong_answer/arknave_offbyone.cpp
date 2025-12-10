#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>

constexpr int32_t INF = std::numeric_limits<int32_t>::max() / 4;

int main() {
    int32_t m, n;
    std::cin >> m >> n;
    std::vector<std::string> matrix(m);
    for (auto& row : matrix) {
        std::cin >> row;
    }

    if (m < n) {
        // transpose
        std::vector<std::string> flip(n);
        for (auto i = 0; i < n; ++i) {
            flip[i].assign(m, '0');
            for (auto j = 0; j < m; ++j) {
                flip[i][j] = matrix[j][i];
            }
        }

        matrix = std::move(flip);
        std::swap(m, n);
    }

    assert(m >= n);
    std::vector<std::vector<int32_t>> dp(n, std::vector<int32_t>(n, INF));
    std::vector<int32_t> psum(n + 1, 0);
    for (auto i = 0; i < m; ++i) {
        for (auto j = 0; j < n; ++j) {
            psum[j + 1] = psum[j] + (matrix[i][j] - '0');
        }

        std::vector<int32_t> prevDp = dp[0];
        std::vector<std::vector<int32_t>> ndp(n, std::vector<int32_t>(n, INF));
        for (auto l = 0; l < n; ++l) {
            for (auto r = 0; r < n; ++r) {
                prevDp[r] = std::min(prevDp[r], dp[l][r]);
            }

            int32_t bestDp = prevDp[l];
            for (auto r = l; r < n; ++r) {
                // min cost to make this row's band [l, r]
                int32_t zeroLeft = psum[l];
                int32_t oneRange = (r - l + 1) - (psum[r + 1] - psum[l]);
                int32_t zeroRight = psum[n] - psum[r + 1];
                bestDp = std::min(bestDp, prevDp[r]);
                if (i == 0)
                    bestDp = l == 0 ? 0 : INF;

                ndp[l][r] = std::min(ndp[l][r], zeroLeft + oneRange + zeroRight + bestDp);
            }
        }

        dp = std::move(ndp);
    }

    int32_t ans = INF;
    for (auto l = 0; l < n; ++l) {
        ans = std::min(ans, dp[l][n - 1]);
    }

    std::cout << ans << '\n';

    return 0;
}
