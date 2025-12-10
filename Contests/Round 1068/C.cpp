// Codeforces Round 1068: Problem C

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
    vector<int> ans;
    set<int> c(a.begin(), a.end()), rem;
    while (c.size()) {
        auto d = *c.begin();
        ans.push_back(d);
        // cout << "d: " << d << '\n';
        for (int i = d; i <= k; i += d) {
            if (!c.count(i) && !rem.count(i)) {
                cout << "-1\n";
                return;
            }
            c.erase(i);
            rem.insert(i);
        }
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}