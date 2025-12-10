#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 998244353;

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

    vector<int> mxa(n), mxb(n);
    mxa[0] = 0;
    for (int i = 1; i < n; i++) {
        mxa[i] = (a[i] > a[mxa[i - 1]] ? i : mxa[i - 1]);
    }
    mxb[0] = 0;
    for (int i = 1; i < n; i++) {
        mxb[i] = (b[i] > b[mxb[i - 1]] ? i : mxb[i - 1]);
    }

    for (int i = 0; i < n; i++) {
        auto mxp = max(make_pair(a[mxa[i]], b[i - mxa[i]]),
                       {b[mxb[i]], a[i - mxb[i]]});
        int ans = binexp(2, mxp.f) + binexp(2, mxp.s);
        cout << ans % MOD << ' ';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}