// Codeforces Round 1015: Problem B

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
    sort(a.begin(), a.end());

    int g = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] % a[0] == 0) {
            if (g == 0) g = a[i] / a[0];
            g = gcd(g, a[i] / a[0]);
        }
    }
    cout << (g == 1 ? "YES\n" : "NO\n");
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) solve();
}