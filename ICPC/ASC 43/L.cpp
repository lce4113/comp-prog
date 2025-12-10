#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

vector<pair<int, int>> ans;
int timer;
int n, m;

int reset(vector<pair<int, int>> &g, int v) {
    if (v == -1) return -1;
    int cur = timer++;
    int L = reset(g, g[v].f);
    int R = reset(g, g[v].s);
    ans[cur] = {L, R};
    return cur;
}

void rem(int v, vector<pair<int, int>> &g, bool L = 0) {
    if (v == -1) return;
    rem(g[v].f, g, L);
    rem(g[v].s, g, L);
    if (L) n -= g[v].f != -1;
    if (L) n -= g[v].s != -1;
    g[v] = {-1, -1};
}

bool dfs(int v1, int v2, vector<pair<int, int>> &g1,
         vector<pair<int, int>> &g2) {
    bool le = g1[v1].f == -1 && g1[v1].s == -1;
    bool re = g2[v2].f == -1 && g2[v2].s == -1;
    if (le && re) {
        return 0;
    }
    if (le) {
        rem(v2, g2);
        return 1;
    }
    if (re) {
        rem(v1, g1, 1);
        return 1;
    }
    bool ld = dfs(g1[v1].f, g2[v2].f, g1, g2);
    if (ld) {
        rem(g1[v1].s, g1, 1);
        rem(g2[v2].s, g2);
        return 1;
    }
    bool rd = dfs(g1[v1].s, g2[v2].s, g1, g2);
    if (rd) {
        return 1;
    }
    return 0;
}

void get(vector<pair<int, int>> &g, int N) {
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        g[i] = {l - 1, r - 1};
    }
}

int32_t main() {
#ifdef ONLINE_JUDGE
    ifstream cin("lca.in");
    ofstream cout("lca.out");
#endif

    while (1) {
        cin >> n;
        if (n == 0) break;
        vector<pair<int, int>> g1(n);
        get(g1, n);
        cin >> m;
        vector<pair<int, int>> g2(m);
        get(g2, m);
        dfs(0, 0, g1, g2);
        timer = 0;
        ans.assign(n, {-1, -1});
        reset(g1, 0);
        cout << n << '\n';
        for (auto x : ans) cout << x.f + 1 << ' ' << x.s + 1 << '\n';
    }
}