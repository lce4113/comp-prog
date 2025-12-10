// Codeforces Round 1034: Problem E

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
    map<int, int> mp;
    for (auto x : a) mp[x]++;

    vector<int> ps(n + 2);
    for (int i = 0; i <= n; i++) {
        ps[mp[i]]++;
        ps[n - i + 1]--;
        if (mp[i] == 0) break;
    }
    vector<int> ans(n + 1);
    for (int i = 0, c = 0; i <= n; i++) ans[i] = c += ps[i];
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}