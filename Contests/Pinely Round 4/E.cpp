// Codeforces Pinely Round 4: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, m;
map<int, vector<int>> adj;

pair<int, int> in() {
    int a, b;
    cin >> a >> b;
    return {a, b};
}
void o(int a, int b) { cout << a << ' ' << b << endl; }

void alice() {
    for (int i = 0; i < n; i++) {
        o(1, 2);
        in();
    }
}

void solve() {
    cin >> n >> m;
    adj.clear();
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    map<int, int> par;
    queue<pair<int, int>> Q;
    Q.push({1, 0});
    par[1] = 0;
    while (Q.size()) {
        pair<int, int> c = Q.front();
        // cout << c.f << ' ' << c.s << '\n';
        Q.pop();
        for (auto x : adj[c.f]) {
            if (par.count(x)) {
                if (par[x] != 1 - c.s) {
                    cout << "Alice" << endl;
                    alice();
                    return;
                }
                continue;
            }
            Q.push({x, 1 - c.s});
            par[x] = 1 - c.s;
        }
    }
    cout << "Bob" << endl;
    set<int> v1, v2;
    for (auto p : par) {
        if (p.s == 0) v1.insert(p.f);
        if (p.s == 1) v2.insert(p.f);
    }
    for (int i = 0; i < n; i++) {
        auto x = in();
        if (x == make_pair(1ll, 2ll) || x == make_pair(2ll, 1ll)) {
            if (v1.size()) {
                o(*v1.begin(), 1);
                v1.erase(*v1.begin());
            } else {
                o(*v2.begin(), 2);
                v2.erase(*v2.begin());
            }
        } else if (x == make_pair(1ll, 3ll) || x == make_pair(3ll, 1ll)) {
            if (v1.size()) {
                o(*v1.begin(), 1);
                v1.erase(*v1.begin());
            } else {
                o(*v2.begin(), 3);
                v2.erase(*v2.begin());
            }
        } else if (x == make_pair(2ll, 3ll) || x == make_pair(3ll, 2ll)) {
            if (v2.size()) {
                o(*v2.begin(), 2);
                v2.erase(*v2.begin());
            } else {
                o(*v1.begin(), 3);
                v1.erase(*v1.begin());
            }
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}