// Codeforces Educational Round 168: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] == 'x' && a[i + 1] == 'x' && a[i] == '.' &&
            b[i - 1] == '.' && b[i] == '.' && b[i + 1] == '.')
            ans++;
        if (b[i - 1] == 'x' && b[i + 1] == 'x' && b[i] == '.' &&
            a[i - 1] == '.' && a[i] == '.' && a[i + 1] == '.')
            ans++;
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}