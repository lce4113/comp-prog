// Codeforces Round 1061: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, q;
    cin >> n >> q;
    string a;
    cin >> a;
    bool b = 0;
    for (auto x : a)
        if (x == 'B') b = 1;
    if (!b) {
        while (q--) {
            int x;
            cin >> x;
            cout << x << '\n';
        }
        return;
    }
    while (q--) {
        int x;
        cin >> x;
        int ans = 0;
        for (; x; ans++) {
            if (a[ans % a.size()] == 'A') {
                x--;
            } else {
                x /= 2;
            }
        }
        cout << ans << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}