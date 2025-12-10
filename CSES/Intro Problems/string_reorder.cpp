// CSES Intro Problems: String Reorder

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    string a;
    cin >> a;
    int n = a.size();
    vector<int> mp(26, 0);
    set<pair<int, int>> cs, rcs;
    for (auto x : a) mp[x - 'A']++;
    for (int i = 0; i < 26; i++) {
        if (!mp[i]) continue;
        cs.insert({mp[i], i});
        rcs.insert({i, mp[i]});
    }
    // for (auto x : mp) cout << x << ' ';
    // cout << '\n';
    // cout << '\n';
    // for (auto x : cs) cout << x.f << ' ' << x.s << '\n';
    // cout << '\n';
    // for (auto x : rcs) cout << x.f << ' ' << x.s << '\n';
    if (cs.rbegin()->f > (n + 1) / 2) {
        cout << "-1\n";
        return;
    }
    string ans;
    for (int i = 0; i < n; i++) {
        int nxt;
        if (cs.rbegin()->f > (n - i) / 2) {
            nxt = cs.rbegin()->s;
        } else if (ans.size() && ans.back() - 'A' == rcs.begin()->f) {
            nxt = (++rcs.begin())->f;
        } else {
            nxt = rcs.begin()->f;
        }
        ans += 'A' + nxt;
        cs.erase({mp[nxt], nxt});
        rcs.erase({nxt, mp[nxt]});
        mp[nxt]--;
        if (mp[nxt]) {
            rcs.insert({nxt, mp[nxt]});
            cs.insert({mp[nxt], nxt});
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
