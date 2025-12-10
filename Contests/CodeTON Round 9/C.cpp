// CodeTON Round 9: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 1; i <= min(b, a); i++) {
        if (i == a) continue;
        // cout << i << ' ' << a << ' ' << (a ^ i) << '\n';
        if ((a ^ i) % i == 0 || (a ^ i) % a == 0) {
            ans++;
            // cout << i << ' ';
        }
    }
    int l = 0, r = b / a + 3, m = (l + r) / 2;
    for (; r - l > 1; m = (l + r) / 2) {
        if ((a ^ a * m) <= b) {
            l = m;
        } else {
            r = m;
        }
    }
    ans += l;
    // if (l >= 1) ans--;
    if ((a * (l - 1) ^ a) > b) ans--;
    if ((a * (l + 2) ^ a) <= b) ans++;
    // cout << l << '\n';
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}