#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>

constexpr int32_t INF = std::numeric_limits<int32_t>::max() / 4;

// zero indexed
struct SegTree {
    using T = int32_t;
    static constexpr T UNIT = INF;
    static T f(T a, T b) { return std::min(a, b); }

    int32_t n;
    std::vector<T> data;
    SegTree(int32_t n): n(n) {
        data.assign(2 * n, UNIT);
    }

    // a[i] = v
    void update(int32_t i, T v) {
        i += n;
        data[i] = v;
        for (i >>= 1; i; i >>= 1) {
            data[i] = f(data[i << 1], data[i << 1 | 1]);
        }
    }

    // query [l, r)
    T query(int32_t l, int32_t r) {
        T res_left = UNIT, res_right = UNIT;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res_left  = f(res_left , data[l++]);
            if (r & 1) res_right = f(data[--r], res_right);
        }

        return f(res_left, res_right);
    }

    const T& operator[](int32_t i) const {
        return data[i + n];
    }
};

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
    std::vector<std::vector<int32_t>> dp(n, std::vector<int32_t>(n, 0));
    std::vector<int32_t> psum(n + 1, 0);
    for (auto i = 0; i < m; ++i) {
        for (auto j = 0; j < n; ++j) {
            psum[j + 1] = psum[j] + (matrix[i][j] - '0');
        }

        SegTree bestDp(n);
        std::vector<std::vector<int32_t>> ndp(n, std::vector<int32_t>(n, INF));
        for (auto l = 0; l < n; ++l) {
            for (auto idx = 0; idx < n; ++idx) {
                bestDp.update(idx, SegTree::f(bestDp[idx], dp[l][idx]));
            }

            for (auto r = l; r < n; ++r) {
                // min cost to make this row's band [l, r]
                int32_t zeroLeft = psum[l];
                int32_t oneRange = (r - l + 1) - (psum[r + 1] - psum[l]);
                int32_t zeroRight = psum[n] - psum[r + 1];
                int32_t best = bestDp.query(std::max(0, l - 1), r + 1);
                if (i == 0) {
                    best = l == 0 ? 0 : INF;
                }

                ndp[l][r] = std::min(ndp[l][r], zeroLeft + oneRange + zeroRight + best);
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
