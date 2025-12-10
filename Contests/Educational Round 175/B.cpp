// Codeforces Educational Round 175: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, v, k;
    cin >> n >> v >> k;
    string a;
    cin >> a;
    int c = 0, ans = 0, mz = -1;
    for (int i = 0; i < n; i++) {
        c += (a[i] == 'R');
        c -= (a[i] == 'L');
        k--;
        if (c + v == 0) {
            ans++;
            break;
        }
    }
    c = 0;
    for (int i = 0; i < n; i++) {
        c += (a[i] == 'R');
        c -= (a[i] == 'L');
        if (c == 0 && mz == -1) mz = i + 1;
    }
    if (ans == 0) {
        cout << "0\n";
        return;
    }
    // cout << k << ' ' << mz << '\n';
    cout << ans + (mz == -1 ? 0 : k / mz) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}