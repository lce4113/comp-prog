// Codeforces Round 1034: Problem G

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> ds;
    for (int i = 1; i * i <= m; i++) {
        if (m % i) continue;
        ds.push_back(i);
        if (i * i != m) ds.push_back(m / i);
    }
    map<int, int> mp;
    for (auto x : ds) {
        for (int i = 0; i < n - 1; i++) {
            if (a[i] % x > a[i + 1] % x) mp[x]++;
        }
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, v;
            cin >> k >> v;
            k--;
            for (auto x : ds) {
                if (k - 1 >= 0 && a[k - 1] % x > a[k] % x) mp[x]--;
                if (k + 1 < n && a[k] % x > a[k + 1] % x) mp[x]--;
            }
            a[k] = v;
            for (auto x : ds) {
                if (k - 1 >= 0 && a[k - 1] % x > a[k] % x) mp[x]++;
                if (k + 1 < n && a[k] % x > a[k + 1] % x) mp[x]++;
            }
        } else {
            int k;
            cin >> k;
            int g = gcd(k, m);
            cout << (mp[g] * g + a.back() % g < m ? "YES\n" : "NO\n");
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}