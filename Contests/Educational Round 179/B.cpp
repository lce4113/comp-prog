// Educational Codeforces Round 179: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a(m);
    for (auto &x : a) cin >> x[0] >> x[1] >> x[2];
    vector<int> f(n);
    f[0] = 1, f[1] = 2;
    for (int i = 2; i < n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    // for (auto x : f) cout << x << ' ';
    // cout << '\n';
    for (auto x : a) {
        priority_queue<int> Q;
        Q.push(x[0]), Q.push(x[1]), Q.push(x[2]);
        bool ok = 1;
        int mn = *min_element(x.begin(), x.end());
        for (int i = n - 1; i >= 0; i--) {
            auto y = Q.top();
            Q.pop();
            // cout << y << ' ' << f[i] << '\n';
            if (mn < f[i]) {
                ok = 0;
                break;
            }
            Q.push(y - f[i]);
            mn = min(y - f[i], mn);
        }
        cout << ok;
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}