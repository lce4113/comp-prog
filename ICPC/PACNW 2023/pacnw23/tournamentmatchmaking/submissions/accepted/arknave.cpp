#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
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

bool canMatch(const std::vector<std::array<int32_t, 2>>& teamA, const std::vector<std::array<int32_t, 2>>& teamB) {
    DFSMatching smallMatching(15, 15);
    for (auto i = 0; i < teamA.size(); ++i) {
        auto [u, v] = teamA[i];
        smallMatching.addEdge(i, u);
        smallMatching.addEdge(i, v);
    }

    for (auto i = 0; i < teamB.size(); ++i) {
        auto [u, v] = teamB[i];
        smallMatching.addEdge(i + teamA.size(), u);
        smallMatching.addEdge(i + teamA.size(), v);
    }

    return smallMatching.findMatching() == 15;
}

int main() {
    int32_t n;
    std::cin >> n;

    std::vector<std::vector<std::array<int32_t, 2>>> groups(n);
    for (auto& group : groups) {
        int32_t k;
        std::cin >> k;
    
        group.resize(k);
        for (auto& [u, v] : group) {
            std::cin >> u >> v;
            --u; --v;
        }
    }

    DFSMatching bigMatching(n, n);
    for (auto u = 0; u < n; ++u) {
        if (groups[u].size() % 2 != 0) continue;

        for (auto v = 0; v < n; ++v) {
            if (groups[u].size() + groups[v].size() != 15) continue;

            if (canMatch(groups[u], groups[v])) {
                bigMatching.addEdge(u, v);
            }
        }
    }

    std::cout << bigMatching.findMatching() << '\n';

    return 0;
}
