// CSES Mathematics: Creating Strings II

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 1e6;

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

vector<int> f(MAXN + 1, 1);

int32_t main() {
    for (int i = 1; i <= MAXN; i++) f[i] = f[i - 1] * i, f[i] %= MOD;

    string a;
    cin >> a;
    map<char, int> mp;
    for (auto c : a) mp[c]++;
    int ans = f[a.size()];
    for (auto x : mp) ans *= binexp(f[x.second]), ans %= MOD;
    cout << ans << '\n';
}