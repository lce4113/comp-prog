// CSES Advanced Techniques: Corner Subgrid Check

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> a;

void solve(int c) {
    vector<bool> prs(n * n, 0);
    for (int i = 0; i < n; i++) {
        vector<int> ps;
        for (int j = 0; j < n; j++) {
            if (a[i][j] - 'A' == c) ps.push_back(j);
        }
        int k = ps.size();
        for (int x = 0; x < k; x++) {
            for (int y = x + 1; y < k; y++) {
                int nxt = ps[x] * n + ps[y];
                if (prs[nxt]) {
                    cout << "YES\n";
                    return;
                }
                prs[nxt] = 1;
            }
        }
    }
    cout << "NO\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    a.assign(n, "");
    for (auto &x : a) cin >> x;
    for (int c = 0; c < m; c++) solve(c);
}