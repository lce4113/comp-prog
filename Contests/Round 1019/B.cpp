// Codeforces Round 1019: Problem B

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
    a = '0' + a;
    n++;
    int d = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1]) d++;
    }
    int ans = n;
    if (d >= 3)
        ans += d - 2;
    else if (d == 2)
        ans += d - 1;
    else
        ans += d;
    cout << ans - 1 << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
