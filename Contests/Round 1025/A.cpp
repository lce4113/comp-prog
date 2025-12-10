// Codeforces Round 1025: Problem A

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
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 0 && a[i + 1] == 0) {
            cout << "YES\n";
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
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