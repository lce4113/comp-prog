// CSES Intro Problems: Grid Path Description

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int N = 7;

string a;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool vis[7][7];
int ans = 0;

void rec(int i, int x, int y) {
    if (i == N * N - 1 && x == N - 1 && y == 0) {
        ans++;
        return;
    }
    if (i == N * N - 1) return;
    if (x == N - 1 && y == 0) return;

    bool blockL = (y - 1 < 0 || vis[x][y - 1]);
    bool blockR = (y + 1 > 6 || vis[x][y + 1]);
    bool blockU = (x - 1 < 0 || vis[x - 1][y]);
    bool blockD = (x + 1 > 6 || vis[x + 1][y]);
    if ((blockL && blockR && !blockU && !blockD) ||
        (blockU && blockD && !blockL && !blockR)) {
        return;
    }

    vis[x][y] = 1;
    if (a[i] == '?') {
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j], ny = y + dy[j];
            if (nx < 0 || nx >= N) continue;
            if (ny < 0 || ny >= N) continue;
            if (vis[nx][ny]) continue;
            rec(i + 1, nx, ny);
        }
    } else {
        int nx = x + (a[i] == 'U' ? -1 : (a[i] == 'D' ? 1 : 0));
        int ny = y + (a[i] == 'R' ? 1 : (a[i] == 'L' ? -1 : 0));
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !vis[nx][ny]) {
            rec(i + 1, nx, ny);
        }
    }
    vis[x][y] = 0;
    return;
}

void solve() {
    cin >> a;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vis[i][j] = 0;
        }
    }
    rec(0, 0, 0);
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
