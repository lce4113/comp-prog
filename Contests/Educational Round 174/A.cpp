// Codeforces Educational Round 174
// Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n - 2);
    for (auto &x : a) cin >> x;
    for (int i = 1; i < n - 1; i++) {
        // cout << a[i] << ' ' << a[i - 1] << ' ' << a[i + 1] << '\n';
        if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) {
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