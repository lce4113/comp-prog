// Codeforces Educational Round 177
// Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define s second
#define f first

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (auto &y : a) cin >> y;
    reverse(a.begin(), a.end());
    vector<int> pfs(1, 0);
    for (auto y : a) pfs.push_back(pfs.back() + y);
    if (x > pfs.back() * k) {
        cout << "0\n";
        return;
    }
    int ans = n * (x / pfs.back());
    x %= pfs.back();
    ans += lower_bound(pfs.begin(), pfs.end(), x) - pfs.begin();
    cout << n * k + 1 - ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}