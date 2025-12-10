// BAPC 2024: Problem A

#include <bits/stdc++.h>
using namespace std;

vector<int> rs, es;
vector<string> a;
int n, m, r;
// int timer = 0;

void rot(int e, int rd) {
    // if (timer-- < 0) return;
    // cout << e << ' ' << rd << '\n';
    for (int i = e - 1; i >= e - rd; i--) {
        swap(a[i], a[i + 1]);
        swap(rs[i], rs[i + 1]);
    }
}

pair<int, int> get() {
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i < m; i++) {
            if (a[j][i] == 'P') {
                return {j, i};
            }
        }
    }
    return {-1, -1};
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> r;
    a.assign(n, "");
    for (auto &x : a) cin >> x;
    rs.assign(n, 0);
    iota(rs.begin(), rs.end(), 1);
    while (1) {
        bool ok = 0;
        auto [px, py] = get();
        if (px == -1) break;
        string _, e;
        cin >> _ >> e;
        a[px][py] = 'A';
        // cout << "e: " << e << '\n';
        // cout << "p: " << px << ' ' << py << '\n';
        if (e[3] == 'w') {
            a[px][py] = 'N';
            continue;
        }
        rot(px, e.size() - 9);
        // for (auto x : a) cout << x << '\n';
    }
    // cout << "rs: " << '\n';
    // for (auto x : rs) cout << x << ' ';
    // cout << '\n';
    for (int i = 0; i < n; i++) {
        if (rs[i] == r) cout << i + 1 << '\n';
    }
}