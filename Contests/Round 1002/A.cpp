// Codeforces Round 1002: Problem A
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
    vector<int> b(n);
    for (auto &x : b) cin >> x;
    set<int> as, bs;
    for (auto x : a) as.insert(x);
    for (auto x : b) bs.insert(x);
    if (as.size() + bs.size() <= 3) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}