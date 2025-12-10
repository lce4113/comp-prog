// Codeforces Round 994: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<char> a(n);
    for (auto &x : a) cin >> x;
    int lp = n, rs = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 's') rs = i;
        if (a[i] == 'p') lp = min(lp, i);
    }
    // cout << rs << ' ' << lp << '\n';
    if (min(n - rs, lp + 1) <= lp - rs + 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}