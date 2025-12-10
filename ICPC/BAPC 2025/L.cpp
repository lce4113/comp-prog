// BAPC 2025: Problem L

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 22;
const int M2 = 35000;
// for this direction, this many Bs/Cs have this dot product
short BS[M2][3 * N * 2 * N] = {}, CS[M2][3 * N * 2 * N] = {};
const int OFF = 3 * (N - 1) * (N - 1);
int ind[2 * N - 1][2 * N - 1][2 * N - 1];

array<int, 3> get(int x, int y, int z) {
    if (x < 0) x *= -1, y *= -1, z *= -1;
    vector<int> ps;
    for (auto co : {x, y, z}) {
        if (co != 0) ps.push_back(abs(co));
    }
    int g = ps.size() ? ps[0] : 1;
    for (auto co : ps) g = gcd(g, co);
    return {x / g, y / g, z / g};
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    map<char, vector<array<int, 3>>> mp;
    for (int x = 0; x < n; x++) {
        char _;
        cin >> _;
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                char c;
                cin >> c;
                mp[c].push_back({x, y, z});
            }
        }
    }

    vector<array<int, 3>> vecs;
    memset(ind, -1, sizeof(ind));
    for (int x = -N + 1; x < N; x++) {
        for (int y = -N + 1; y < N; y++) {
            for (int z = -N + 1; z < N; z++) {
                auto [nx, ny, nz] = get(x, y, z);
                if (ind[nx + N - 1][ny + N - 1][nz + N - 1] != -1) {
                    ind[x + N - 1][y + N - 1][z + N - 1] =
                        ind[nx + N - 1][ny + N - 1][nz + N - 1];
                    continue;
                }
                ind[nx + N - 1][ny + N - 1][nz + N - 1] = vecs.size();
                ind[x + N - 1][y + N - 1][z + N - 1] = vecs.size();
                vecs.push_back({nx, ny, nz});
            }
        }
    }
    // M = 33681
    int M = vecs.size();

    for (int i = 0; i < M; i++) {
        auto [x1, y1, z1] = vecs[i];
        for (auto [x, y, z] : mp['B']) {
            int pr = x1 * x + y1 * y + z1 * z;
            BS[i][pr + OFF]++;
        }
        for (auto [x, y, z] : mp['C']) {
            int pr = x1 * x + y1 * y + z1 * z;
            CS[i][pr + OFF]++;
        }
    }

    ll ans = 0;
    for (auto [xa, ya, za] : mp['A']) {
        for (auto [xp, yp, zp] : mp['P']) {
            int vi = ind[xp - xa + N - 1][yp - ya + N - 1][zp - za + N - 1];
            auto [xd, yd, zd] = vecs[vi];
            int pra = xd * xa + yd * ya + zd * za;
            int prp = xd * xp + yd * yp + zd * zp;
            ans += 1ll * BS[vi][pra + OFF] * CS[vi][prp + OFF];
        }
    }
    cout << ans << endl;
}