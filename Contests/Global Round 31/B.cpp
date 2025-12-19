// Codeforces Global Round 31: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    string ans;
    for (int i = 0; i < n; i++) {
        if (a[i] + ans <= ans + a[i])
            ans = a[i] + ans;
        else
            ans += a[i];
    }
    cout << ans << '\n';
    // reverse(ans.begin(), ans.end());
    // ans.insert(ans.end(), res.begin(), res.end());
    // for (auto x : ans) cout << a[x];
    // cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}