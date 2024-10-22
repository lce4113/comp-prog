#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 9;
const int P = 998244353;

int binexp(int a, int b = MOD - 2) {
    int ans = 1;
    for (; b > 0; a = (a * a) % MOD) {
        if (b % 2) ans *= a, ans %= MOD;
        b /= 2;
    }
    return ans;
}

int H(int h, int x) {
    int ans = h;
    ans *= P - (x % MOD), ans %= MOD;
    return ans;
}

int H_inv(int h, int x) {
    int ans = h;
    ans *= binexp(P - (x % MOD)), ans %= MOD;
    return ans;
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int h = 1;
    map<int, int> h_table;
    for (int i = 0; i < n; i++) {
        h = H(h, a[i]);
        h = H_inv(h, b[i]);
        h_table[h]++;
    }
    int ans = 0;
    for (auto x : h_table) {
        // cout << x.second << '\n';
        ans += binexp(2, x.second) - x.second - 1;
    }
    cout << ans << '\n';
}