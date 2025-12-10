// CSES Graph Algorithms: Shortest Routes I

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int32_t main() {
    int n, m;
    cin >> n >> m;
    map<int, vector<pair<int, int>>> adj;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
    }

    vector<int> dist(n, 1e18);
    multiset<pair<int, int>> Q;
    Q.insert({0, 0});
    dist[0] = 0;
    while (Q.size()) {
        int c = Q.begin()->s;
        Q.erase(Q.begin());
        for (auto x : adj[c]) {
            if (dist[c] + x.s < dist[x.f]) {
                Q.erase({dist[x.f], x.f});
                dist[x.f] = dist[c] + x.s;
                Q.insert({dist[x.f], x.f});
            }
        }
    }

    for (auto x : dist) cout << x << ' ';
    cout << '\n';
}