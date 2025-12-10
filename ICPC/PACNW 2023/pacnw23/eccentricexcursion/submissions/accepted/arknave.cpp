#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

int main() {
    int32_t n, k;
    std::cin >> n >> k;

    auto roads = n - 1 - k;

    std::vector<std::vector<int32_t>> tree(n);
    for (auto i = 1; i < n; ++i) {
        int32_t u, v;
        std::cin >> u >> v;
        --u; --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    auto hasEdge = [&tree](int32_t u, int32_t v) -> bool {
        return std::find(tree[u].begin(), tree[u].end(), v) != tree[u].end();
    };

    std::vector<bool> used(n, false);

    // roads if u is free, roads if u is connected to parent
    auto compute = [&](auto&& self, std::vector<bool>& vis, int32_t u) -> std::array<int32_t, 2> {
        assert(!vis[u]);
        vis[u] = true;
        int32_t withoutSum = 0;
        std::array<int32_t, 2> matchWiths{-1, -1};
        for (auto v : tree[u]) {
            if (used[v] || vis[v]) continue;

            auto [subWithout, subWith] = self(self, vis, v);
            withoutSum += subWithout;

            int32_t with = subWith - subWithout + 1;
            if (with > matchWiths[0]) {
                matchWiths[1] = matchWiths[0];
                matchWiths[0] = with;
            } else if (with > matchWiths[1]) {
                matchWiths[1] = with;
            }
        }

        int32_t matchWithout = withoutSum;
        for (auto x : matchWiths) {
            if (x != -1) {
                matchWithout += x;
            }
        }

        int32_t matchWith = withoutSum;
        if (matchWiths[0] != -1) {
            matchWith += matchWiths[0];
        }

        return {matchWithout, matchWith};
    };

    // find min and max number of roads for a sequence starting with s
    auto bounds = [&](int32_t s, bool roadStart) -> std::array<int32_t, 2> {
        int32_t lo = 0;
        int32_t hi = roadStart;
        std::vector<bool> vis(n, false);
        {
            auto [match0, match1] = compute(compute, vis, s);
            hi += match1;
        }

        for (auto u = 0; u < n; ++u) {
            if (!used[u] && !vis[u]) {
                auto [match0, match1] = compute(compute, vis, u);
                hi += match0;
            }
        }

        // When can lo increase?
        // s is connected to all unused nodes
        // some other node u is connected to all unused parts except s.
        int32_t unusedSize = 0;
        for (auto u = 0; u < n; ++u) {
            unusedSize += !used[u];
        }

        int32_t sDegree = 0;
        for (auto u : tree[s]) {
            sDegree += !used[u];
        }

        if (sDegree > 0 && sDegree + 1 == unusedSize) {
            lo = 1;
        }

        for (auto u = 0; u < n; ++u) {
            if (u == s || used[u]) continue;
            int32_t deg = 0;
            for (auto v : tree[u]) {
                deg += !used[v];
            }

            if (deg > 0 && deg + 1 + !hasEdge(u, s) == unusedSize) {
                lo = 1;
            }
        }

        lo += roadStart;
        return {lo, hi};
    };

    std::vector<int32_t> ans;
    ans.reserve(n);

    int32_t cur = 0;
    for (auto i = 0; i < n; ++i) {
        for (auto u = 0; u < n; ++u) {
            if (used[u]) continue;

            bool usedRoad = !ans.empty() && hasEdge(ans.back(), u);
            auto [lo, hi] = bounds(u, usedRoad);
            if (cur + lo <= roads && roads <= cur + hi) {
                cur += usedRoad;
                ans.push_back(u);
                used[u] = true;
                break;
            }
        }

        if (ans.size() <= i) {
            break;
        }
    }

    if (ans.size() == n) {
        for (auto i = 0; i < n; ++i) {
            std::cout << ans[i] + 1 << " \n"[i + 1 == n];
        }
    } else {
        std::cout << -1 << '\n';
    }

    return 0;
}
