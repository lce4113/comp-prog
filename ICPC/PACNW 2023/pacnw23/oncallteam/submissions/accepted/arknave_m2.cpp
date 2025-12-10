#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int main() {
    int32_t n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int32_t>> fixers(m);
    for (auto i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;

        for (auto j = 0; j < m; ++j) {
            if (s[j] == '1') {
                fixers[j].push_back(i);
            }
        }
    }

    std::vector<uint8_t> isRobust(m + 1, 1);
    for (auto mask = 1; mask < (1 << m); ++mask) {
        // auto pc = std::popcount(mask);
        auto pc = __builtin_popcount(mask);

        if (!isRobust[pc]) continue;

        // Hall's theorem: count the number of engineers who can fix at least one system in this subset
        // O(m^2) version: keep a hash set
        std::unordered_set<int32_t> neighbors;
        for (auto service = 0; neighbors.size() <= pc && service < m; ++service) {
            if ((mask >> service & 1) == 0) {
                continue;
            }
            for (auto engineer : fixers[service]) {
                if (neighbors.find(engineer) == neighbors.end()) {
                    neighbors.insert(engineer);
                }
                if (neighbors.size() >= pc) break;
            }
        }

        if (neighbors.size() < pc) {
            for (auto j = pc; j <= m; ++j) {
                isRobust[j] = false;
            }
        }
    }

    int32_t ans = m;
    while (!isRobust[ans])
        --ans;

    std::cout << ans << '\n';

    return 0;
}
