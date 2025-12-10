// CSES Intro Problems: Chessboard and Queens

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n = 8;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++) p[i] = i;
    int ans = 0;
    do {
        bool ok = 1;
        set<int> d1, d2;
        for (int i = 0; i < n; i++) {
            if (d1.count(i + p[i]) || d2.count(i - p[i]) || a[i][p[i]] == '*') {
                ok = 0;
                break;
            }
            d1.insert(i + p[i]);
            d2.insert(i - p[i]);
        }
        if (!ok) continue;
        ans++;
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
