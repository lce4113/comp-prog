// CSES Construction Problems: Inverse Inversions

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> ans(n);
    int c = n - 1, v = 1;
    while (m > c) ans[c] = v++, m -= c--;
    ans[m] = v++;
    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) ans[i] = v++;
    }

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}