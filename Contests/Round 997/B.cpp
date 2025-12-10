// Codeforces Round 997: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for (auto &x : a)
        for (auto &y : x) cin >> y;

    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cnt[i] += (a[i][j] == '1');
        }
    }

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (ans[j] == -1) cnt[i]--;
            if (cnt[i] == -1) {
                ans[j] = i + 1;
                break;
            }
        }
    }

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}