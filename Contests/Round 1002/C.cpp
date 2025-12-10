// Codeforces Round 1002: Problem C
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &x : a)
        for (auto &y : x) cin >> y;

    vector<int> x;
    for (int r = 0; r < n; r++) {
        int c = 0;
        for (int i = n - 1; i >= 0; i--) {
            // cout << r << ' ' << i << ' ' << a[r][i] << ' ';
            if (a[r][i] == 1)
                c++;
            else
                break;
        }
        // cout << '\n';
        x.push_back(c);
    }

    sort(x.begin(), x.end());
    // for (auto y : x) cout << y << ' ';
    // cout << '\n';

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] >= c) c++;
    }
    cout << c << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}