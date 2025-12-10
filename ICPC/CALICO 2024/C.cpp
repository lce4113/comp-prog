// CALICO 2024: Problem C

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    int mxx = 0, mxy = 0, mnx = INT_MAX, mny = INT_MAX;
    vector<vector<char>> a(n, vector<char>(m));
    for (auto &x : a)
        for (auto &y : x) cin >> y;

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (a[i][k] == '#') {
                mxy = max(mxy, i);
                mxx = max(mxx, k);
                mny = min(mny, i);
                mnx = min(mnx, k);
            }
        }
    }
    int mxxs = 0, mxys = 0, mnxs = 0, mnys = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (a[i][k] == '#') {
                mxys += (i == mxy);
                mxxs += (k == mxx);
                mnys += (i == mny);
                mnxs += (k == mnx);
            }
        }
    }
    if (mxxs == 1 || mxys == 1 || mnxs == 1 || mnys == 1) {
        cout << "phineas\n";
    } else {
        cout << "ferb\n";
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}