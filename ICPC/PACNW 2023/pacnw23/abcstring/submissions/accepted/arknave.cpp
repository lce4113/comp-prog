#include <array>
#include <cstdint>
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int32_t ans = 0;
    std::array<int32_t, 7> freq{};
    for (char c : s) {
        int8_t x = 1 << (c - 'A');
        for (auto j = 6; j >= 0; --j) {
            if ((j & x) > 0 || (j > 0 && freq[j] == 0)) continue;
            if (freq[j] == 0) {
                ++freq[j];
                ++ans;
            }
            --freq[j];
            auto goal = x | j;
            if (goal == 7) goal = 0;
            ++freq[goal];
            break;
        }
    }

    std::cout << ans << '\n';
}
