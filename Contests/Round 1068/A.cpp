// Codeforces Round 1068: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    string a, b(n, '0');
    cin >> a;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            for (int j = i; j <= i + k && j < n; j++) {
                b[j] = '1';
            }
        }
    }
    int ans = 0;
    for (auto x : b) ans += x == '0';
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}