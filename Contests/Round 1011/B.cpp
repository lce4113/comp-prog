// Codeforces Round 1011: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<pair<int, int>> ans;
    int j = 0;
    for (int i = 0; i < n; i++, j++) {
        if (a[i] == 0) {
            if (i == n - 1) {
                ans.push_back({j - 1, j});
                j--;
            } else {
                ans.push_back({j, j + 1});
            }
            i++;
        }
    }
    ans.push_back({0, j - 1});

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x.f + 1 << ' ' << x.s + 1 << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}