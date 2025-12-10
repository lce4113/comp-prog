// Codeforces Round 987: Problem D

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

    vector<set<int>> adj(n);

    int mxi = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= a[mxi])
            mxi = i;
        else
            adj[mxi].insert(i);
    }

    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++) pos.push_back({a[i], i});
    sort(pos.begin(), pos.end());
    // for (auto x : pos) cout << x.f << ' ' << x.s << '\n';

    int mni = -1;
    for (int i = 0; i < n; i++) {
        if (pos[i].s >= mni)
            mni = pos[i].s;
        else
            adj[mni].insert(pos[i].s);
    }

    // for (int i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for (auto y : adj[i]) cout << y << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';

    set<pair<int, int>> rem;
    for (int i = 0; i < n; i++) rem.insert({a[i], i});

    vector<int> ans(n);
    while (rem.size()) {
        queue<int> Q;
        int val = rem.rbegin()->f;
        Q.push(rem.rbegin()->s);
        rem.erase(*rem.rbegin());
        // cout << val << '\n';
        while (Q.size()) {
            int curr = Q.front();
            Q.pop();
            // cout << curr << '\n';
            ans[curr] = val;
            for (auto x : adj[curr]) {
                if (!rem.count({a[x], x})) continue;
                Q.push(x);
                rem.erase({a[x], x});
            }
        }
    }
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}