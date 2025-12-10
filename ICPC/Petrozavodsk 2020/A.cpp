// Petrozavodsk 2020: Problem A

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll count_primes(ll n) {
    vector<ll> v;
    for (ll i = 1; i <= n; i = n / (n / i) + 1) v.push_back(n / i);
    reverse(all(v));

    int sq = sqrt(n);
    auto geti = [&](ll x) { return x <= sq ? x - 1 : sz(v) - n / x; };

    vector<ll> dp = v;
    for (ll p = 2, a = 0; p <= sq; p++) {
        if (dp[geti(p)] == dp[geti(p - 1)]) continue;
        a++;
        double inv = 1.0 / p;
        for (int i = sz(v) - 1; i >= 0 && p * p <= v[i]; i--) {
            dp[i] -= dp[geti(v[i] * inv + 1e-9)] - a;
        }
    }

    return dp[geti(n)] - 1;
}

void solve() {
    ll n;
    cin >> n;
    ll ps = count_primes(n) - count_primes(n / 2) + 1;
    ll ans = ps + (n - ps + 1) / 2;
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n = 1e12;
    cout << count_primes(n) << '\n';

    // int t;
    // cin >> t;
    // while (t--) solve();
}