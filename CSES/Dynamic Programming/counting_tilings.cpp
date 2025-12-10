// CSES Dynamic Programming: Counting Tilings

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;

int n, m;

vector<int> dig(int x) {
    vector<int> c;
    for (int i = 0; i < n; i++, x /= 2) c.push_back(x % 2);
    return c;
}

bool check(int x) {
    vector<int> c = dig(x);
    if (c[0] == 0) return 0;
    if (c.back() == 1) return 0;
    for (int j = 0; j < n - 1; j++) {
        if (c[j] == 1 && c[j + 1] != 0) return 0;
        if (c[j] != 1 && c[j + 1] == 0) return 0;
    }
    return 1;
}

bool check_connect(int x, int y) {
    vector<int> c1 = dig(x), c2 = dig(y);
    // for (auto x : c1) cout << x << ' ';
    // cout << "/ ";
    // for (auto x : c2) cout << x << ' ';
    // cout << '\n';
    vector<int> ps(1, 1);
    for (int i = 0; i < n; i++) {
        if (c1[i] == 0 && c2[i] == 0) return 0;
        if (c1[i] == 0 || c2[i] == 0) ps.push_back(i % 2);
    }
    ps.push_back(n % 2);
    int N = ps.size();
    for (int i = 0; i < N - 1; i++) {
        if (ps[i + 1] == ps[i]) return 0;
    }
    return 1;
}

bool check_start(int x) { return check_connect((1 << n) - 1, x); }

void solve() {
    cin >> n >> m;
    // 0: ^, 1: >/</v
    vector<int> dp(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        if (check_start(i)) dp[i] = 1;
    }
    vector<vector<int>> connect(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            if (check_connect(i, j)) connect[i].push_back(j);
        }
    }
    m--;
    while (m--) {
        vector<int> ndp(1 << n);
        for (int i = 0; i < (1 << n); i++) {
            for (auto j : connect[i]) {
                // cout << i << ' ' << j << '\n';
                ndp[j] += dp[i], ndp[j] %= MOD;
            }
        }
        dp = ndp;
    }
    cout << dp.back() << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}