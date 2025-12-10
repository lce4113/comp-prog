// Codeforces Educational Round 167
// Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size(), ans = m;
    for (int s = 0; s < m; s++) {
        int c = m;
        for (int i = 0, j = s; i < n && j < m;) {
            if (a[i] == b[j]) j++, c--;
            i++;
        }
        ans = min(ans, c);
    }
    ans += n;
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}