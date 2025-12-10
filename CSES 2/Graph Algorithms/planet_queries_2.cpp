// CSES Graph Algorithms: Planet Queries II

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;

vector<int> tin(MAXN), tout(MAXN);
vector<set<int>> adj(MAXN);
vector<int> p(MAXN), dst(MAXN);
vector<int> cyc(MAXN, -1), cyc_num(MAXN), cyc_len(MAXN);
vector<bool> vis(MAXN);
int timer = 0;

bool anc(int a, int b) { return tin[b] <= tin[a] && tout[a] <= tout[b]; }

int find(int v) {
    int a = v, b = v;
    do {
        a = p[a], b = p[p[b]];
    } while (a != b);
    return a;
}

void dfs(int v, int c, int d = 1) {
    vis[v] = 1;
    cyc[v] = c;
    dst[v] = d;
    tin[v] = timer++;
    for (auto to : adj[v]) dfs(to, c, d + 1);
    tout[v] = timer++;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        adj[p[i]].insert(i);
    }

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int c = find(i);
        int start = c;
        int curr = 0;
        int tinc = timer;
        do {
            adj[p[c]].erase(c);
            c = p[c];
            vis[c] = 1;
            cyc_num[c] = curr++;
            cyc[c] = c;
        } while (c != start);
        do {
            for (auto v : adj[c]) dfs(v, c);
            c = p[c];
        } while (c != start);
        do {
            tin[c] = tinc, tout[c] = timer;
            cyc_len[c] = curr;
            c = p[c];
        } while (c != start);
        timer++;
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (!anc(a, b)) {
            cout << "-1\n";
            continue;
        }
        if (cyc[b] != b) {
            cout << dst[a] - dst[b] << '\n';
            continue;
        }
        int ans = dst[a];
        a = cyc[a];
        ans += (cyc_num[b] - cyc_num[a] + cyc_len[b]) % cyc_len[b];
        cout << ans << '\n';
    }
}