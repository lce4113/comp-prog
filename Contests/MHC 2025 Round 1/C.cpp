// Meta Hacker Cup 2025 Round 1: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int B = 30;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> pre;
    int c = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        c ^= a[i];
        // calc
        // pre[c];
        // set
        // pre[c] = x;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}