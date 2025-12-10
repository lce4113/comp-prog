// CSES Construction Problems: Filling Trominos

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<string> A;

void fill(int x, int y, bool h, int off) {
    if (h) {
        A[x][y] = 'A' + off * 2;
        A[x][y + 1] = 'A' + off * 2;
        A[x][y + 2] = 'B' + off * 2;
        A[x + 1][y] = 'A' + off * 2;
        A[x + 1][y + 1] = 'B' + off * 2;
        A[x + 1][y + 2] = 'B' + off * 2;
    } else {
        A[x][y] = 'A' + off * 2;
        A[x + 1][y] = 'A' + off * 2;
        A[x + 2][y] = 'B' + off * 2;
        A[x][y + 1] = 'A' + off * 2;
        A[x + 1][y + 1] = 'B' + off * 2;
        A[x + 2][y + 1] = 'B' + off * 2;
    }
}

pair<int, int> find(int a, int b, int n) {
    for (int i = 0; i <= n; i += a) {
        if ((n - i) % b) continue;
        return {i, n - i};
    }
    return {-1, -1};
}

void out() {
    cout << "YES\n";
    for (auto x : A) cout << x << '\n';
}

void solve() {
    int n, m;
    cin >> n >> m;
    A.assign(n, string(m, '.'));
    if (n * m % 3) {
        cout << "NO\n";
        return;
    }
    if (n % 2 == 0 && m % 3 == 0) {
        for (int x = 0; x < n; x += 2) {
            for (int y = 0; y < m; y += 3) {
                fill(x, y, 1, (x / 2 + y / 3) % 2);
            }
        }
        out();
        return;
    }
    if (n % 3 == 0 && m % 2 == 0) {
        for (int x = 0; x < n; x += 3) {
            for (int y = 0; y < m; y += 2) {
                fill(x, y, 0, (x / 3 + y / 2) % 2);
            }
        }
        out();
        return;
    }
    if (n % 6 && m % 6) {
        cout << "NO\n";
        return;
    }
    if (n % 6 == 0) {
        auto c = find(2, 3, m);
        if (c.f == -1) {
            cout << "NO\n";
            return;
        }
        for (int x = 0; x < n; x += 2) {
            for (int y = 0; y < c.s; y += 3) {
                fill(x, y, 1, (x / 2 + y / 3) % 2);
            }
        }
        for (int x = 0; x < n; x += 3) {
            for (int y = c.s; y < m; y += 2) {
                fill(x, y, 0, (x / 3 + y / 2) % 2 + 2);
            }
        }
        out();
        return;
    }
    if (m % 6 == 0) {
        auto c = find(2, 3, n);
        if (c.f == -1) {
            cout << "NO\n";
            return;
        }
        for (int x = 0; x < c.f; x += 2) {
            for (int y = 0; y < m; y += 3) {
                fill(x, y, 1, (x / 2 + y / 3) % 2);
            }
        }
        for (int x = c.f; x < n; x += 3) {
            for (int y = 0; y < m; y += 2) {
                fill(x, y, 0, (x / 3 + y / 2) % 2 + 2);
            }
        }
        out();
        return;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}