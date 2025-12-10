// Codeforces Round 1014: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int o1 = 0, o2 = 0;
    for (int i = 0; i < n; i += 2) o1 += a[i] == '1', o2 += b[i] == '1';
    for (int i = 1; i < n; i += 2) o2 += a[i] == '1', o1 += b[i] == '1';
    cout << ((o1 <= (n / 2) && o2 <= n - n / 2) ? "YES\n" : "NO\n");
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}