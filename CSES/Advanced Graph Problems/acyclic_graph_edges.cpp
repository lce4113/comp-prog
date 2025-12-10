// CSES Advanced Graph Problems: Acyclic Graph Edges

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (u < v) swap(u, v);
        cout << u << ' ' << v << '\n';
    }
}