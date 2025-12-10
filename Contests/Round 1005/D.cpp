// Codeforces Round 1005
// Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXB = 32;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), xp(n + 1, 0);
    for (auto &x : a) cin >> x;
    for (int i = n - 1; i >= 0; i--) xp[i] = xp[i + 1] ^ a[i];

    vector<vector<int>> lst(n, vector<int>(MAXB, -1));
    vector<int> bs(MAXB, -1);
    for (int i = 0; i < n; i++) {
        int mb = log2(a[i]);
        for (int j = 0; j < MAXB; j++) lst[i][j] = bs[j];
        for (int j = 0; j <= mb; j++) bs[j] = i;
    }

    while (q--) {
        int v;
        cin >> v;
        int mb = log2(v), c = bs[mb];
        while (c >= 0 && (v ^ xp[c + 1]) >= a[c]) {
            mb = log2(v ^ xp[c]);
            c = lst[c][mb];
        }
        cout << n - 1 - c << ' ';
    }
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}