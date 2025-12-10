// CSES Advanced Techniques: Parcel Delivery

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int n, m, k;
// from, to, capacity, cost, opposite
vector<array<int, 5>> edges;
vector<int> p, d;

void path(int s) {
    d[s] = 0;
    for (int r = n; r--;) {
        int M = edges.size();
        for (int i = 0; i < M; i++) {
            auto e = edges[i];
            if (e[2] == 0) continue;
            if (d[e[0]] + e[3] < d[e[1]]) {
                d[e[1]] = d[e[0]] + e[3];
                p[e[1]] = i;
            }
        }
    }
}

int min_cost(int s, int t) {
    int tot = 0;
    while (k) {
        p.assign(n, -1);
        d.assign(n, INF);
        path(s);
        if (d[t] == INF) return -1;
        int c = t, flow = INF, cost = 0;
        while (c != s) {
            auto e = edges[p[c]];
            flow = min(flow, e[2]);
            cost += e[3];
            c = e[0];
        }

        flow = min(flow, k);
        k -= flow;
        tot += cost * flow;

        c = t;
        while (c != s) {
            auto e = edges[p[c]];
            edges[e[4]][2] += flow;
            edges[p[c]][2] -= flow;
            c = e[0];
        }
    }
    return tot;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> k;
    edges.assign(m, {0, 0, 0, 0});
    for (auto &e : edges) {
        cin >> e[0] >> e[1] >> e[2] >> e[3];
        e[0]--, e[1]--;
    }
    for (int i = 0; i < m; i++) {
        auto e = edges[i];
        edges.push_back({e[1], e[0], 0, -e[3], i});
        edges[i][4] = i + m;
    }
    cout << min_cost(0, n - 1) << '\n';
}