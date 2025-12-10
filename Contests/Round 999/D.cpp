// Codeforces Round 999: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    multiset<int> sa;
    for (auto x : a) sa.insert(x);
    multiset<int> sb;
    for (auto x : b) sb.insert(x);

    while (sb.size() && sb.size() < sa.size()) {
        int x = *sb.rbegin();
        // cout << x << '\n';
        sb.erase(--sb.end());
        // sb.erase(sb.lower_bound(x));
        if (sa.count(x)) {
            sa.erase(sa.lower_bound(x));
        } else {
            sb.insert(x / 2);
            sb.insert(x - x / 2);
        }
    }

    if (sa != sb) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}