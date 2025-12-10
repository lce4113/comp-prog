#include <cstdint>
#include <iostream>
#include <vector>

int64_t solve(int64_t n, int64_t k, int64_t a, int64_t b) {
    int64_t d = b - a;
    int64_t steps = 0;
    while (k > 0) {
        int64_t inc = (d * n) / a;
        if (inc == 0)
            break;

        if (k <= inc || (d * (n + inc)) / a != inc) {
            steps += 1;
            inc = std::min(k, inc);
            n += inc;
            k -= inc;
        } else {
            int64_t s = (inc * a + a - d * n - 1) / (d * inc);
            s = std::min(s, (k + inc - 1) / inc);
            steps += s;
            int64_t take = std::min(k, inc * s);
            n += take;
            k -= take;
        }
    }

    if (k) {
        return -1;
    } else {
        return steps;
    }
}

int main() {
    int32_t t;
    std::cin >> t;
    for (int32_t i = 0; i < t; ++i) {
        int64_t n, k, a, b;
        std::cin >> n >> k >> a >> b;
        std::cout << solve(n, k, a, b) << std::endl;
    }
    return 0;
}
