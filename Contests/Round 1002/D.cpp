// Codeforces Round 1002: Problem D
#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, s1, s2, m1, m2;
    cin >> n >> s1 >> s2 >> m1;
    s1--, s2--;
    vector<set<int>> adj1(n), adj2(n);
    while (m1--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj1[a].insert(b);
        adj1[b].insert(a);
    }
    cin >> m2;
    while (m2--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj2[a].insert(b);
        adj2[b].insert(a);
    }

    set<int> good;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adj1[i].count(j) && adj2[i].count(j)) {
                good.insert(i);
                good.insert(j);
            }
        }
    }

    // for (auto x : good) cout << x << ' ';
    // cout << '\n';

    // vector<vector<int>> dist(n, vector<int>(n, 1e9));
    // priority_queue<pair<int, pair<int, int>>> Q;
    // dist[s1][s2] = 0;
    // Q.push({0, {s1, s2}});
    // while (Q.size()) {
    //     auto c = Q.top().s;
    //     auto dc = Q.top().f;
    //     Q.pop();
    //     if (dist[c.f][c.s] != dc) continue;
    //     for (auto x : adj1[c.f]) {
    //         for (auto y : adj2[c.s]) {
    //             if (dist[c.f][c.s] + abs(x - y) < dist[x][y]) {
    //                 dist[x][y] = dist[c.f][c.s] + abs(x - y);
    //                 Q.push({dist[x][y], {x, y}});
    //             }
    //         }
    //     }
    // }

    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    set<pair<int, pair<int, int>>> Q;
    dist[s1][s2] = 0;
    Q.insert({0, {s1, s2}});
    while (Q.size()) {
        auto c = Q.begin()->s;
        Q.erase(Q.begin());
        for (auto x : adj1[c.f]) {
            for (auto y : adj2[c.s]) {
                if (dist[c.f][c.s] + abs(x - y) < dist[x][y]) {
                    Q.erase({dist[x][y], {x, y}});
                    dist[x][y] = dist[c.f][c.s] + abs(x - y);
                    Q.insert({dist[x][y], {x, y}});
                }
            }
        }
    }

    int ans = 1e9;
    for (auto x : good) ans = min(ans, dist[x][x]);
    cout << (ans == 1e9 ? -1 : ans) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}