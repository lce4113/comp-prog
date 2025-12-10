// Codeforces Pinely Round 5: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n;

bool check(vector<string> &a, vector<string> &b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '#' && b[i][j] == '.') {
                return 0;
            }
        }
    }
    return 1;
}

void solve() {
    cin >> n;
    vector<string> a(n), b;
    for (auto &x : a) cin >> x;
    b = a;
    int bs = -1, bd = -1;
    vector<pair<int, int>> B;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '#') {
                bs = i + j, bd = i - j;
                B.push_back({i, j});
            }
        }
    }
    if (bs == -1) {
        cout << "YES\n";
        return;
    }
    if (B.size() == 4) {
        int bx = B[0].f, by = B[0].s;
        if (B[1].f == bx && B[1].s == by + 1 && B[2].f == bx + 1 &&
            B[2].s == by && B[3].f == bx + 1 && B[3].s == by + 1) {
            cout << "YES\n";
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = '.';
            if (i + j == bs || i + j == bs - 1) {
                b[i][j] = '#';
            }
        }
    }
    if (check(a, b)) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = '.';
            if (i + j == bs || i + j == bs + 1) {
                b[i][j] = '#';
            }
        }
    }
    if (check(a, b)) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = '.';
            if (i - j == bd || i - j == bd - 1) {
                b[i][j] = '#';
            }
        }
    }
    if (check(a, b)) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = '.';
            if (i - j == bd || i - j == bd + 1) {
                b[i][j] = '#';
            }
        }
    }
    if (check(a, b)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}