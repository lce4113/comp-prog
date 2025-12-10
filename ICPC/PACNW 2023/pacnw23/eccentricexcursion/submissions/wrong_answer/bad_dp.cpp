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

    // size, max degree, roads if u is free, roads if u is connected to parent
    auto compute = [&](auto&& self, std::vector<bool>& vis, int32_t u) -> std::array<int32_t, 4> {
        assert(!vis[u]);
        vis[u] = true;
        int32_t size = 1;
        int32_t maxDegree = 0;
        int32_t curDegree = 0;
        int32_t withoutSum = 0;
        std::array<int32_t, 2> matchWiths{-1, -1};
        for (auto v : tree[u]) {
            if (used[v] || vis[v]) continue;

            ++curDegree;
            auto [subSize, subDegree, subWithout, subWith] = self(self, vis, v);
            size += subSize;
            maxDegree = std::max(maxDegree, subDegree);
            withoutSum += subWithout;

            int32_t with = subWith - subWithout + 1;
            if (with > matchWiths[0]) {
                matchWiths[1] = matchWiths[0];
                matchWiths[0] = with;
            } else if (with > matchWiths[1]) {
                matchWiths[1] = with;
            }
        }

        maxDegree = std::max(maxDegree, curDegree);

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

        return {size, maxDegree, matchWithout, matchWith};
    };

    // find min and max number of roads for a sequence starting with s
    auto bounds = [&](int32_t s, bool roadStart) -> std::array<int32_t, 2> {
        int32_t unusedSize = 0;
        int32_t maxDegree = 0;
        int32_t hi = roadStart;
        std::vector<bool> vis(n, false);
        {
            auto [size, degree, match0, match1] = compute(compute, vis, s);
            unusedSize += size;
            maxDegree = std::max(maxDegree, degree);
            hi += match1;
        }

        for (auto u = 0; u < n; ++u) {
            if (!used[u] && !vis[u]) {
                auto [size, degree, match0, match1] = compute(compute, vis, u);
                unusedSize += size;
                maxDegree = std::max(maxDegree, degree);
                hi += match0;
            }
        }

        int32_t lo = roadStart + (maxDegree > 0 && maxDegree + 1 == unusedSize);
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
