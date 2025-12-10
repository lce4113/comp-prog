// CSES Additional Problems I: Subarray Sum Constraints

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> rs, rs2;
    vector<pair<int, int>> jump(n);
    for (int i = 0; i < n; i++) jump[i] = {i, 0};
    for (int i = 0; i < m; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        l--, r--;
        jump[r] = {l - 1, v};
        rs.push_back({r, l, v});
    }
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < n; j++) {
            jump[r] = {jump[jump[r]], jump[r].s + jump[jump[r].f].s};
        }
    }
    for (auto c : rs) {
        auto [r, l, v] = c;
        int r2 = jump[r].f + 1;
        int v2 = v - jump[r].s;
        rs2.push_back({r2, l, v2});
    }
    swap(rs, rs2);
    sort(rs.begin(), rs.end());
    vector<int> pfs(1, 0), ans(n);
    for (int i = 0, j = 0; i < n && j < m; i++) {
        if (rs[j][0] == i) {
            ans[i] = rs[j][2] - (pfs.back() - pfs[rs[j][1]]);
            j++;
        }
        pfs.push_back(pfs.back() + ans[i]);
    }
    cout << "YES\n";
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}