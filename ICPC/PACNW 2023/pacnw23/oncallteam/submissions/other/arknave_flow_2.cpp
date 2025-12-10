#include <algorithm>
#include <array>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

struct DFSMatching {
    DFSMatching(int32_t n, int32_t m): n_(n), m_(m), graph_(n), rev_(m, -1), vis_(m, 0) {}

    void addEdge(int32_t u, int32_t v) {
        graph_[u].push_back(v);
    }

    bool find(int32_t v) {
        if (rev_[v] == -1) return true;
        vis_[v] = true;
        int32_t u = rev_[v];
        for (auto w : graph_[u]) {
            if (!vis_[w] && find(w)) {
                rev_[w] = u;
                return true;
            }
        }

        return false;
    }

    // return the size of the maximum matching
    int32_t findMatching() {
        for (auto i = 0; i < n_; ++i) {
            std::fill(vis_.begin(), vis_.end(), 0);
            for (auto j : graph_[i]) {
                if (find(j)) {
                    rev_[j] = i;
                    break;
                }
            }
        }

        return m_ - std::count(rev_.begin(), rev_.end(), -1);
    }

    int32_t n_, m_;
    std::vector<std::vector<int32_t>> graph_;
    std::vector<int32_t> rev_;
    std::vector<uint8_t> vis_;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

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

    std::vector<int32_t> usefulEng;
    usefulEng.reserve((m + 1) * (m + 1));
    for (auto j = 0; j < m; ++j) {
        // TODO: shuffle?
        if (fixers[j].size() > m) {
            fixers[j].resize(m + 1);
        }
        for (auto eng : fixers[j]) {
            usefulEng.push_back(eng);
        }
    }

    std::sort(usefulEng.begin(), usefulEng.end());
    usefulEng.erase(std::unique(usefulEng.begin(), usefulEng.end()), usefulEng.end());

    for (auto j = 0; j < m; ++j) {
        for (auto& eng : fixers[j]) {
            eng = std::lower_bound(usefulEng.begin(), usefulEng.end(), eng) - usefulEng.begin();
        }
    }

    auto hasMatch = [&](int32_t serviceMask, int32_t k) -> bool {
        DFSMatching match(k, usefulEng.size());
        for (auto j = 0, idx = 0; j < m; ++j) {
            if ((serviceMask >> j & 1) == 0) continue;

            for (auto eng : fixers[j]) {
                match.addEdge(idx, eng);
            }
            idx++;
        }

        return match.findMatching() >= k;
    };

    std::vector<std::vector<int32_t>> serviceMasks(m + 1);
    for (auto i = 0; i < (1 << m); ++i) {
        auto k = __builtin_popcount(i);
        serviceMasks[k].push_back(i);
    }

    int32_t lo = 0;
    int32_t hi = m + 1;

    while (lo + 1 < hi) {
        int32_t k = (lo + hi) / 2;
        bool valid = true;
        for (auto serviceMask : serviceMasks[k]) {
            if (!hasMatch(serviceMask, k)) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            hi = k;
        } else {
            lo = k;
        }
    }

    std::cout << lo << '\n';
    return 0;
}
