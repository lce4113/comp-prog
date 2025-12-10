// CSES Advanced Graph Problems: Tree Isomorphism II

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> deg1(n), deg2(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        deg1[u]++, deg1[v]++;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        deg2[u]++, deg2[v]++;
    }
    multiset<int> m1(deg1.begin(), deg1.end()), m2(deg2.begin(), deg2.end());
    cout << (m1 == m2 ? "YES\n" : "NO\n");
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}