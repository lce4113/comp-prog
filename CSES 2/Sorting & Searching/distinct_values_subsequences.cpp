// CSES Sorting & Searching: Distinct Values Subsequences

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> mp;
    for (auto x : a) mp[x]++;
    int ans = 1;
    for (auto x : mp) {
        ans *= x.s + 1;
        ans %= MOD;
    }
    ans = ans - 1 + MOD;
    ans %= MOD;
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}