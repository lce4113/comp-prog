// Educational Codeforces Round 185: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> q(n), r(n);
    for (auto &x : q) cin >> x;
    for (auto &x : r) cin >> x;
    sort(r.begin(), r.end());
    multiset<int> Q(q.begin(), q.end());
    int ans = 0;
    for (auto v : r) {
        auto p = Q.upper_bound((k - v) / (v + 1));
        if (p == Q.begin()) continue;
        p--;
        Q.erase(Q.find(*p));
        ans++;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}