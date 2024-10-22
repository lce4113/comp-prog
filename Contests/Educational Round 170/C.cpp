#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> mp;
    for (auto x : a) mp[x]++;

    int last = -1;
    vector<vector<int>> b;
    vector<int> c;
    for (auto x : mp) {
        if (x.first != last + 1 && last != -1) {
            b.push_back(c);
            c.clear();
            last = -1;
        }
        // cout << x.first << '\n';
        c.push_back(x.second);
        last = x.first;
    }
    b.push_back(c);
    int ans = -1;
    for (auto vec : b) {
        int N = vec.size();
        // cout << N << ' ';
        vector<int> pfs(N + 1, 0);
        for (int i = 0; i < N; i++) {
            pfs[i + 1] = pfs[i] + vec[i];
        }
        if (N < k) ans = max(ans, pfs.back());
        for (int i = k; i <= N; i++) {
            int sum = pfs[i] - pfs[i - k];
            ans = max(ans, sum);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}