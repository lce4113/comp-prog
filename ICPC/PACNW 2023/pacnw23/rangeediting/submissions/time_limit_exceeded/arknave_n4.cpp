#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);

    int32_t n;
    std::cin >> n;

    std::vector<int32_t> a;
    a.reserve(n);
    std::unordered_map<int32_t, int32_t> lookup;
    lookup.insert({0, 0});
    auto m = 1;
    for (auto i = 0; i < n; ++i) {
        int32_t x;
        std::cin >> x;
        if (auto it = lookup.find(x); it != lookup.end()) {
            x = it->second;
        } else {
            lookup.emplace(x, m);
            x = m++;
        }
        if (a.empty() || a.back() != x) {
            a.push_back(x);
        }
    }
    n = a.size();
    std::vector<int32_t> dp(m * (n + 1) * (n + 1), 0);
    auto index = [n](int32_t i, int32_t j, int32_t k) -> int32_t {
        return (n + 1) * ((n + 1) * i + j) + k;
    };

    for (auto len = 1; len <= n; ++len) {
        for (auto l = 0; l + len <= n; ++l) {
            auto r = l + len;
            for (auto c = 0; c < m; ++c) {
                auto& ans = dp[index(c, len, l)];
                ans = len;
                if (a[l] == c) {
                    ans = std::min(ans, dp[index(c, len - 1, l + 1)]);
                }
                if (a[r - 1] == c) {
                    ans = std::min(ans, dp[index(c, len - 1, l)]);
                }
                if (len >= 2 && a[l] == a[r - 1]) {
                    ans = std::min(ans, 1 + dp[index(a[l], len - 2, l + 1)]);
                }

                ans = std::min(ans, 1 + dp[index(a[l], len - 1, l + 1)]);
                ans = std::min(ans, 1 + dp[index(a[r - 1], len - 1, l)]);

                for (auto k = l + 1; k < r; ++k) {
                    ans = std::min(ans, dp[index(c, k - l, l)] + dp[index(c, r - k, k)]);
                }
            }
        }
    }

    std::cout << dp[index(0, n, 0)] << '\n';

    return 0;
}
