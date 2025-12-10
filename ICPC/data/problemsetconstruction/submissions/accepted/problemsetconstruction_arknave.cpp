#include <cstdint>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using DP_t = vector<vector<double>>;
using Problem = tuple<int32_t, int32_t, double>;

int main() {
    int32_t n, k, t;
    cin >> n >> k >> t;

    auto advance = [=](const DP_t& dp, int32_t s, int32_t idx, double p) -> DP_t {
        DP_t res(k, vector<double>(t + 1, 0.0));

        int32_t rem_probs = n - idx;
        for (int i = 0; i < k; ++i) {
            double prob_choose = static_cast<double>(k - i)/rem_probs;

            for (int j = 0; j <= t; ++j) {
                if (i + 1 < k) {
                    res[i + 1][min(t, j + s)] += dp[i][j] * prob_choose * p;
                    res[i + 1][j] += dp[i][j] * prob_choose * (1.0 - p);
                }

                res[i][j] += dp[i][j] * (1.0 - prob_choose);
            }
        }

        return res;
    };

    vector<Problem> problems;
    for (int32_t i = 0; i < n; ++i) {
        double p;
        int32_t s;
        cin >> p >> s;

        problems.emplace_back(s, i, p);
    }

    sort(problems.begin(), problems.end());

    DP_t prob(k, vector<double>(t + 1, 0.0));
    prob[0][0] = 1.0;

    vector<double> ans(n, 0.0);
    int32_t loop_iter = 0;
    for (auto [s, idx, p] : problems) {
        {
            double& res = ans[idx];

            for (int i = 0; i < k; ++i) {
                for (int j = 0; j + s <= t; ++j) {
                    res += static_cast<double>(k - i) / (n - loop_iter) * prob[i][j];
                }
            }

            res *= p;
        }

        prob = advance(prob, s, loop_iter, p);
        ++loop_iter;
    }

    cout << setprecision(20);
    for (auto res : ans) {
        // Scale by n/k to ensure this problem gets used.
        cout << res * n / k << '\n';
    }
}
