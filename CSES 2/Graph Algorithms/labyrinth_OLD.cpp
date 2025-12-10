#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1010;
bool a[MAXN][MAXN];
char dp[MAXN][MAXN];
int n, m;
pair<int, int> start, fin;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            char x;
            cin >> x;
            a[i][k] = (x == '.' || x == 'A' || x == 'B');
            if (x == 'A') start = {i, k};
            if (x == 'B') fin = {i, k};
            dp[i][k] = "x";
        }
    }

    queue<pair<pair<int, int>, string>> Q;
    Q.push({start, ""});
    a[start.first][start.second] = false;
    while (Q.size()) {
        pair<int, int> curr = Q.front().first;
        string path = Q.front().second;
        if (path.size() < dp[curr.first][curr.second].size() ||
            dp[curr.first][curr.second] == "x") {
            dp[curr.first][curr.second] = path;
        }
        Q.pop();
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        char dd[4] = {'U', 'D', 'L', 'R'};
        for (int k = 0; k < 4; k++) {
            int x = curr.first + dx[k];
            int y = curr.second + dy[k];
            if (x >= n || x < 0) continue;
            if (y >= m || y < 0) continue;
            if (!a[x][y]) continue;
            a[x][y] = false;
            Q.push({{x, y}, path + dd[k]});
        }
    }

    string path = dp[fin.first][fin.second];
    if (path == "x") {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << path.size() << '\n';
    cout << path << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}