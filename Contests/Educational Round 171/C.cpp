#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += i;
    int ones = 0;
    for (int i = n - 1; i >= 0; i--) {
        // cout << i << ' ' << ones << '\n';
        if (a[i] == '1' && ones + 1 <= i) {
            ones++;
            ans -= i + 1;
        } else {
            ones--;
            ones = max(ones, 0LL);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}