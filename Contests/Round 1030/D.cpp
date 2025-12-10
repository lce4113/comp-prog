// Codeforces Round 1030: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n), d(n);
    for (auto &x : p) cin >> x;
    for (auto &x : d) cin >> x;
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
        int c = (p[i] - d[i] % k + k) % k;
        mp[c].push_back({p[i], i});
    }
    map<pair<int, int>, set<pair<int, int>>> adj;
    set<pair<int, int>> S;
    for (int i = n - 1; i >= 0; i--) {
        int c = (d[i] + p[i]) % k;
        auto it = S.lower_bound({c, -1});
        if (it != S.end() && it->f == c) {
            adj[{i, 0}].insert({it->s, 1});
            S.erase(it);
        }
        S.insert({c, i});
    }
    for (auto x : S) adj[{-1, -1}].insert({x.s, 1});
    S.clear();
    for (int i = 0; i < n; i++) {
        int c = (d[i] - p[i] % k + k) % k;
        auto it = S.lower_bound({c, -1});
        if (it != S.end() && it->f == c) {
            adj[{i, 1}].insert({it->s, 0});
            S.erase(it);
        }
        S.insert({c, i});
    }
    for (auto x : S) adj[{-1, -1}].insert({x.s, 0});

    // cout << "adj:\n";
    // for (auto x : adj) {
    //     cout << "a: " << x.f.f << ' ' << x.f.s << '\n';
    //     for (auto y : x.s) {
    //         cout << y.f << ' ' << y.s << '\n';
    //     }
    // }
    // cout << '\n';

    set<pair<int, int>> vis;
    queue<pair<int, int>> Q;
    Q.push({-1, -1});
    vis.insert({-1, -1});
    while (Q.size()) {
        auto c = Q.front();
        Q.pop();
        for (auto x : adj[c]) {
            if (vis.count(x)) continue;
            Q.push(x);
            vis.insert(x);
        }
    }
    // cout << "vis:\n";
    // for (auto x : vis) cout << x.f << ' ' << x.s << '\n';
    // cout << '\n';

    // cout << "S:\n";
    // for (auto x : S) cout << x.f << " " << x.s << '\n';
    // cout << '\n';

    // cout << "mp:\n";
    // for (auto x : mp) {
    //     cout << x.f << '\n';
    //     for (auto y : x.s) {
    //         cout << y.f << ' ' << y.s << '\n';
    //     }
    // }
    // cout << '\n';

    int q;
    cin >> q;
    while (q--) {
        int c;
        cin >> c;
        auto it =
            lower_bound(mp[c % k].begin(), mp[c % k].end(), make_pair(c, -1ll));
        if (it == mp[c % k].end()) {
            cout << "YES\n";
            continue;
        }
        cout << (vis.count({it->s, 1}) ? "YES\n" : "NO\n");
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}