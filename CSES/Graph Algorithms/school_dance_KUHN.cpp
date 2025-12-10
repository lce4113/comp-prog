// CSES Graph Algorithms: School Dance

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXN = 500;

int n, m, k;
vector<vector<int>> g(MAXN);
vector<int> mt(MAXN, -1);
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v]) return 0;
    used[v] = 1;
    for (auto to : g[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return 1;
        }
    }
    return 0;
}

int32_t main() {
    cin >> n >> m >> k;
    while (k--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        used.assign(MAXN, 0);
        ans += try_kuhn(i);
    }

    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        if (mt[i] != -1) cout << mt[i] + 1 << ' ' << i + 1 << '\n';
    }
}