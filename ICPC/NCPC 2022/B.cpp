// https://open.kattis.com/problem-sources/Nordic%20Collegiate%20Programming%20Contest%20(NCPC)%202022?order=difficulty_data
// https://youtu.be/S25kO1kric8?t=1075

#include <bits/stdc++.h>
using namespace std;

#define int long long

map<int, vector<int>> adj;
// map<int, int> dp;
// set<int> cvisited;

// int num_children(int n, int root) {
//     if (dp.count(root)) return dp[root];
//     cvisited.insert(root);
//     int ans = 1;
//     for (auto x : adj[root]) {
//         if (cvisited.count(x)) continue;
//         ans += num_children(n, x);
//         // cout << x << ' ';
//     }
//     // cout << '\n';
//     dp[root] = ans;
//     return ans;
// }

pair<int, int> max_dist(int n) {
    map<int, int> dist;
    set<int> visited;
    queue<int> q;
    q.push(n), dist[n] = 0;
    int mi = 0;
    while (q.size()) {
        int curr = q.front();
        q.pop();
        visited.insert(curr);
        for (auto x : adj[curr]) {
            if (visited.count(x)) continue;
            q.push(x);
            dist[x] = dist[curr] + 1;
            if (dist[x] > dist[mi]) mi = x;
        }
    }
    return {mi, dist[mi]};
}

int32_t main() {
    int n;
    cin >> n;
    int root = -1;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (root == -1 && adj[a].size() >= 2) root = a;
        if (root == -1 && adj[b].size() >= 2) root = b;
    }
    int d1 = max_dist(1).first;
    int diam = max_dist(d1).second;

    if (diam <= 3) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    // num_children(n, root);

    // for (auto x : dp) cout << x.first << ' ' << x.second << '\n';
    // cout << '\n';

    set<int> visited;
    queue<int> q;
    q.push(root);
    visited.insert(root);
    for (auto x : adj[root]) {
        if (!adj[x].empty()) {
            q.push(x);
            visited.insert(x);
            break;
        }
    }
    while (q.size()) {
        int curr = q.front();
        q.pop();
        cout << curr << ' ';
        for (auto x : adj[curr]) {
            if (visited.count(x)) continue;
            q.push(x);
            visited.insert(x);
        }
    }
    cout << '\n';
}