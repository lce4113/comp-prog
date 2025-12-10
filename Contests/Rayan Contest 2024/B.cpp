// Rayan Programming Contest 2024: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    string a;
    int n, m, k;
    cin >> n >> m >> k;
    cin >> a;
    int ans = 0, zs = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '0') zs++;
        if (a[i] == '1') zs = 0;
        if (zs == m) zs = 0, ans++, i += k - 1;
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}