// Codeforces Round 1024: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> ps;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ps.push_back({i * i * (n - i), {i, j}});
        }
    }

    vector<vector<int>> ans(n, vector<int>(n));
    if (n % 2) {
        ans[n / 2][n / 2] = 0;
        for (int i = 1, c = 1; i <= n / 2; i++) {
            for (int j = n / 2 - i + 1; j <= n / 2 + i; j++)
                ans[j][n / 2 + i] = c++;
            for (int j = n / 2 + i - 1; j >= n / 2 - i; j--)
                ans[n / 2 + i][j] = c++;
            for (int j = n / 2 + i - 1; j >= n / 2 - i; j--)
                ans[j][n / 2 - i] = c++;
            for (int j = n / 2 - i + 1; j <= n / 2 + i; j++)
                ans[n / 2 - i][j] = c++;
        }
    } else {
        int hf = n / 2 - 1;
        ans[hf][hf] = 0;
        int c = 1;
        for (int i = 0; i < n / 2; i++) {
            for (int j = hf - i + 1; j <= hf + i; j++) ans[j][hf + i] = c++;
            for (int j = hf + i - 1; j >= hf - i; j--) ans[hf + i][j] = c++;
            for (int j = hf + i - 1; j >= hf - i; j--) ans[j][hf - i] = c++;
            for (int j = hf - i + 1; j <= hf + i; j++) ans[hf - i][j] = c++;
        }
        for (int i = 0; i < n; i++) ans[i][n - 1] = c++;
        for (int i = n - 2; i >= 0; i--) ans[n - 1][i] = c++;
    }

    for (auto x : ans) {
        for (auto y : x) cout << y << ' ';
        cout << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}