// Codeforces Round 956: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    // cout << n << " " << m << '\n';
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a) {
        for (auto &y : x) {
            char z;
            cin >> z;
            y = z - '0';
        }
    }
    vector<vector<int>> b(n, vector<int>(m));
    for (auto &x : b) {
        for (auto &y : x) {
            char z;
            cin >> z;
            y = z - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[i][j] = (b[i][j] - a[i][j] + 3) % 3;
        }
    }
    for (int i = 0; i < n; i++) {
        int sm = 0;
        for (auto &y : b[i]) sm = (sm + y) % 3;
        if (sm != 0) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        int sm = 0;
        for (int j = 0; j < n; j++) sm = (sm + b[j][i]) % 3;
        if (sm != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}