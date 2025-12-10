// Codeforces Round 984: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    vector<int> a;
    for (auto x : mp) {
        a.push_back(x.s);
    }
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0; i < a.size() && i < n; i++) {
        ans += a[i];
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}