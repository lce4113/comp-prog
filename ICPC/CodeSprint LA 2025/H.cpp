#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;

int binexp(int a, int b) {
    int res = 1;
    for (; b; a *= a, a %= MOD, b /= 2)
        if (b % 2) res *= a, res %= MOD;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    int ans = 1;
    int dist = a[0] + b[0];
    vector<map<int, int>> mp(dist + 1);

    if (a[0] != b[1] || a[1] != b[0] || a[0] != 0) goto bad;
    for (int i = 0; i < n; i++) {
        if ((a[i] + b[i] - dist) % 2) goto bad;
        if ((a[i] - b[i] + dist) % 2) goto bad;

        int pos = (a[i] - b[i] + dist) / 2;
        int dep = (a[i] + b[i] - dist) / 2;

        if (pos < 0 || pos > dist) goto bad;
        if (dep < 0) goto bad;

        mp[pos][dep]++;
    }

    for (int i = 0; i <= dist; i++) {
        if (mp[i][0] != 1) goto bad;
        for (auto x : mp[i]) {
            if (x.f != 0 && mp[i][x.f - 1] == 0) goto bad;
        }
    }

    for (int i = 0; i <= dist; i++) {
        for (auto x : mp[i]) {
            if (x.f == 0) continue;
            ans *= binexp(mp[i][x.f - 1], x.s), ans %= MOD;
        }
    }

    cout << ans << '\n';
    return;
bad:
    cout << "0\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}