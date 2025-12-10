// USACO 2025 February Gold
// Problem 2. "The Best Subsequence"

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;

int binexp(int a, int b = MOD - 2) {
    int ans = 1;
    for (; b; a *= a, a %= MOD) {
        if (b % 2) ans *= a, ans %= MOD;
        b /= 2;
    }
    return ans;
}

int H(int a, int b) { return ((2 * a) % MOD + b) % MOD; }
int HI(int a, int b, int l) {
    return (a + MOD - ((b * binexp(2, l)) % MOD)) % MOD;
}

void solve() {
    int n, M, q;
    cin >> n >> M >> q;

    vector<int> zp(n + 1, 0), bin;
    while (M--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        zp[l]++, zp[r + 1]++;
    }
    int c = 1;
    for (int i = 0; i < n; i++) c ^= (zp[i] % 2), bin.push_back(c);

    // for (auto x : bin) cout << x << ' ';
    // cout << '\n';

    vector<int> zpfs(1, 0), hpfs(1, 0);
    for (auto x : bin) zpfs.push_back(zpfs.back() + (x == 0));
    for (auto x : bin) hpfs.push_back(H(hpfs.back(), x));
    // for (auto x : hpfs) cout << x << ' ';
    // cout << '\n';
    // cout << HI(hpfs[5], hpfs[1], 4) << '\n';

    while (q--) {
        int L, R, k;
        cin >> L >> R >> k;
        L--, R--;
        int l = -1, r = k, m = (l + r) / 2;
        for (; r - l > 1; m = (l + r) / 2) {
            if (zpfs[R - m + 1] - zpfs[L] + m >= k) {
                r = m;
            } else {
                l = m;
            }
        }
        // cout << L << ' ' << R << ' ' << k << ' ' << l << ' ' << r << '\n';
        int ans = HI(hpfs[R + 1], hpfs[R - r + 1], r);
        // int shift = (binexp(2, k - r) - 1 + MOD) % MOD;
        // shift *= binexp(2, r), shift %= MOD;
        // ans += shift, ans %= MOD;
        ans = (binexp(2, k) + MOD - ans - 1) % MOD;
        cout << ans << '\n';
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
