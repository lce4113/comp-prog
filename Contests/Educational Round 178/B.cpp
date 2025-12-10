// Codeforces Educational Round 178: Problem B

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
    vector<int> mx(1, 0);
    for (int i = 0; i < n; i++) {
        mx.push_back(max(mx.back(), a[i]));
    }
    // set<int> st;
    int sm = 0;
    for (int i = n - 1; i >= 0; i--) {
        int ans = sm + mx[i + 1];
        sm += a[i];
        cout << ans << ' ';
    }
    cout << '\n';
    // for (auto x : mx) cout << x << ' ';
    // cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}