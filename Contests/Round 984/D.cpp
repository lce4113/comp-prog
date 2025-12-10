// Codeforces Round 984: Problem D

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (auto &x : a)
        for (auto &y : x) cin >> y;
    vector<vector<char>> ls;
    for (int i = 0; i < min(n, m) / 2; i++) {
        vector<char> l;
        for (int k = i; k <= m - i - 1; k++) l.push_back(a[i][k]);
        for (int k = i + 1; k <= n - i - 2; k++) l.push_back(a[k][m - 1 - i]);
        for (int k = m - i - 1; k >= i; k--) l.push_back(a[n - i - 1][k]);
        for (int k = n - i - 2; k >= i + 1; k--) l.push_back(a[k][i]);
        ls.push_back(l);
    }
    int ans = 0;
    for (auto l : ls) {
        int N = l.size();
        for (int i = 0; i < N; i++) {
            ans += (l[i] == '1' && l[(i + 1) % N] == '5' &&
                    l[(i + 2) % N] == '4' && l[(i + 3) % N] == '3');
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}