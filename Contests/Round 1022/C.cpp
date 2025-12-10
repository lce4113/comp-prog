// Codeforces Round 1022: Problem C

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
    vector<int> b(1, a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) b.push_back(a[i]);
    }
    // for (auto x : b) cout << x << ' ';
    // cout << '\n';
    int N = b.size();
    int ans = 1;
    for (int i = 2; i < N; i++) {
        ans += (b[i - 1] < b[i - 2] && b[i] > b[i - 1]);
    }
    // ans += (n >= 2 && a[0] > a[1]);
    // ans += (n >= 2 && a[n - 1] > a[n - 2]);
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}