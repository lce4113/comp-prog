#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <numeric>
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
    int32_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> mat(n);
    for (auto& row : mat) {
        std::cin >> row;
    }

    auto hasMatch = [&](int32_t colMask, int k) {
        DFSMatching match(n, m);
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if ((colMask >> j & 1) == 0) continue;

                if (mat[i][j] == '1')
                    match.addEdge(i, j);
            }
        }

        return match.findMatching() >= k;
    };

    std::vector<std::vector<int32_t>> serviceMasks(m + 1, std::vector<int32_t>());
    for (auto i = 0u; i < (1 << m); ++i) {
        int k = __builtin_popcount(i);
        serviceMasks[k].push_back(i);
    }

    int ans = 0;
    for (int k = 1; k <= m; k++) {
        bool ok = true;
        for (auto &serviceMask: serviceMasks[k]) {
            if (!hasMatch(serviceMask, k)) {
                ok = false;
                break;
            }
        }
        if (ok) ans = k;
        else break;
    }
    std::cout << ans << '\n';

    return 0;
}
