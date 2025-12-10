// Columbia Programming Camp
// Spring 2025 Contest #1
// Problem L

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

const int MAXN = 1e6;
vector<int> lp(MAXN + 1), pr;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    vector<int> fs(MAXN + 1);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> ds;
        for (int d = 1; d * d <= a[i]; d++) {
            if (a[i] % d) continue;
            ds.push_back(d);
            if (d * d != a[i]) ds.push_back(a[i] / d);
        }
        sort(ds.begin(), ds.end());
        long long c = 0;
        for (auto d : ds) {
            c += fs[d] * (d - d / lp[d]);
            cout << fs[d] << ' ' << d << '\n';
            fs[d]++;
        }
        c *= n - i - 1;
        ans += c;
        cout << c << '\n';
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i <= MAXN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; pr[j] * i <= MAXN; j++) {
            lp[pr[j] * i] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }

    // for (int i = 0; i < 10; i++) {
    //     cout << pr[i] << '\n';
    // }

    int t = 1;
    cin >> t;
    while (t--) solve();
}