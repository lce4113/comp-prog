// Codeforces Round 984: Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int l, r, i, k;

int xr(int n) {
    if (i == 0) return 0;
    int ans = 0, e = 1, c = 0;
    int E = 1 << i;

    for (int K = k; c < i; e *= 2, c++, K /= 2) {
        bool cbit = 0;
        int crem = n % (2 * E);

        // mod down to 2^i
        if (E == 2 && e == 1) {
            if (K % 2 == 0 && crem >= E) cbit ^= 1;
        } else if (K % 2 && crem >= E) {
            cbit ^= 1;
        }
        crem %= E;

        // consider the missing K
        // cout << "asdf: " << cbit << ' ' << crem << ' ' << e << '\n';
        if (E == 2 && e == 1) {
            if (K % 2 && (crem == 1 || crem == 2)) cbit ^= 1;
        } else if (K % 2 && crem >= k) {
            cbit ^= 1;
        }

        if (e == 1) {
            // get rid of last digit case
            crem %= 4;
            if (crem == 1 || crem == 2) cbit ^= 1;
        } else {
            // mod down to e*2
            crem %= e * 2;
            // cout << "asdf: " << cbit << ' ' << crem << ' ' << e << '\n';
            if (crem >= e) cbit ^= (crem - e + 1) % 2;
        }

        if (cbit) ans += e;
    }

    bool bit = 0;
    int rem = n % (2 * e);

    bit ^= (n / (2 * e)) % 2;
    if (rem >= e) {
        rem -= e;
        if (rem >= k) bit ^= 1;
        // cout << "crem: " << cbit << ' ' << crem << ' ' << e << '\n';
        bit ^= (rem + 1) % 2;
    }

    if (bit) ans += e;
    c++, e *= 2;

    for (; c <= 60; e *= 2, c++) {
        bool cbit = 0;
        int crem = n % (2 * e);

        // cout << "asdf: " << c << ' ' << i << ' ' << n << ' ' << e << '\n';
        if (crem < e) continue;

        // mod E
        crem %= 2 * E;
        if (crem >= E) crem -= E, cbit ^= 1;
        // consider the missing K
        if (crem >= k) cbit ^= 1;
        // cout << "crem: " << cbit << ' ' << crem << ' ' << e << '\n';
        cbit ^= (crem + 1) % 2;

        if (cbit) ans += e;
    }
    return ans;
}

void solve() {
    cin >> l >> r >> i >> k;
    // cout << l << ' ' << r << ' ' << i << ' ' << k << '\n';
    // for (int x = 0; x <= 32; x++) cout << x << ' ' << xr(x) << '\n';
    int ans = xr(l - 1) ^ xr(r);
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}