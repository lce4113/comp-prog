#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int dots[n][m];
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            char c;
            cin >> c;
            dots[x][y] = (c == '.');
        }
    }

    // bfs
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int ans = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (dots[x][y] == 0) continue;
            queue<pair<int, int>> bfs;
            bfs.push({x, y});
            while (!bfs.empty()) {
                auto curr = bfs.front();
                bfs.pop();
                for (int k = 0; k < 4; k++) {
                    int x2 = curr.first + dx[k], y2 = curr.second + dy[k];
                    if (x2 < 0 || x2 >= n) continue;
                    if (y2 < 0 || y2 >= m) continue;
                    if (dots[x2][y2] == 0) continue;
                    dots[x2][y2] = 0;
                    bfs.push({x2, y2});
                }
            }
            ans++;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}

// #include <bits/stdc++.h>

// using namespace std;

// char c;
// int N, M, cnt;
// int h[] = {1, -1, 0, 0}, v[] = {0, 0, 1, -1};
// bool vis[1000][1000];

// void dfs(int x, int y) {
//     vis[x][y] = true;
//     for (int i = 0; i < 4; i++) {
//         int dx = x + h[i], dy = y + v[i];
//         if (0 <= dx && dx < N && 0 <= dy && dy < M && !vis[dx][dy]) dfs(dx,
//         dy);
//     }
// }

// int main() {
//     scanf("%d %d", &N, &M);
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < M; j++) {
//             scanf(" %c", &c);
//             vis[i][j] = (c == '#');
//         }
//     }
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < M; j++) {
//             if (!vis[i][j]) {
//                 dfs(i, j);
//                 cnt++;
//             }
//         }
//     }
//     printf("%d\n", cnt);
// }