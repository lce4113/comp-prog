// ASC 2: Problem H

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;

void solve() {
#ifdef ONLINE_JUDGE
    ifstream cin("tickets.in");
    ofstream cout("tickets.out");
#endif

    cin >> n >> m;
    int ans = 0;
    for (int r = 0; r < 4; r++) {
        if (n != m && r % 2) continue;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // cout << "r,i,j: " << r << ' ' << i << ' ' << j << '\n';
                vector<vector<bool>> vis(n, vector<bool>(m, 0));
                int cmp = 0;
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if (vis[x][y]) continue;
                        int cx = x, cy = y;
                        do {
                            // cout << cx << ' ' << cy << '\n';
                            vis[cx][cy] = 1;
                            if (r == 2) {
                                cx = n - 1 - cx, cy = m - 1 - cy;
                            } else {
                                for (int rep = r; rep--;) {
                                    swap(cx, cy);
                                    cy = m - 1 - cy;
                                }
                            }
                            cx = (cx + i) % n;
                            cy = (cy + j) % m;
                        } while (!(cx == x && cy == y));
                        cmp++;
                    }
                }
                ans += (1ll << cmp);
            }
        }
    }
    ans /= n == m ? n * m * 4 : n * m * 2;
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    // for (int i = 1; i <= 20; i++) {
    //     for (int j = 1; j <= 20; j++) {
    //         n = i, m = j;
    //         solve();
    //     }
    // }
}