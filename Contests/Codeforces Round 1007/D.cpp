// Codeforces Round 1007: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

vector<int> a, xp;
int n;

int calc(int l, int r) {
    if (l % 2 == 0)
        if (num <= n) return a[num - 1];
    if (num / 2 <= n) return xp[num / 2];
    if ((num / 2) % 2) return xp[n];
    return xp[n] ^ calc(num / 2);
}

void solve() {
    int l, r;
    cin >> n >> l >> r;
    a.clear(), a.assign(n, 0);
    xp.clear(), xp.assign(1, 0);
    for (auto &x : a) {
        cin >> x;
        xp.push_back(xp.back() ^ x);
    }
    if (n % 2 == 0) {
        a.push_back(xp[n / 2]);
        xp.push_back(xp.back() ^ a.back());
        n++;
    }
    // int ans = 0;
    // if (r <= n) ans ^= xp[n] ^ xp[r + 1], r = n + 1;
    // if (l <= n) ans ^= xp[n] ^ xp[l], l = n;

    // if (l % 2) ans ^= calc(l);
    // if (r % 2 == 0) ans ^= calc(r);
    // cout << ans << '\n';
    cout << calc(l) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}