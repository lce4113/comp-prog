#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

constexpr int32_t MAXV = 100000;

int main() {
    std::vector<int32_t> sequence{0};
    while (sequence.back() < MAXV) {
        sequence.push_back(sequence.back() + 1);
        sequence.push_back(sequence.back() + 2);
    }

    sequence.pop_back();
    assert(sequence.back() == MAXV);

    std::cout << sequence.size() << '\n';

    std::vector<bool> isFixed(MAXV, false);
    while (true) {
        int32_t x;
        std::cin >> x;
        if (x == -1) {
            break;
        }

        if (x % 3 == 0) {
            // who needs math
            auto idx = std::distance(sequence.begin(), std::lower_bound(sequence.begin(), sequence.end(), x));
            std::cout << idx + 1 << std::endl;
        } else if (x == sequence.back()) {
            std::cout << sequence.size() << std::endl;
        } else {
            if (isFixed[x / 3]) {
                auto idx = std::distance(sequence.begin(), std::lower_bound(sequence.begin(), sequence.end(), x - (x % 3)));
                std::cout << idx + 2 << std::endl;
            } else {
                isFixed[x / 3] = true;
                auto it = std::lower_bound(sequence.begin(), sequence.end(), x);
                if (*it == x) {
                    ++*it;
                }
                std::cout << -1 << std::endl;
            }
        }
    }

    for (auto i = 0u; i < sequence.size(); ++i) {
        std::cout << sequence[i];
        if (i + 1 < sequence.size()) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;

    return 0;
}
