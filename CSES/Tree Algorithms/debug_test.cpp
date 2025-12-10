#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int n;
    vector<int> a;
    Tree(int _n) : n(_n), a(2 * _n, -1) {}
    void u(int pos, int val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = max(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int ans = -1;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans = max(ans, a[l++]);
            if (r % 2) ans = max(ans, a[--r]);
        }
        return ans;
    }
};

const int MAXN = 10;
vector<int> sz(MAXN);
vector<int> heavy(MAXN, -1);
vector<int> head(MAXN);
vector<int> par(MAXN);
vector<int> pos(MAXN);
vector<int> dep(MAXN, -1);
vector<int> vals(MAXN);
vector<vector<int>> adj(MAXN);
int timer = 0;
Tree seg(MAXN);

void dfs(int v, int p) {
    par[v] = p;
    sz[v] = 1;
    if (p == -1) dep[v] = 0;  // Fix for root
    else dep[v] = dep[p] + 1;
    
    cout << "DFS: node " << v << ", parent " << p << ", depth " << dep[v] << endl;
    
    for (auto to : adj[v]) {
        if (to == p) continue;
        dfs(to, v);
        sz[v] += sz[to];
        if (heavy[v] == -1 || sz[to] > sz[heavy[v]]) heavy[v] = to;
    }
}

void decomp(int v, int h) {
    pos[v] = timer++;
    seg.u(pos[v], vals[v]);
    head[v] = h;
    cout << "Decomp: node " << v << ", pos " << pos[v] << ", head " << head[v] << ", val " << vals[v] << endl;
    
    if (heavy[v] != -1) decomp(heavy[v], h);
    for (auto to : adj[v]) {
        if (to == par[v] || to == heavy[v]) continue;
        decomp(to, to);
    }
}

int Q(int a, int b) {
    cout << "Query: " << a << " to " << b << endl;
    int ans = -1;
    for (; head[a] != head[b]; a = par[head[a]]) {
        if (dep[a] < dep[b]) swap(a, b);
        cout << "  Processing chain from " << head[a] << " to " << a << " (pos " << pos[head[a]] << " to " << pos[a]+1 << ")" << endl;
        ans = max(ans, seg.q(pos[head[a]], pos[a] + 1));
    }
    if (dep[a] < dep[b]) swap(a, b);
    cout << "  Final segment: " << b << " to " << a << " (pos " << pos[b] << " to " << pos[a]+1 << ")" << endl;
    ans = max(ans, seg.q(pos[b], pos[a] + 1));
    return ans;
}

int main() {
    // Test case: tree with 5 nodes
    int n = 5;
    vals = {2, 4, 1, 3, 3};
    
    // Build tree: 0-1, 0-2, 1-3, 1-4
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};
    
    dfs(0, -1);  // Fixed: pass -1 as parent for root
    timer = 0;   // Reset timer
    decomp(0, 0);
    
    cout << "\nQuery 2->4 (path 2-0-1-4):" << endl;
    cout << "Answer: " << Q(2, 4) << endl;
    
    return 0;
} 