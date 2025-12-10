// ICPC 2022 Pacific Northwest Regionals
// Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

vector<array<int, 3>> a;
vector<pair<int, int>> ans;
int n;

void mv(int x, int y) {
    ans.push_back({x + 1, y + 1});
    int i = 2, j = 0;

    while (a[x][i] == 0) i--;
    while (a[y][j] != 0) j++;
    swap(a[x][i], a[y][j]);
}

void fix() {
    vector<int> zs;
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == 0) zs.push_back(i);
        }
    }
    for (int i = 0; i < 3; i++) {
        if (zs[i] != n) mv(n, zs[i]);
    }
}

void sec(int r, int x, int y) {
    mv(r, n);
    mv(r, n); // r = 1, x = 3, n = 2
    if (y == 0) {
        mv(x, r);
        mv(x, r); // r = 3, x = 1, n = 2
        mv(x, n); // r = 3, x = 0, n = 3
        mv(r, x);
        mv(r, x); // r = 1, x = 2, n = 3
        mv(n, r); // r = 2, x = 2, n = 2
        mv(n, r); // r = 3, x = 2, n = 1
        mv(n, x); // r = 3, x = 3, n = 0
    } else if (y == 1) {
        mv(x, n);
        mv(x, r);
        mv(n, x);
        mv(n, x);
        mv(n, r);
    } else {
        mv(x, r);
        mv(n, x);
        mv(n, r);
    }
}
void fir(int r, int x, int y) {
    mv(r, n); // r = 2, x = 3, n = 1
    if (y == 0) {
        mv(x, n);
        mv(x, n); // r = 2, x = 1, n = 3
        mv(x, r);
        mv(n, x);
        mv(n, x);
        mv(n, x);
    } else if (y == 1) {
        mv(x, n); // r = 2, x = 2, n = 2
        mv(x, r);
        mv(n, x);
        mv(n, x);
    } else {
        mv(x, r);
        mv(n, x);
    }
}

void sol(int r) {
    if (a[r][0] == a[r][1] && a[r][1] == a[r][2]) return;
    for (int i = 0; i < n; i++) {
        if (i == r) continue;
        bool ok = 1;
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == a[r][0]) {
                if (a[r][0] == a[r][1])
                    fir(r, i, j);
                else
                    sec(r, i, j);
                ok = 0;
                break;
            }
        }
        if (!ok) break;
    }
    if (a[r][0] == a[r][1] && a[r][1] == a[r][2]) return;
    for (int i = 0; i < n; i++) {
        if (i == r) continue;
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == a[r][0]) {
                fir(r, i, j);
                return;
            }
        }
    }
}

void solve() {
    cin >> n;
    a.assign(n + 1, array<int, 3>());
    for (auto &x : a) cin >> x[0] >> x[1] >> x[2];

    fix();

    for (int i = 0; i < n; i++) sol(i);

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x.f << ' ' << x.s << '\n';
    // for (auto x : a) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}