#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    string a;
    cin >> a;
    int n = a.size();
    map<char, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]].push_back(i);
    }
    set<pair<int, int>> itv;
    for (int i = 0; i < n / 3; i++) {
        int lo = 1e9, hi = -1;
        for (auto x : {'A', 'B', 'C'}) {
            lo = min(lo, mp[x][i]), hi = max(hi, mp[x][i]);
        }
        itv.insert({lo, hi});
    }

    // for (auto x : itv) {
    //     cout << x.f << ' ' << x.s << '\n';
    // }

    int ans = 0;
    while (itv.size()) {
        ans++;
        int end = -1;
        while (itv.size() && end < itv.rbegin()->f) {
            auto x = itv.lower_bound({end + 1, -1});
            end = x->s;
            itv.erase(x);
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}