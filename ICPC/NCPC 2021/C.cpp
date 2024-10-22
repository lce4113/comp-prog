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

int hash1(vector<int> a) {
    int x = 1, ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * x, ans %= MOD;
        x *= P, x %= MOD;
    }
    return ans;
}

int hash2(vector<int> a) {
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= P - (a[i] % MOD), ans %= MOD;
    }
    return ans;
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    cout << binexp(2, 10) << '\n';
}