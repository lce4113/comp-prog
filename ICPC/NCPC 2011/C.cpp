#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    for (auto x : a) {
        int N = x.size();
        for (int i = 0; i < N - 1; i++) {
            if (x[i] == 'C' && x[i + 1] == 'D') {
                ans--;
                break;
            }
        }
        ans++;
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}