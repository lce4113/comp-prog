// Codeforces Educational Round 174
// Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;
const int P = 998244353;

int binexp(int a, int b = MOD - 2) {
    int ans = 1;
    for (; b; a *= a, a %= MOD) {
        if (b % 2) ans *= a, ans %= MOD;
        b /= 2;
    }
    return ans;
}

int H(int h, int v) { return (((h * P) % MOD) + v) % MOD; }
int H_inv(int h, int hi, int len) {
    return (h - (hi * binexp(P, len)) % MOD + MOD) % MOD;
}
int Hr(vector<int> pfs, int l, int r) { return H_inv(pfs[r], pfs[l], r - l); }

bool pal(string a) {
    int n = a.size();
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - 1 - i]) return false;
    }
    return true;
}

void solve() {
    string a;
    cin >> a;
    // cout << a << ' ';
    int n = a.size();
    int l = 0;
    while (l < n / 2 && a[l] == a[n - 1 - l]) l++;
    if (l == n / 2) {
        cout << "0\n";
        return;
    }
    n -= 2 * l;
    a = a.substr(l, n);

    vector<int> hpfs(1, 0), hipfs(1, 0);
    for (auto x : a) hpfs.push_back(H(hpfs.back(), (x - 'a')));
    reverse(a.begin(), a.end());
    for (auto x : a) hipfs.push_back(H(hipfs.back(), (x - 'a')));
    reverse(a.begin(), a.end());

    // for (auto x : hpfs) cout << x << ' ';
    // cout << '\n';
    // for (auto x : hipfs) cout << x << ' ';
    // cout << '\n';

    int R = n / 2 - 1;
    while (R >= 0 && a[R] == a[n - 1 - R]) R--;
    R++;

    // cout << a << ' ' << R << '\n';
    // cout << 0 << ' ' << R << ' ' << n - R << ' ' << n << '\n';
    // cout << Hr(hpfs, 0, R) << ' ' << Hr(hpfs, n - R, n) << '\n';
    if (Hr(hpfs, 0, R) == Hr(hpfs, n - R, n)) {
        cout << R << '\n';
        return;
    }

    int r = n / 2;
    while (r > 0 && (Hr(hpfs, 0, r) != Hr(hpfs, r, 2 * r) ||
                     Hr(hpfs, 2 * r, n / 2 + r) != Hr(hipfs, 0, n / 2 - r)))
        r--;
    cout << r << '\n';
    int ans = n - r;

    r = n / 2;
    while (r > 0 && (Hr(hpfs, n - r, n) != Hr(hpfs, n - 2 * r, n - r) ||
                     Hr(hpfs, n / 2 - r, n - 2 * r) != Hr(hipfs, n / 2 + r, n)))
        r--;
    cout << r << '\n';
    ans = min(ans, n - r);

    // cout << n / 2 << ' ' << l << ' ' << r << '\n';
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}