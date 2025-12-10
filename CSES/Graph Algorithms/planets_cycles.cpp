// CSES Graph Algorithms: Planets Cycles

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXN = 2e5;

bool vis[MAXN];
int ans[MAXN];
vector<int> adj[MAXN];

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        adj[--p[i]].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;

        int a = p[i], b = p[p[i]];
        while (a != b) a = p[a], b = p[p[b]];
        vector<int> cycs;
        do {
            b = p[b];
            cycs.push_back(b), vis[b] = 1;
        } while (b != a);

        queue<pair<int, int>> Q;
        for (auto x : cycs) {
            ans[x] = cycs.size();
            for (auto c : adj[x]) {
                if (vis[c]) continue;
                vis[c] = 1;
                Q.emplace(c, 1);
            }
        }

        while (Q.size()) {
            auto [r, d] = Q.front();
            Q.pop();
            ans[r] = d + cyc;
            for (auto c : adj[r]) {
                if (vis[c]) continue;
                Q.emplace(c, d + 1);
                vis[c] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
}
