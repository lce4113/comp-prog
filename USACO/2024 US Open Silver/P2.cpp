// USACO 2024 Open: Problem 2 "Painting Fence Posts"

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

map<pair<int, int>, int> mp;

void solve() {
    int n, p;
    cin >> n >> p;
    vector<pair<int, int>> f1(p);
    for (auto &x : f1) cin >> x.f >> x.s;

    map<int, vector<int>> fx, fy;
    for (auto x : f1) {
        fx[x.f].push_back(x.s);
        fy[x.s].push_back(x.f);
    }
    for (auto &x : fx) sort(x.s.begin(), x.s.end());
    for (auto &x : fy) sort(x.s.begin(), x.s.end());

    // for (auto x : fx) {
    //     cout << x.f << ": ";
    //     for (auto y : x.s) cout << y << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';
    // for (auto x : fy) {
    //     cout << x.f << ": ";
    //     for (auto y : x.s) cout << y << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';

    vector<pair<int, int>> F;
    F.push_back(f1[0]);
    bool X = true;
    for (int i = 1; i < p; i++) {
        int x = F.back().f, y = F.back().s;
        if (X) {
            int pos =
                lower_bound(fx[x].begin(), fx[x].end(), y) - fx[x].begin();
            int nxt = pos - (pos % 2) + 1 - (pos % 2);
            F.push_back({x, fx[x][nxt]});
        } else {
            int pos =
                lower_bound(fy[y].begin(), fy[y].end(), x) - fy[y].begin();
            int nxt = pos - (pos % 2) + 1 - (pos % 2);
            F.push_back({fy[y][nxt], y});
        }
        X = !X;
    }

    for (int i = 0; i < p; i++) mp[F[i]] = i;

    // for (auto x : F) cout << x.f << "," << x.s << ' ';
    // cout << '\n';

    vector<int> dist(p);
    for (int i = 0; i < p; i++) {
        dist[i] =
            abs(F[(i + 1) % p].f - F[i].f) + abs(F[(i + 1) % p].s - F[i].s);
    }

    vector<int> dpfs(p + 1, 0);
    for (int i = 0; i < p; i++) dpfs[i + 1] = dpfs[i] + dist[i];

    // for (auto x : dist) cout << x << ' ';
    // cout << '\n';
    // for (auto x : dpfs) cout << x << ' ';
    // cout << '\n';

    vector<int> diffs(p + 1, 0);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int y1p =
            lower_bound(fx[x1].begin(), fx[x1].end(), y1) - fx[x1].begin();
        int x1p =
            lower_bound(fy[y1].begin(), fy[y1].end(), x1) - fy[y1].begin();
        int p1b, p1f;
        if (mp.count({x1, y1})) {
            p1b = mp[{x1, y1}], p1f = mp[{x1, y1}];
        } else if (y1p < (int)fx[x1].size() && (y1p % 2 || fx[x1][y1p] == y1)) {
            int P = mp[{x1, fx[x1][y1p]}];
            if (F[(P + 1) % p].f == F[P].f)
                p1b = P, p1f = (P + 1) % p;
            else
                p1b = (P - 1 + p) % p, p1f = P;
        } else {
            int P = mp[{fy[y1][x1p], y1}];
            if (F[(P + 1) % p].s == F[P].s)
                p1b = P, p1f = (P + 1) % p;
            else
                p1b = (P - 1 + p) % p, p1f = P;
        }

        int y2p =
            lower_bound(fx[x2].begin(), fx[x2].end(), y2) - fx[x2].begin();
        int x2p =
            lower_bound(fy[y2].begin(), fy[y2].end(), x2) - fy[y2].begin();
        int p2b, p2f;
        if (mp.count({x2, y2})) {
            p2b = mp[{x2, y2}], p2f = mp[{x2, y2}];
        } else if (y2p < (int)fx[x2].size() && (y2p % 2 || fx[x2][y2p] == y2)) {
            int P = mp[{x2, fx[x2][y2p]}];
            if (F[(P + 1) % p].f == F[P].f)
                p2b = P, p2f = (P + 1) % p;
            else
                p2b = (P - 1 + p) % p, p2f = P;
        } else {
            int P = mp[{fy[y2][x2p], y2}];
            if (F[(P + 1) % p].s == F[P].s)
                p2b = P, p2f = (P + 1) % p;
            else
                p2b = (P - 1 + p) % p, p2f = P;
        }

        if (p1b == p2b && !mp.count({x1, y1})) continue;

        if (p2b < p1b)
            swap(p1b, p2b), swap(p1f, p2f), swap(x1, x2), swap(y1, y2);
        // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        // cout << p1b << ' ' << p1f << '\n';
        // cout << p2b << ' ' << p2f << '\n';
        int D1 = dpfs[p2b] - dpfs[p1f];
        D1 += abs(x1 - F[p1f].f) + abs(y1 - F[p1f].s);
        D1 += abs(x2 - F[p2b].f) + abs(y2 - F[p2b].s);
        int D2 = dpfs[p] - D1;
        // cout << "D: " << D1 << ' ' << D2 << '\n';
        if (D2 < D1) {
            diffs[0]++;
            swap(p1b, p2b), swap(p1f, p2f), swap(x1, x2), swap(y1, y2);
        }
        // cout << p1b << ' ' << p1f << '\n';
        // cout << p2b << ' ' << p2f << '\n';
        diffs[p1f]++;
        diffs[p2b + 1]--;

        // for (auto x : diffs) cout << x << ' ';
        // cout << '\n';
        // cout << '\n';
    }

    // cout << mp[F[3]] << '\n';

    vector<int> sm;
    int c = 0;
    for (auto x : diffs) {
        c += x;
        sm.push_back(c);
    }

    // for (auto x : sm) cout << x << ' ';
    // cout << '\n';

    vector<int> ans(p);
    for (int i = 0; i < p; i++) {
        int pos = mp[f1[i]];
        ans[i] = sm[pos];
    }

    for (auto x : ans) cout << x << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
