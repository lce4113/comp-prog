// NCPC 2010 Problem B: Connect
// https://codeforces.com/gym/101556/submit
// https://codeforces.com/gym/101556/attachments/download/6037/20102011-acmicpc-nordic-collegiate-programming-contest-ncpc-2010-en.pdf

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int n, m, ans = INT_MAX;
vector<vector<char>> a;

int bfs(int x1, int y1, int x2, int y2) {
    // a[x1][y1] = '-', a[x2][y2] = '-';
    // for (int i = 0; i < n; i++) {
    //     for (int k = 0; k < m; k++) {
    //         cout << a[i][k] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    queue<pair<pair<int, int>, int>> Q;
    if (a[x1][y1] == '#') return -1;
    Q.push({{x1, y1}, 0});
    a[x1][y1] = '#';
    while (Q.size()) {
        auto curr = Q.front();
        // cout << curr.f.f << ' ' << curr.f.s << ' ' << curr.s << '\n';
        Q.pop();
        if (curr.f.f == x2 && curr.f.s == y2) return curr.s;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int xn = curr.f.f + dx[i], yn = curr.f.s + dy[i];
            if (xn >= n || xn < 0) continue;
            if (yn >= m || yn < 0) continue;
            if (a[xn][yn] == '#') continue;
            a[xn][yn] = '#';
            Q.push({{xn, yn}, curr.s + 1});
        }
    }
    return -1;
}

void count(int a1, int b1, int a2, int b2) {
    int C = -1;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (a[i][k] == '#') C++;
        }
    }
    int B = bfs(a1, b1, a2, b2);
    ans = min(ans, B == -1 ? INT_MAX : B + C);
    // cout << (B == -1 ? INT_MAX : B + C) << '\n';
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            a[i][k] = '.';
        }
    }
}

void solve() {
    int x1, y1, x2, y2, a1, a2, b1, b2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> a1 >> b1 >> a2 >> b2;
    // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    n++, m++;

    if (x1 > x2) {
        int tmp = x1;
        x1 = x2, x2 = tmp;
        tmp = y1;
        y1 = y2, y2 = tmp;
    }

    if (a1 > a2) {
        int tmp = a1;
        a1 = a2, a2 = tmp;
        tmp = b1;
        b1 = b2, b2 = tmp;
    }

    if (y1 > b1) {
        int tmp = x1;
        x1 = a1, a1 = tmp;
        tmp = y1;
        y1 = b1, b1 = tmp;
        tmp = x2;
        x2 = a2, a2 = tmp;
        tmp = y2;
        y2 = b2, b2 = tmp;
    }

    for (int i = 0; i < n; i++) {
        a.push_back(vector<char>(m, '.'));
    }

    if (y2 > y1) {
        // x1 < x2, y1 < y2
        // cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << '\n';
        for (int k = x1; k <= x2; k++) {
            for (int i = x1; i <= k; i++) a[i][y1] = '#';
            for (int i = y1; i <= y2; i++) a[k][i] = '#';
            for (int i = k; i <= x2; i++) a[i][y2] = '#';
            count(a1, b1, a2, b2);
        }
    } else {
        // x1 < x2, y1 > y2
        for (int k = x1; k <= x2; k++) {
            for (int i = x1; i <= k; i++) a[i][y2] = '#';
            for (int i = y2; i <= y1; i++) a[k][i] = '#';
            for (int i = k; i <= x2; i++) a[i][y1] = '#';
            count(a1, b1, a2, b2);
        }
    }

    if (b2 > b1) {
        // a1 < a2, b1 < b2
        // cout << a1 << ' ' << a2 << ' ' << b1 << ' ' << b2 << '\n';
        for (int k = a1; k <= a2; k++) {
            for (int i = a1; i <= k; i++) a[i][b1] = '#';
            for (int i = b1; i <= b2; i++) a[k][i] = '#';
            for (int i = k; i <= a2; i++) a[i][b2] = '#';
            count(x1, y1, x2, y2);
        }
    } else {
        // a1 < a2, b1 > b2
        for (int k = a1; k <= a2; k++) {
            for (int i = a1; i <= k; i++) a[i][b2] = '#';
            for (int i = b2; i <= b1; i++) a[k][i] = '#';
            for (int i = k; i <= a2; i++) a[i][b1] = '#';
            count(x1, y1, x2, y2);
        }
    }

    if (ans == INT_MAX) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans << '\n';
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}