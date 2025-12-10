// Spring 2025 Columbia University Local Contest
// Problem H

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

vector<vector<vector<int>>> a, pfs;
int n, m, k;

bool sub(int x1, int x2, int x3, int y1, int y2, int y3) {
    int ans = pfs[y1][y2][y3];
    ans -= pfs[x1][y2][y3] + pfs[y1][x2][y3] + pfs[y1][y2][x3];
    ans += pfs[x1][x2][y3] + pfs[x1][y2][x3] + pfs[y1][x2][x3];
    ans -= pfs[x1][x2][x3];
    // cout << x1 << ' ' << x2 << ' ' << x3 << '\n';
    // cout << y1 << ' ' << y2 << ' ' << y3 << '\n';
    // cout << ans << '\n';
    return ans == (y1 - x1) * (y2 - x2) * (y3 - x3);
}

bool ch(int M) {
    for (int x = 0; x <= n - M; x++) {
        for (int y = 0; y <= m - M; y++) {
            for (int z = 0; z <= k - M; z++) {
                if (sub(x, y, z, x + M, y + M, z + M)) return true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m >> k;
    a.assign(n, vector<vector<int>>(m, vector<int>(k)));
    pfs.assign(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1)));
    for (auto &x : a)
        for (auto &y : x)
            for (auto &z : y) cin >> z;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            for (int z = 1; z <= k; z++) {
                pfs[x][y][z] = a[x - 1][y - 1][z - 1];
                pfs[x][y][z] +=
                    pfs[x - 1][y][z] + pfs[x][y - 1][z] + pfs[x][y][z - 1];
                pfs[x][y][z] -= pfs[x - 1][y - 1][z] + pfs[x - 1][y][z - 1] +
                                pfs[x][y - 1][z - 1];
                pfs[x][y][z] += pfs[x - 1][y - 1][z - 1];
                // cout << pfs[x][y][z] << ' ';
            }
            // cout << '\n';
        }
        // cout << '\n';
    }
    int l = 0, r = max(max(n, m), k), M = (l + r) / 2;
    for (; r - l > 1; M = (l + r) / 2) {
        if (ch(M)) {
            l = M;
        } else {
            r = M;
        }
    }
    cout << l << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}