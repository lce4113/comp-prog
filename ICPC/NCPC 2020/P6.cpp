/*
// Problem D

#include <bits/stdc++.h>

using namespace std;
#define int long long
vector<vector<int>> adj;
vector<pair<int, int>> water;

vector<bool> visited;
int dfs(int node, int miniOverflow, int needed) {

    int ans = 1e9;
    visited[node] = true;
    int thisOverflow =
        max(miniOverflow, water[node].first - water[node].second);
    int thisNeeded = needed - water[node].second;

    if (thisNeeded > 0) {
        int tmp = water[node].first - water[node].second;
        int left = thisNeeded - tmp;

        ans = ((water[node].first - water[node].second) + max(left, 0ll));

    } else {
        ans = water[node].first - water[node].second;
    }
    for (auto x : adj[node]) {
        if (!visited[x]) {
            ans = min(ans, dfs(x, thisOverflow, thisNeeded));
        }
    }
    cout << node << " " << ans << endl;
    return ans;
}
void solve() {
    int n, k;
    cin >> n >> k;
    adj.resize(n + 1);
    water.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < n; i++) {
        int u, cap, cur;
        cin >> u >> cap >> cur;
        adj[u].push_back(i + 1);
        water[i + 1] = {cap, cur};
    }
    water[0] = {0, 0};
    int tst = dfs(0, 0, k);
    cout << tst << endl;
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
*/
// Problem A

#include <bits/stdc++.h>

using namespace std;
#define int long long
vector<vector<int>> adj;
vector<pair<int, int>> water;

vector<bool> visited;
int dfs(int node, int miniOverflow, int needed) {
    int ans = 1e9;
    visited[node] = true;
    int thisOverflow =
        max(miniOverflow, water[node].first - water[node].second);
    int thisNeeded = needed - water[node].second;
    ans = thisNeeded;
    for (auto x : adj[node]) {
        if (!visited[x]) {
            ans = min(ans, dfs(x, thisOverflow, thisNeeded));
        }
    }
    cout << node << " " << ans << endl;
    return ans;
}
void solve() {
    int n, k;
    cin >> n >> k;
    adj.resize(n + 1);
    water.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < n; i++) {
        int u, cap, cur;
        cin >> u >> cap >> cur;
        adj[u].push_back(i + 1);
        water[i + 1] = {cap, cur};
    }
    water[0] = {0, 0};
    int tst = dfs(0, 0, k);
    cout << tst << endl;
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}