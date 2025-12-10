// Codeforces Pinely Round 5: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int r, X, d, n;
    cin >> r >> X >> d >> n;
    string a;
    cin >> a;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1' || (a[i] == '2' && r < X)) ans++, r -= d;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}