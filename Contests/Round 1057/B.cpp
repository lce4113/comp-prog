// Codeforces Round 1057: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    vector<int> a(3);
    for (auto &x : a) cin >> x;
    for (int i = 0; i <= 35; i++) {
        int c = 0;
        for (auto x : a) {
            if (x & (1 << i)) c++;
        }
        if (c == 2) {
            cout << "NO\n";
            // cout << i << '\n';
            return;
        }
    }
    cout << "YES\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}