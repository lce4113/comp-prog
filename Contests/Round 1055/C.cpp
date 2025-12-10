// Codeforces Round 1055: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> pfs(1, 0);
    for (int i = 0; i < n - 1; i++) {
        pfs.push_back(pfs.back() + (a[i + 1] == a[i]));
    }
    vector<vector<int>> ps(2, vector<int>(1, 0));
    for (int i = 0; i < n; i++) {
        ps[0].push_back(ps[0].back() + (a[i] == 0));
        ps[1].push_back(ps[1].back() + (a[i] == 1));
    }
    // for (auto x : pfs) cout << x << ' ';
    // cout << '\n';
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        if ((ps[0][r] - ps[0][l]) % 3 || (ps[1][r] - ps[1][l]) % 3) {
            cout << "-1\n";
            continue;
        }
        int ans = (r - l) / 3;
        if (pfs[r - 1] == pfs[l]) ans++;
        cout << ans << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}