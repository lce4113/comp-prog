#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;
vector<int> adj[MAXN], ADJ[MAXN], adj2[MAXN];
map<int, vector<int>> colors;
bool rem[MAXN];

int n, m, num;

int q(int num) {
    cout << num + 1 << endl;
    string status;
    cin >> status;
    if (status[0] == 'F') return -1;
    int res;
    cin >> res;
    res--;
    return res;
}

bool bfs(int s) {
    vector<int> dist(MAXN, -1);
    vector<unordered_set<int>> color(MAXN);
    queue<int> Q;
    colors.clear();
    dist[s] = 1e9;
    for (auto c : adj[s]) {
        Q.push(c);
        dist[c] = 0;
        color[c].insert(c);
    }
    while (Q.size()) {
        auto v = Q.front();
        Q.pop();
        for (auto to : adj[v]) {
            if (dist[to] != -1) {
                if (dist[v] + 1 == dist[to]) {
                    for (auto c : color[v]) color[to].insert(c);
                }
                continue;
            }
            for (auto c : color[v]) color[to].insert(c);
            dist[to] = dist[v] + 1;
            Q.push(to);
        }
    }
    for (int v = 0; v < n; v++) {
        for (auto c : color[v]) colors[c].push_back(v);
    }
    int tot = 1;
    for (auto c : colors) {
        cout << c.first << ' ' << c.second.size() << '\n';
        tot += c.second.size();
        if (c.second.size() * 2 > num) return 0;
    }
    if (tot < num) return 0;
    return 1;
}

void solve() {
    for (int i = 0; i < MAXN; i++) adj[i] = ADJ[i];
    for (int i = 0; i < n; i++) rem[i] = 1;
    while (true) {
        int s = -1;
        for (auto v : rem) {
            if (bfs(v)) {
                s = v;
                break;
            }
        }
        int d = q(s);
        memset(rem, 0, sizeof(rem));
        num = 0;
        for (auto v : colors[d]) rem[v] = 1, num++;
        if (d == -1) return;
        for (auto v : rem) {
            if (!rem[v]) continue;
            for (auto to : adj[v]) {
                if (!rem[to]) continue;
                adj2[v].push_back(to);
            }
        }
        for (int i = 0; i < MAXN; i++) adj[i] = adj2[i];
        for (auto &x : adj2) x.clear();
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    num = n;
    while (m--) {
        int N;
        cin >> N;
        vector<int> path(N);
        for (auto &p : path) {
            cin >> p;
            p--;
        }
        for (int i = 0; i < N - 1; i++) {
            ADJ[path[i]].push_back(path[i + 1]);
            ADJ[path[i + 1]].push_back(path[i]);
        }
    }
    for (int i = 0; i < MAXN; i++) adj[i] = ADJ[i];
    int t = n;
    while (t--) solve();
}
