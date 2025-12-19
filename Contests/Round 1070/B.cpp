// Codeforces Round 1070: Problem B

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
    for (int i = 0; i < n; i++) a += a[i];
    int ans = 0;
    for (int i = 0; i < 2 * n;) {
        int st = i;
        while (i < 2 * n && a[i] == a[st]) i++;
        if (a[st] == '0') ans = max(ans, i - st);
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}