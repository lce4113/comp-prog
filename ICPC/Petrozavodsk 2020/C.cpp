// Petrozavodsk 2020: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(2 * n);
    for (int i = n; i < 2 * n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) a[i + n] -= i * d;
    int ans = 0;
    priority_queue<int> Q;
    for (int i = 0; i < 2 * n; i++) {
        Q.push(a[i]), Q.push(a[i]);
        ans += Q.top() - a[i];
        Q.pop();
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) solve();
}