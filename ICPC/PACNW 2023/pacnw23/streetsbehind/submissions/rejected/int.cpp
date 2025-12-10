// @EXPECTED_RESULTS@: WRONG_ANSWER, TIME_LIMIT_EXCEEDED

#include <cstdint>
#include <iostream>
#include <vector>

int32_t solve(int32_t n, int32_t k, int32_t a, int32_t b) {
    int32_t d = b - a;
    int32_t steps = 0;
    while (k > 0) {
        int32_t inc = (d * n) / a;
        if (inc == 0)
            break;

        if (k <= inc || (d * (n + inc)) / a != inc) {
            steps += 1;
            inc = std::min(k, inc);
            n += inc;
            k -= inc;
        } else {
            int32_t s = (inc * a + a - d * n - 1) / (d * inc);
            s = std::min(s, (k + inc - 1) / inc);
            steps += s;
            int32_t take = std::min(k, inc * s);
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
        int32_t n, k, a, b;
        std::cin >> n >> k >> a >> b;
        std::cout << solve(n, k, a, b) << std::endl;
    }
    return 0;
}
