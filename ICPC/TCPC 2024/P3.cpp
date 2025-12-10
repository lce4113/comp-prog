// Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define f first
#define s second

const int MOD = 1e9 + 7;

int dex[4] = {-1, 1, 0, 0};
int dey[4] = {0, 0, -1, 1};
int dcx[4] = {-1, 1, -1, 1};
int dcy[4] = {-1, -1, 1, 1};

int binexp(int a, int b = MOD - 2) {
    int ans = 1;
    for (; b > 0; a = (a * a) % MOD) {
        if (b % 2) ans = (ans * a) % MOD;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n, m, d0, d1, d2;
    cin >> n >> m >> d0 >> d1 >> d2;
    vector<vector<char>> a(n, vector<char>(m));
    for (auto &x : a) {
        for (auto &y : x) cin >> y;
    }

    vector<vector<vector<int>>> qq(n,
                                   vector<vector<int>>(m, vector<int>(3, 0))),
        qv(n, vector<vector<int>>(m, vector<int>(3, 0)));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (a[i][k] != 'V') continue;
            qv[i][k][0]++;
            for (int l = 0; l < 4; l++) {
                int nx = i + dex[l], ny = k + dey[l];
                if (nx >= n || nx < 0) continue;
                if (ny >= m || ny < 0) continue;
                qv[nx][ny][1]++;
            }
            for (int l = 0; l < 4; l++) {
                int nx = i + dcx[l], ny = k + dcy[l];
                if (nx >= n || nx < 0) continue;
                if (ny >= m || ny < 0) continue;
                qv[nx][ny][2]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (a[i][k] != '?') continue;
            qq[i][k][0]++;
            for (int l = 0; l < 4; l++) {
                int nx = i + dex[l], ny = k + dey[l];
                if (nx >= n || nx < 0) continue;
                if (ny >= m || ny < 0) continue;
                qq[nx][ny][1]++;
            }
            for (int l = 0; l < 4; l++) {
                int nx = i + dcx[l], ny = k + dcy[l];
                if (nx >= n || nx < 0) continue;
                if (ny >= m || ny < 0) continue;
                qq[nx][ny][2]++;
            }
        }
    }

    // for (auto &x : qv) {
    //     for (auto &y : x) cout << y[0] << ',' << y[1] << ',' << y[2] << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';
    // for (auto &x : qq) {
    //     for (auto &y : x) cout << y[0] << ',' << y[1] << ',' << y[2] << ' ';
    //     cout << '\n';
    // }

    int ans = 0;
    int d[3] = {d0, d1, d2};
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            int ev = 0, prob = 1, v = 0;
            for (int l = 0; l < 3; l++) {
                // cout << qv[i][k][l] << '/' << qq[i][k][l] << ", ";
                int curr = d[l];
                curr *= prob, curr %= MOD;
                if (qv[i][k][l]) v = 1;
                if (v) {
                    ev += curr, ev %= MOD;
                    prob *= binexp(binexp(2), qq[i][k][l]), prob %= MOD;
                    break;
                }
                curr *= 1 - binexp(binexp(2), qq[i][k][l]) + MOD, curr %= MOD;
                ev += curr, ev %= MOD;
                prob *= binexp(binexp(2), qq[i][k][l]), prob %= MOD;
            }
            // cout << ev << '\n';
            ans += ev, ans %= MOD;
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}