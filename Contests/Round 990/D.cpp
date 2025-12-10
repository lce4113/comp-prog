// Codeforces Round 990: Problem D

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

    vector<pair<int, int>> ps;
    for (int i = 0; i < n; i++) ps.push_back({a[i], i});
    sort(ps.begin(), ps.end());
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[a[i]].push_back(i);

    int mx = 1e9 + 10;
    for (int i = 1; i < n; i++) {
        if (ps[i].s < ps[i - 1].s) {
            mx = ps[i].f + 1;
            break;
        }
    }
    // cout << mx << '\n';

    vector<int> ans;
    int cmx = -1;
    for (auto x : mp) {
        for (auto i : x.s) {
            // cout << x.f << ' ' << i << '\n';
            if (i < cmx || x.f > mx) {
                ans.push_back(x.f + 1);
            } else {
                ans.push_back(x.f);
            }
        }
        cmx = max(cmx, x.s.back());
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > mx) continue;
        if (a[i] > cmx) continue;
        cmx = max(cmx, a[i]);
    }

    sort(ans.begin(), ans.end());
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}