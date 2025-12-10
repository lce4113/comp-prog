// CSES Mathematics: Triangle Number Sums

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e12;
vector<int> tri(1, 0);
int timer = 0;

int get(int n) {
    if (n == 0) return 0;
    n -= *(--upper_bound(tri.begin(), tri.end(), n));
    return 1 + get(n);
}

void solve() {
    int n;
    cin >> n;
    for (auto c : tri) {
        if (c == n) {
            cout << "1\n";
            return;
        }
    }
    for (int i = 0, j = tri.size() - 1; i <= j;) {
        if (tri[i] + tri[j] < n) {
            i++;
        } else if (tri[i] + tri[j] > n) {
            j--;
        } else {
            cout << "2\n";
            return;
        }
    }
    cout << "3\n";
}

int32_t main() {
    for (int i = 1; tri.back() + i <= MAXN; i++) tri.push_back(tri.back() + i);

    // const int MAX2 = 1e5;
    // vector<int> dp(MAX2, 1e18);
    // dp[0] = 0;
    // for (int i = 0; i < MAX2; i++) {
    //     for (int j = 1; i - tri[j] >= 0; j++) {
    //         dp[i] = min(dp[i - tri[j]] + 1, dp[i]);
    //     }
    // }

    // for (int i = 1e4; i <= 1e4 + 100; i++) {
    //     cout << i << ' ' << dp[i] << '\n';
    // }
    // for (int i = 0; i < MAX2; i++) {
    //     if (dp[i] > 3) {
    //         cout << i << '\n';
    //         return 0;
    //     }
    //     // if (get(i) != dp[i]) {
    //     //     cout << i << ' ' << get(i) << ' ' << dp[i] << '\n';
    //     //     cout << "ohno\n";
    //     // }
    // }

    int t = 1;
    cin >> t;
    while (t--) solve();
}