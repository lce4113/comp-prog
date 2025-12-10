// Codeforces Round 998: Problem C

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
    multiset<int> sa;
    for (auto x : a) sa.insert(x);

    int ans = 0;
    while (sa.size()) {
        int goal = k - *sa.begin();
        auto x = --sa.upper_bound(goal);
        if (*x == goal && x != sa.begin()) {
            ans++;
            sa.erase(--sa.upper_bound(goal));
        }
        sa.erase(sa.begin());
    }

    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}