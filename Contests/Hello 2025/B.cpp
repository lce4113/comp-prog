// Codeforces Hello 2025: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), cs;
    for (auto &x : a) cin >> x;
    map<int, int> mp;
    for (auto x : a) mp[x]++;
    int ans = 0;
    for (auto x : mp) ans++, cs.push_back(x.s);
    sort(cs.begin(), cs.end());
    int i = 0;
    while (k >= cs[i] && i < cs.size() - 1) k -= cs[i++], ans--;
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}