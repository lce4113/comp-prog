#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
typedef pair<int, int> pi;

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for (int i = 0; i < k; i++) {
        pq.push({a[i], i + 1});
    }
    map<int, set<int>> adj;
    pi prev = {-1, 0};
    for (int i = k; i < n; i++) {
        pi x = pq.top();
        // cout << i << ' ' << x.f << ' ' << x.s << '\n';
        if (prev.f == x.f) {
            adj[prev.s].insert(x.s);
            adj[x.s].insert(prev.s);
        }
        prev = x;
        pq.pop();
        pq.push({x.f + a[i], x.s});
    }
    // cout << prev.f << ' ' << prev.s << '\n';
    // cout << pq.top().f << ' ' << pq.top().s << '\n';

    // for (auto x : adj) {
    //     cout << x.f << ": ";
    //     for (auto y : x.s) cout << y << ' ';
    //     cout << '\n';
    // }

    // BFS
    set<int> vis;
    queue<int> Q;
    pi fin = pq.top();
    Q.push(fin.s);
    vis.insert(fin.s);
    // cout << prev.f << ' ' << prev.s << '\n';
    while (pq.top().f == prev.f) {
        adj[pq.top().s].insert(prev.s);
        adj[prev.s].insert(pq.top().s);
        // cout << pq.top().f << ' ' << pq.top().s << '\n';
        pq.pop();
    }
    string ans = "";
    for (int i = 0; i < k; i++) ans += '0';
    while (Q.size()) {
        int curr = Q.front();
        Q.pop();
        ans[curr - 1] = '1';
        for (auto x : adj[curr]) {
            if (vis.count(x)) continue;
            Q.push(x);
            vis.insert(x);
        }
    }
    cout << fin.f << '\n';
    cout << ans << '\n';
    // for (auto x : adj) {
    //     cout << x.f << ": ";
    //     for (auto y : x.s) cout << y << ' ';
    //     cout << '\n';
    // }
}