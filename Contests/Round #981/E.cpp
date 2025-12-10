#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        x--;
    }
    vector<bool> vis(n, false);
    int ans = 0;
    for (int x = 0; x < n; x++) {
        if (vis[x]) continue;
        int curr = x;
        int start = curr, i = 0;
        vis[curr] = true;
        do {
            // cout << curr << ' ' << a[curr] << ' ' << start << '\n';
            curr = a[curr], i++;
            vis[curr] = true;
        } while (curr != start && i <= MAXN);
        ans += (i - 1) / 2;
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}