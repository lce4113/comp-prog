// USACO 2024-25 January Silver
// Problem 1. "Cow Checkups"

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            ans += i * (i + 1) / 2;
            ans += (n - i) * (n - i - 1) / 2;
            // cout << i * (i + 1) / 2 << ' ' << (n - i) * (n - i - 1) / 2 <<
            // '\n';
        }
    }
    // cout << '\n';

    vector<vector<int>> mpi(n + 1);
    vector<vector<int>> mpp(n + 1, vector<int>(1, 0));
    for (int i = 0; i < n; i++) {
        mpi[b[i]].push_back(i + 1);
        mpp[b[i]].push_back(mpp[b[i]].back() + i + 1);
        int p = upper_bound(mpi[a[i]].begin(), mpi[a[i]].end(), n - i) -
                mpi[a[i]].begin();
        ans += mpp[a[i]][p];
        ans += (mpi[a[i]].size() - p) * (n - i);
        // cout << i << ' ' << mpp[a[i]][p] << '\n';
        // cout << i << ' ' << (mpi[a[i]].size() - p) * (n - i) << '\n';
    }
    // cout << '\n';

    vector<vector<int>> mpi2(n + 1);
    vector<vector<int>> mpp2(n + 1, vector<int>(1, 0));
    for (int i = n - 1; i >= 0; i--) {
        int p = upper_bound(mpi2[a[i]].begin(), mpi2[a[i]].end(), i + 1) -
                mpi2[a[i]].begin();
        ans += mpp2[a[i]][p];
        ans += (mpi2[a[i]].size() - p) * (i + 1);
        // cout << i << ' ' << mpp2[a[i]][p] << '\n';
        // cout << i << ' ' << (mpi2[a[i]].size() - p) * (i + 1) << '\n';
        mpi2[b[i]].push_back(n - i);
        mpp2[b[i]].push_back(mpp2[b[i]].back() + n - i);
    }
    // cout << '\n';

    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}