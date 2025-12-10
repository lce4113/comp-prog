#include <cstdint>
#include <iostream>
#include <vector>

int main() {
    int32_t n;
    std::cin >> n;
    std::vector<int32_t> a(n);
    for (auto& x : a) {
        std::cin >> x;
    }

    constexpr int32_t INF = 1e9;
    std::vector<int32_t> ans;
    for (auto k = 2; k <= n; ++k) {
        if (n % k) continue;

        auto sectionSize = n / k;
        bool valid = true;
        int32_t lastMax = 0;
        int32_t curMax = 0;
        int32_t curMin = INF;
        for (auto i = 0; i < n; ++i) {
            if (i % sectionSize == 0) {
                lastMax = curMax;
                curMax = 0;
                curMin = INF;
            }

            curMax = std::max(curMax, a[i]);
            curMin = std::min(curMin, a[i]);

            if (curMin < lastMax) {
                valid = false;
            }
        }

        if (valid)
            ans.push_back(k);
    }

    if (ans.empty()) {
        std::cout << -1 << '\n';
    } else {
        for (auto i = 0; i < ans.size(); ++i) {
            std::cout << ans[i] << '\n';
        }
    }

    return 0;
}
