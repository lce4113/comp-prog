// Codeforces Educational Round 172: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    int diff = 0;
    vector<int> ds;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] == '1')
            diff++;
        else
            diff--;
        ds.push_back(diff);
    }
    sort(ds.rbegin(), ds.rend());
    // for (auto x : ds) cout << x << ' ';
    // cout << '\n';
    int ans = 1, sm = 0, i = 0;
    while (i < n && sm < k) sm += ds[i++], ans++;
    if (i == n) {
        cout << "-1\n";
        return;
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}