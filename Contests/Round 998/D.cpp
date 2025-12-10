// Codeforces Round 998: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    if (a[0] > a[1]) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1] && (i == 1 || a[i - 2] == 0)) {
            a[i] -= a[i - 1], a[i - 1] = 0;
        }
    }

    // for (auto x : a) cout << x << ' ';
    // cout << '\n';

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            cout << "NO\n";
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