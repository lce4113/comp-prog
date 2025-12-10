#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;
const int MAXN = 1e6;

vector<int> fact(MAXN + 1, 1);
vector<int> fact_inv(MAXN + 1, 1);

int binexp(int a, int b = MOD - 2) {
    int ans = 1;
    for (; b; a *= a, a %= MOD) {
        if (b % 2) ans *= a, ans %= MOD;
        b /= 2;
    }
    return ans;
}

int comb(int n, int r) {
    int ans = fact[n];
    ans *= fact_inv[r], ans %= MOD;
    ans *= fact_inv[n - r], ans %= MOD;
    return ans;
}

void solve() {
    int k, n, l;
    cin >> k >> n >> l;
    string a;
    cin >> a;
    reverse(a.begin(), a.end());
    int o = 0, ans = 1;
    for (auto x : a) {
        if (x == 'O') {
            o++;
        } else {
            ans *= comb(o, k), ans %= MOD;
            o -= k;
        }
    }

    cout << binexp(ans, l) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i, fact[i] %= MOD;
        fact_inv[i] = binexp(fact[i]);
    }

    int t = 1;
    // cin >> t;
    while (t--) solve();
}