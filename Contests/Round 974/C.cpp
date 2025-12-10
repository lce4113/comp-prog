// Codeforces Round 974: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), vs;
    for (auto &x : a) cin >> x;
    if (n <= 2) {
        cout << "-1\n";
        return;
    }
    // for (auto x : a) cout << x << ' ';
    // cout << '\n';

    int sm = 0;
    for (auto x : a) vs.push_back(2 * n * x), sm += x;
    sort(vs.begin(), vs.end());
    // for (auto x : vs) cout << x << ' ';
    // cout << '\n';

    int ans = max(vs[n / 2] - sm + 1, 0ll);
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}