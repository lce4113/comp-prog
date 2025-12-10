#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

const std::string PARENS = "()[]{}";

int main() {
    int32_t n;
    std::cin >> n;
    std::string labels;
    std::cin >> labels;
    std::vector<std::vector<int32_t>> tree(n);
    for (auto i = 1; i < n; ++i) {
        int32_t u, v;
        std::cin >> u >> v;
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    std::vector<char> stk;
    auto solve = [&](auto&& self, int32_t u, int32_t p) -> int32_t {
        auto type = PARENS.find(labels[u]);
        if (type % 2 == 0) {
            stk.push_back(labels[u]);
        } else if (!stk.empty() && stk.back() == PARENS[type - 1]) {
            stk.pop_back();
        } else {
            return 0;
        }

        int32_t ans = stk.empty();
        for (auto v : tree[u]) {
            if (v == p) continue;
            ans += self(self, v, u);
        }

        if (type % 2 == 0) {
            stk.pop_back();
        } else {
            stk.push_back(PARENS[type - 1]);
        }

        return ans;
    };

    int32_t ans = 0;
    for (auto root = 0; root < n; ++root) {
        ans += solve(solve, root, -1);
    }

    std::cout << ans << '\n';

    return 0;
}
