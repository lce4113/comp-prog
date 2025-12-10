#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct Solver {
    constexpr static int INF = 1e9 + 7;
    int n;
    vector<int> a;
    vector<vector<int>> memo;

    // number of days until u raises their hand, assuming they can only see
    // people in mask
    int days(int mask, int u) {
        if (memo[mask][u] != -1)
            return memo[mask][u];

        assert((mask & (1 << u)) > 0);
        vector<int> triple_part(n);
        for (int i = 0; i < n; ++i) {
            if (i == u || (mask & (1 << i)) == 0) continue;
            for (int j = i + 1; j < n; ++j) {
                if (j == u || (mask & (1 << j)) == 0) continue;
                for (int k = j + 1; k < n; ++k) {
                    if (k == u || (mask & (1 << k)) == 0) continue;

                    if (a[i] ^ a[j] ^ a[k] == 0) {
                        triple_part[i] = triple_part[j] = triple_part[k] = true;
                    }
                }
            }
        }

        if (!any_of(triple_part.begin(), triple_part.end(), [](int x) { return x; })) {
            return memo[mask][u] = 0;
        }

        int ans = INF;
        for (int v = 0; v < n; ++v) {
            // only get in the heads of others if they're part of a triple.
            if (v == u || !triple_part[v] || (mask & (1 << v)) == 0) continue;
            ans = min(ans, days(mask ^ (1 << u), v) + 1);
        }

        return memo[mask][u] = ans;
    }

    void solve() {
        cin >> n;
        a.resize(n);
        for (auto& x : a)
            cin >> x;

        memo.assign(1 << n, vector<int>(n, -1));

        int ans = INF;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, days((1 << n) - 1, i));
        }

        assert(ans < INF);
        ans = max(ans, 1);

        cout << ans << '\n';
    }
};

int main() {
    Solver solver;
    solver.solve();

    return 0;
}
