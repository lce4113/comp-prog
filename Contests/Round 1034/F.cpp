// Codeforces Round 1034: Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXN = 1e6;
vector<int> lp(MAXN + 1), pr;
vector<int> gp(MAXN + 1);

void solve() {
    int n;
    cin >> n;
    vector<int> ans(n + 1, 1);
    map<int, vector<int>> mp;
    for (int i = 2; i <= n; i++) mp[gp[i]].push_back(i);
    for (auto [_, x] : mp) {
        int m = x.size();
        for (int i = 0; i < m; i++) {
            ans[x[i]] = x[(i + 1) % m];
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i <= MAXN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; pr[j] * i <= MAXN; j++) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }

    for (int j = 0; j < pr.size(); j++) {
        for (int i = 1; pr[j] * i <= MAXN; i++) {
            gp[i * pr[j]] = pr[j];
        }
    }

    // for (int i = 0; i < 20; i++) cout << gp[i] << ' ';
    // cout << '\n';

    int t = 1;
    cin >> t;
    while (t--) solve();
}