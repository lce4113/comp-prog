#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    int32_t n, k;
    std::cin >> n >> k;
    std::unordered_map<std::string, int32_t> lookup;
    auto get_id = [&lookup](const std::string& s) -> int32_t {
        if (auto it = lookup.find(s); it != lookup.end()) {
            return it->second;
        } else {
            auto id = lookup.size();
            lookup.emplace(s, id);
            return id;
        }
    };

    std::vector<std::vector<int32_t>> problems(n);
    for (auto i = 0; i < n; ++i) {
        int32_t t;
        std::cin >> t;
        for (auto j = 0; j < t; ++j) {
            std::string topic;
            std::cin >> topic;
            problems[i].push_back(get_id(topic));
        }
    }

    std::vector<int32_t> usedTopics(lookup.size(), 0);

    auto solve = [&](auto&& self, int32_t idx, int32_t rem) -> int32_t {
        if (std::any_of(usedTopics.begin(), usedTopics.end(), [k](auto freq){ return 2 * freq > k; })) {
            return 0;
        }
        if (rem == 0) {
            return 1;
        }
        if (idx >= n) {
            return 0;
        }

        int32_t ans = self(self, idx + 1, rem);
        for (auto topic : problems[idx]) {
            ++usedTopics[topic];
        }
        ans += self(self, idx + 1, rem - 1);
        for (auto topic : problems[idx]) {
            --usedTopics[topic];
        }

        return ans;
    };

    int32_t ans = solve(solve, 0, k);

    std::cout << ans << '\n';

    return 0;
}
