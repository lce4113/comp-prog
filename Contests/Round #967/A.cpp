// Codeforces Round #967: Problem A

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> mp;
    for (auto x : a) mp[x]++;
    int mx = -1, mxv;
    for (auto x : mp) {
        if (x.s > mx) mx = x.s;
    }
    cout << n - mx << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}