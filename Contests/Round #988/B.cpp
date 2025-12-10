// Codeforces Round #988: Problem B

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
    set<int> st;
    for (auto &x : a) st.insert(x);
    for (int i = 0; i < n; i++) {
        if ((n - 2) % a[i] == 0 && st.count((n - 2) / a[i]) &&
            (a[i] != (n - 2) / a[i] || mp[a[i]] >= 2)) {
            cout << a[i] << ' ' << (n - 2) / a[i] << '\n';
            return;
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}