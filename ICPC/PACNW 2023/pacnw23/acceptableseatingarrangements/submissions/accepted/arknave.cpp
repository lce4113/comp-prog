#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

int main() {
    int32_t r, c;
    std::cin >> r >> c;
    int32_t n = r * c;
    std::vector<int32_t> a(n);
    for (auto& x: a) {
        std::cin >> x;
        --x;
    }

    std::vector<int32_t> b(n);
    for (auto& x: b) {
        std::cin >> x;
        --x;
    }

    std::vector<std::array<int32_t, 2>> moves;
    for (int32_t v = 0; v < n; ++v) {
        int32_t aIdx = std::find(a.begin(), a.end(), v) - a.begin();
        int32_t bIdx = std::find(b.begin(), b.end(), v) - b.begin();

        int32_t aEnd = (aIdx / c + 1) * c;

        while (a[bIdx] != v) {
            int32_t swapIdx = std::lower_bound(a.begin() + aIdx, a.begin() + aEnd, a[bIdx]) - a.begin();
            --swapIdx;

            moves.push_back({bIdx, swapIdx});
            std::swap(a[bIdx], a[swapIdx]);
        }
    }

    std::cout << moves.size() << '\n';
    for (auto [x, y] : moves) {
        auto r1 = x / c + 1;
        auto c1 = x % c + 1;
        auto r2 = y / c + 1;
        auto c2 = y % c + 1;

        std::cout << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << '\n';
    }

    return 0;
}
