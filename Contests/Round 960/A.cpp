// Codeforces Round 960: Problem A
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
    vector<int> cnt;
    for (auto x : mp) cnt.push_back(x.s);
    reverse(cnt.begin(), cnt.end());

    int c = 0;
    for (auto x : cnt) {
        c += x;
        if (c % 2) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";

    // for (auto x : cnt) cout << x << ' ';
    // cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}