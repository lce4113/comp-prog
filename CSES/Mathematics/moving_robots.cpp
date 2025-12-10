// CSES Mathematics: Moving Robots

#include <bits/stdc++.h>
using namespace std;

const int N = 8;

double ps[N][N][N][N], nps[N][N][N][N];
int reach[N][N];

int32_t main() {
    int T;
    cin >> T;
    memset(ps, 0, sizeof(ps));
    memset(nps, 0, sizeof(nps));
    memset(reach, 0, sizeof(reach));
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            ps[x][y][x][y] = 1;
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                reach[x][y]++;
            }
        }
    }

    while (T--) {
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                for (int cx = 0; cx < N; cx++) {
                    for (int cy = 0; cy < N; cy++) {
                        for (int k = 0; k < 4; k++) {
                            int nx = cx + dx[k], ny = cy + dy[k];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                                continue;
                            nps[x][y][nx][ny] +=
                                ps[x][y][cx][cy] / reach[cx][cy];
                        }
                    }
                }
            }
        }
        swap(ps, nps);
        memset(nps, 0, sizeof(nps));
    }

    double ans = 0;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            double c = 1;
            for (int cx = 0; cx < N; cx++) {
                for (int cy = 0; cy < N; cy++) {
                    c *= 1 - ps[cx][cy][x][y];
                }
            }
            ans += c;
        }
    }
    cout << fixed << setprecision(6) << ans << '\n';
}