#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>

/**
 * Cramming for Finals
 *
 * For each circle, for each row, create two events to signify the seats that change. Run prefix sums over the rows to find the minimum value.
 * Total runtime is O(n d log n)
 */

std::vector<int32_t> getOffsets(int32_t d) {
    // if you ar x rows away, you can be up to y columns away and still be in range d. res[x] = y;

    int32_t d2 = d * d;
    std::vector<int32_t> res(d + 1);
    res[0] = d;
    for (int32_t x = 1; x <= d; ++x) {
        res[x] = res[x - 1];
        while (x * x + res[x] * res[x] > d2)
            --res[x];
    }

    return res;
}

using Circle = std::array<int32_t, 2>;

int main() {
    int32_t r, c, d, n;
    std::cin >> r >> c >> d >> n;

    std::vector<int32_t> offsets = getOffsets(d);

    std::map<int32_t, std::map<int32_t, int32_t>> events;
    std::set<Circle> circles;
    for (auto i = 0; i < n; ++i) {
        int32_t x, y;
        std::cin >> x >> y;
        circles.insert(Circle{x, y});

        for (int32_t dx = 0; dx <= d; ++dx) {
            int32_t dy = offsets[dx];
            if (x - dx >= 1) {
                events[x - dx][std::max(1, y - dy)] += 1;
                events[x - dx][std::min(c, y + dy) + 1] -= 1;
            }
            if (dx > 0 && x + dx <= r) {
                events[x + dx][std::max(1, y - dy)] += 1;
                events[x + dx][std::min(c, y + dy) + 1] -= 1;
            }
        }
    }

    int32_t ans = events.size() == r ? n : 0;
    for (const auto& [x, rowEvents] : events) {
        if (rowEvents.begin()->first != 1) {
            ans = 0;
        }
        if (ans == 0)
            break;

        auto cur = 0;
        for (auto [y, delta] : rowEvents) {
            cur += delta;

            if (y <= c && (circles.find(Circle{x, y}) == circles.end()))
                ans = std::min(ans, cur);
        }
    }

    std::cout << ans << '\n';

    return 0;
}
