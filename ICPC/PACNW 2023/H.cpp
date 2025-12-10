// ICPC Pacific Northwest 2023: Problem H

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a) cin >> x;

    vector<vector<int>> ps(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j][i] == '1') ps[i].push_back(j);
        }
    }

    size_t ans = m + 1;
    for (int i = 0; i < (1 << m); i++) {
        size_t sz = __builtin_popcount(i);
        set<int> ns;
        for (int j = 0; j < m; j++) {
            if ((i & (1 << j)) == 0) continue;
            for (auto x : ps[j]) {
                ns.insert(x);
                if (ns.size() >= sz) goto skip;
            }
        }
        if (ns.size() < sz) ans = min(ans, sz);
    skip:
        continue;
    }

    cout << ans - 1 << '\n';
}
