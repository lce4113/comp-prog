// Codeforces Round 1008: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    long double sm = 0;
    for (auto x : a) sm += x;
    sm /= n;
    cout << (sm == k ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}