

// Codeforces Educational Round 176: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXN = 1e6;

vector<int> trs(MAXN + 1);

using li = long long;

const int B = 60;
const li INF = 1e18;

array<array<li, B>, B> dp;

int ch(int x, int y) {
    // cin >> x >> y;
    li ans = INF;
    for (int i = 0; i < B; ++i) {
        for (int j = 0; j < B; ++j) {
            if ((x >> i) == (y >> j)) ans = min(ans, dp[i][j]);
        }
    }
    return ans;
}

int solve(int x, int y) {
    vector<int> bx, by;
    int c1 = 0, c2 = 0;
    while (x) {
        bx.push_back(x % 2);
        x /= 2, c1++;
    }
    while (y) {
        by.push_back(y % 2);
        y /= 2, c2++;
    }

    // for (auto x : bx) cout << x << ' ';
    // cout << '\n';
    // for (auto x : by) cout << x << ' ';
    // cout << '\n';

    int sm = 0;
    for (int i = bx.size() - 1, j = by.size() - 1; i >= 0 && j >= 0;
         i--, j--, sm++) {
        if (bx[i] != by[j]) break;
    }

    // cout << tot << ' ' << sm << '\n';

    c1 -= sm, c2 -= sm;
    int sq = lower_bound(trs.begin(), trs.end(), c1 + c2) - trs.begin();
    int tr = sq * (sq + 1) / 2;
    if (c1 > c2) swap(c1, c2);
    if (tr - c1 - c2 == 1 && (c1 == 1)) {
        if (c1 + c2 >= (int)bx.size() + (int)by.size()) {
            c2++;
        } else {
            c1++, c2++;
        }
        sq = lower_bound(trs.begin(), trs.end(), c1 + c2) - trs.begin();
        tr = sq * (sq + 1) / 2;
    }
    if (tr - c1 - c2 == 2 && (c1 == 2)) {
        if (c1 + c2 >= (int)bx.size() + (int)by.size()) {
            c2++;
        } else {
            c1++, c2++;
        }
        sq = lower_bound(trs.begin(), trs.end(), c1 + c2) - trs.begin();
        tr = sq * (sq + 1) / 2;
    }
    int ans = 0;
    for (int i = 1; i <= sq; i++) {
        if (i == tr - c1 - c2) continue;
        // cout << i << ' ';
        ans += (1ll << i);
    }

    // cout << ans << '\n';
    return ans;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < B; ++i) {
        for (int j = 0; j < B; ++j) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int x = 0; x < B; ++x) {
        for (int i = B - 1; i >= 0; --i) {
            for (int j = B - 1; j >= 0; --j) {
                if (dp[i][j] == INF) continue;
                if (i + x < B)
                    dp[i + x][j] = min(dp[i + x][j], dp[i][j] + (1LL << x));
                if (j + x < B)
                    dp[i][j + x] = min(dp[i][j + x], dp[i][j] + (1LL << x));
            }
        }
    }

    for (int i = 0; i < MAXN; i++) {
        trs[i] = i * (i + 1) / 2;
    }
    // for (int i = 0; i < 10; i++) {
    //     cout << i << ' ' << tr[i] << '\n';
    // }

    for (int x = 0; x <= 100; x++) {
        for (int y = x; y <= 100; y++) {
            int a1 = ch(x, y), a2 = solve(x, y);
            cout << "xy: " << x << ' ' << y << '\n';
            cout << a1 << ' ' << a2 << '\n';
            if (a1 != a2) {
                cout << "ohno\n";
                return 0;
            }
        }
    }

    // int t = 1;
    // cin >> t;
    // while (t--) solve();
}