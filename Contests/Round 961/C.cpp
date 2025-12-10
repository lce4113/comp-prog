// Codeforces Round 961: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0, c = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1] && a[i + 1] == 1) {
            cout << "-1\n";
            return;
        }
        int x = a[i], y = a[i + 1];
        while (y < x) y *= y, c++;
        x = a[i], y = a[i + 1];
        while (x < y && c > 0) {
            x *= x, c--;
            if (x > y) c++;
        }
        // cout << c << ' ';
        ans += c;
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}