#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <limits>
#include <utility>

constexpr int32_t INF = std::numeric_limits<int32_t>::max() / 4;
constexpr int32_t MAXN = 200000;
char s[MAXN + 1];
char t[MAXN + 1];
int32_t dp[2][MAXN];
int32_t prevDp[MAXN];
int32_t psum[MAXN + 1];

int main() {
    int32_t m, n;
    std::cin >> m >> n;
    std::cin.read(&s[0], 1); // flush the newline
    for (auto i = 0; i < m; ++i) {
        std::cin.read(&s[n * i], n + 1);
    }

    char *data = s;
    if (m < n) {
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                t[m * j + i] = s[n * i + j];
            }
        }

        data = t;
        std::swap(m, n);
    }

    assert(m >= n);
    std::memset(dp[0], 0x3f, sizeof(int32_t) * n * n);
    psum[0] = 0;
    {
        auto i = 0;
        psum[0] = 0;
        for (auto j = 0; j < n; ++j) {
            psum[j + 1] = psum[j] + (data[n * i + j] - '0');
        }

        auto l = 0;
        for (auto r = l; r < n; ++r) {
            int32_t zeroLeft = psum[l];
            int32_t oneRange = (r - l + 1) - (psum[r + 1] - psum[l]);
            int32_t zeroRight = psum[n] - psum[r + 1];

            dp[0][n * l + r] = zeroLeft + oneRange + zeroRight;
        }
    }

    auto row = 1;
    for (auto i = 1; i < m; ++i, row ^= 1) {
        psum[0] = 0;
        for (auto j = 0; j < n; ++j) {
            psum[j + 1] = psum[j] + (data[n * i + j] - '0');
        }
        for (auto j = 0; j < n; ++j) {
            prevDp[j] = dp[row ^ 1][j];
        }

        std::memset(dp[row], 0x3f, sizeof(int32_t) * n * n);

        for (auto l = 0; l < n; ++l) {
            for (auto r = 0; r < n; ++r) {
                prevDp[r] = std::min(prevDp[r], dp[row ^ 1][n * l + r]);
            }

            int32_t bestDp = prevDp[l == 0 ? 0 : l - 1];
            for (auto r = l; r < n; ++r) {
                // min cost to make this row's band [l, r]
                int32_t zeroLeft = psum[l];
                int32_t oneRange = (r - l + 1) - (psum[r + 1] - psum[l]);
                int32_t zeroRight = psum[n] - psum[r + 1];
                bestDp = std::min(bestDp, prevDp[r]);

                dp[row][n * l + r] = std::min(dp[row][n * l + r], zeroLeft + oneRange + zeroRight + bestDp);
            }
        }
    }

    row ^= 1;
    int32_t ans = INF;
    for (auto l = 0; l < n; ++l) {
        ans = std::min(ans, dp[row][n * l + n - 1]);
    }

    std::cout << ans << '\n';

    return 0;
}
