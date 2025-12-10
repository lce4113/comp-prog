// Codeforces Round 1055: Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int B = 20;

void solve() {
    int n, z;
    cin >> n >> z;
    vector<int> p(n);
    for (auto &x : p) cin >> x;
    vector<vector<int>> nxt(B + 1, vector<int>(n));
    for (int i = 0; i < n; i++) {
        int pos = upper_bound(p.begin(), p.end(), p[i] + z) - p.begin();
        nxt[0][i] = pos;
    }
    for (int i = 1; i <= B; i++) {
        for (int j = 0; j < n; j++) {
            nxt[i][j] = nxt[i - 1][j] == n ? n : nxt[i - 1][nxt[i - 1][j]];
        }
    }

    vector<vector<pair<int, int>>> col(B + 1, vector<pair<int, int>>(n));
    for (int i = 0; i < n; i++) {
        if (i + 1 == n) {
            col[0][i] = {n, 1};
            continue;
        }
        int a = i, b = i + 1, c = 0;
        for (int j = B; j >= 0; j--) {
            if (b == n) break;
            if (nxt[j][a] != nxt[j][b]) {
                a = nxt[j][a];
                b = nxt[j][b];
                c += (1 << j) * 2;
            }
        }
        // cout << a << ' ' << b << '\n';
        int A = nxt[0][i], C = 1;
        b = i + 1;
        for (int j = B; j >= 0; j--) {
            if (A == n) break;
            if (nxt[j][A] != nxt[j][b]) {
                A = nxt[j][A];
                b = nxt[j][b];
                C += (1 << j) * 2;
            }
        }
        // cout << i << ": " << a << ' ' << A << '\n';
        if (A < a) {
            col[0][i] = {A == n ? n : nxt[0][A], C + 2};
        } else {
            col[0][i] = {a == n ? n : nxt[0][a], c + 2};
        }
    }
    for (int i = 1; i <= B; i++) {
        for (int j = 0; j < n; j++) {
            if (col[i - 1][j].f == n) {
                col[i][j] = col[i - 1][j];
                continue;
            }
            auto [x, c] = col[i - 1][col[i - 1][j].f];
            col[i][j] = {x, col[i - 1][j].s + c};
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << i << ": " << col[0][i].f << ' ' << col[0][i].s << '\n';
    // }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        // cout << l << ' ' << r << '\n';
        int ans = 0;
        for (int i = B; i >= 0; i--) {
            if (col[i][l].f < r) {
                // cout << "col: " << col[i][l].f << ' ' << col[i][l].s << '\n';
                ans += col[i][l].s, l = col[i][l].f;
                // cout << "l: " << l << '\n';
            }
        }
        if (l + 1 == r) {
            cout << ans + 1 << '\n';
            continue;
        }
        // cout << "ans: " << ans << '\n';
        int a = l, b = l + 1;
        for (int i = B; i >= 0; i--) {
            if (nxt[i][a] < r) {
                a = nxt[i][a], ans += (1 << i);
                // cout << "a: " << a << '\n';
            }
        }
        for (int i = B; i >= 0; i--) {
            if (nxt[i][b] < r) {
                b = nxt[i][b], ans += (1 << i);
                // cout << "b: " << b << '\n';
            }
        }
        cout << ans + 2 << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}