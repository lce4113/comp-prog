// Codeforces Round 997: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 998244353;
const int MAXN = 4e5 + 20;
const int MAXC = 2e5 + 5;

vector<int> fact(MAXN + 1, 1);
vector<int> fact_inv(MAXN + 1, 1);
vector<int> cat(MAXC + 1, 1);

int binexp(int a, int b = MOD - 2) {
    int ans = 1;
    for (; b; a *= a, a %= MOD) {
        if (b % 2) ans *= a, ans %= MOD;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; i++) {
        cin >> a[i].f >> a[i].s;
        mp[a[i]] = a[i].s - a[i].f + 1;
        a[i].s *= -1;
    }
    sort(a.begin(), a.end());

    // for (auto x : mp) cout << x.f.f << ' ' << x.f.s << ' ' << x.s << '\n';
    // for (auto x : a) cout << x.f << ' ' << x.s << '\n';

    set<pair<int, int>> b;
    if (a.size() == 0 || a[0] != make_pair(1ll, -n)) {
        mp[{1, n}] = n;
        b.insert({-n, 1});
    }
    for (int i = 0; i < m; i++) {
        // cout << i << ' ' << a[i].f << ' ' << a[i].s << '\n';
        if (b.size() != 0) {
            auto iv = --b.upper_bound({a[i].s, a[i].f});
            pair<int, int> c = {(iv->s), -(iv->f)};
            // cout << a[i].f << ' ' << a[i].s << ' ' << c.f << ' ' << c.s <<
            // '\n';
            mp[c] -= -a[i].s - a[i].f;
        }
        b.insert({a[i].s, a[i].f});
    }

    int ans = 1;
    for (auto x : mp) {
        // cout << x.f.f << ' ' << x.f.s << ' ' << x.s << '\n';
        ans *= cat[x.s], ans %= MOD;
    }
    cout << ans << '\n';
}

int32_t main() {
    for (int i = 1; i <= MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;
    for (int i = 1; i <= MAXN; i++) fact_inv[i] = binexp(fact[i]);
    for (int i = 1; i <= MAXC; i++) {
        cat[i + 1] = (fact[2 * i] * fact_inv[i + 1]) % MOD;
        cat[i + 1] = (cat[i + 1] * fact_inv[i]) % MOD;
    }

    // for (int i = 1; i <= 10; i++) cout << cat[i] << ' ';
    // cout << '\n';

    int t = 1;
    cin >> t;
    while (t--) solve();
}