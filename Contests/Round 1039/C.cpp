// Codeforces Round 1039: Problem C

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
    int c = 1e9;
    for (int i = 0; i < n; i++) {
        if (a[i] > c) {
            cout << "NO\n";
            return;
        }
        c = min(a[i] * 2 - 1, c);
    }
    cout << "YES\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}