// CSES Additional Problems I: Cyclic Array

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5;
const int B = 20;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    a.insert(a.end(), a.begin(), a.end());
    // for (auto x : a) cout << x << ' ';
    // cout << '\n';

    vector<int> pfs(1, 0);
    for (auto x : a) pfs.push_back(pfs.back() + x);
    // for (auto x : pfs) cout << x << ' ';
    // cout << '\n';

    vector<vector<int>> jump(B + 1, vector<int>(2 * MAXN));
    for (int i = 0; i < 2 * n; i++) {
        int p = upper_bound(pfs.begin(), pfs.end(), pfs[i] + k) - pfs.begin();
        jump[0][i] = p - 1;
    }
    for (int i = 1; i <= B; i++) {
        for (int j = 0; j < 2 * n; j++) {
            jump[i][j] =
                jump[i - 1][j] == 2 * n ? 2 * n : jump[i - 1][jump[i - 1][j]];
        }
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        int c = i, dst = 0;
        for (int j = B; j >= 0; j--) {
            if (jump[j][c] < i + n) c = jump[j][c], dst += (1 << j);
        }
        ans = min(ans, dst + 1);
    }
    cout << ans << '\n';
}