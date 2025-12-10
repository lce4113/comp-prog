#include <cstdint>
#include <iostream>
#include <vector>

int main() {
    int32_t n;
    std::cin >> n;
    std::vector<int32_t> a(n);
    for (auto& x : a) {
        std::cin >> x;
    }

    bool printed = false;
    for (auto d = 2; d <= n; ++d) {
        if (n % d) continue;

        bool valid = true;
        for (auto i = 0; i < n; ++i) {
            valid &= (i % d == 0 || a[i] > a[i - 1]);
        }

        if (valid) {
            std::cout << d << '\n';
        }
    }

    if (!printed) {
        std::cout << -1;
    }
    std::cout << '\n';

    return 0;
}
