// Codeforces Round 1001: Problem B

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
    // if (a[0] < n * 2 - 1) {
    //     cout << "NO\n";
    //     return;
    // }
    // if (a.back() < n * 2 - 1) {
    //     cout << "NO\n";
    //     return;
    // }
    for (int i = 0; i < n; i++) {
        if (a[i] < max(i, n - 1 - i) * 2 + 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}