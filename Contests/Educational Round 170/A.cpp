#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), N = b.size();
    int ans = n + N;
    bool copy = false;
    for (int i = 0; i < min(n, N); i++) {
        if (a[i] == b[i])
            ans--, copy = true;
        else
            break;
    }
    if (copy) ans++;
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}