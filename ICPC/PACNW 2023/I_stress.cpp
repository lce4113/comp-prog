// ICPC Pacific Northwest 2023: Problem I

#include <bits/stdc++.h>
using namespace std;

int binexp(int a, int b) {
    int res = 1;
    for (; b; a *= a, b /= 2)
        if (b % 2) res *= a;
    return res;
}

vector<int> a;

int ch() {
    int n = a.size();
    constexpr int32_t INF = 1e9;
    std::vector<std::vector<int32_t>> dp(n + 1,
                                         std::vector<int32_t>(n + 1, INF));

    std::fill(dp[1].begin(), dp[1].end(), 0);
    for (int32_t len = 2; len <= n; ++len) {
        for (int32_t i = 0; i + len <= n; ++i) {
            for (int32_t j = i + 1; j < i + len; ++j) {
                dp[len][i] =
                    std::min(dp[len][i], (a[i] != a[j]) + dp[j - i][i] +
                                             dp[len - (j - i)][j]);
            }
        }
    }

    return dp[n][0];
}

int solve() {
    cin.tie(0)->sync_with_stdio(0);

    int n = a.size();

    int dp[n + 1][n + 1];
    for (auto &x : dp[0]) x = 0;
    for (auto &x : dp[1]) x = 1;
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int c = 0, cl = l;
            dp[len][l] = 1e9;
            for (int i = l; i < l + len; i++) {
                if (a[i] == a[cl]) {
                    c += i == cl ? 0 : dp[i - cl - 1][cl + 1];
                    while (i < l + len && a[i] == a[cl]) i++;
                    cl = i - 1;
                    dp[len][l] = min(dp[len][l], 1 + c + dp[l + len - i][i]);
                }
            }
        }
    }

    return dp[n][0] - 1;
}

int32_t main() {
    int N = 6;
    for (int i = 0; i < binexp(3, N); i++) {
        a.clear(), a.push_back(0);
        for (int x = i, j = 0; j < N; x /= 3, j++) a.push_back(x % 3);
        int a1 = solve(), a2 = ch();
        cout << a1 << ' ' << a2 << '\n';
        for (auto x : a) cout << x << ' ';
        cout << '\n';
        if (a1 != a2) {
            cout << "ohno\n";
            return 0;
        }
    }
}
