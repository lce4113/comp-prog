// Codeforces Round 1024: Problem B

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
    int g = 0, l = 0;
    for (int i = 1; i < n; i++) {
        g += abs(a[i]) > abs(a[0]);
        l += abs(a[i]) < abs(a[0]);
    }
    if (l > n / 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}