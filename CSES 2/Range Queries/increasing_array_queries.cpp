// CSES Range Queries: Increasing Array Queries

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXB = 20;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> pfs(1, 0);
    for (auto x : a) pfs.push_back(pfs.back() + x);

    vector<vector<pair<int, int>>> bin(n, vector<pair<int, int>>(MAXB + 1));
    stack<pair<int, int>> Q;
    Q.emplace(1e18, n - 1);
    for (int i = n - 1; i >= 0; i--) {
        while (Q.top().f < a[i]) Q.pop();
        bin[i][0] = {Q.top().s, a[i] * (Q.top().s - i)};
        Q.emplace(a[i], i);
    }

    for (int i = 1; i <= MAXB; i++) {
        for (int j = 0; j < n; j++) {
            bin[j][i].f = bin[bin[j][i - 1].f][i - 1].f;
            bin[j][i].s = bin[j][i - 1].s + bin[bin[j][i - 1].f][i - 1].s;
        }
    }

    // for (int i = 0; i < n; i++)
    //     cout << bin[i][0].f << ' ' << bin[i][0].f << ", ";
    // cout << '\n';

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = pfs[l] - pfs[r + 1], c = l;
        // cout << ans << '\n';
        for (int i = MAXB; i >= 0; i--) {
            if (bin[c][i].f < r) ans += bin[c][i].s, c = bin[c][i].f;
        }
        ans += a[c] * (r - c) + max(a[c], a[r]);
        cout << ans << '\n';
    }
}