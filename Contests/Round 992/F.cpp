// Codeforces Round 992: Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 998244353;
const int MAXN = 3e6;

vector<int> fact(MAXN + 1, 1);
vector<int> fact_inv(MAXN + 1, 1);
vector<int> sieve(MAXN + 1, 1);
vector<int> phi(MAXN + 1, 1);

int binexp(int a, int b = MOD - 2) {
    int ans = 1;
    for (; b; a *= a, a %= MOD) {
        if (b % 2) ans *= a, ans %= MOD;
        b /= 2;
    }
    return ans;
}

void solve() {
    int a, b, c, K;
    cin >> a >> b >> c >> K;
    vector<int> d(K);
    for (auto &x : d) cin >> x;

    int G = d[0];
    for (auto x : d) G = gcd(G, x);

    int cs = a * b * c;
    map<int, int> ns;
    for (int i = 1; i <= a; i++) {
        if (a % i) continue;
        for (int j = 1; j <= b; j++) {
            if (b % j) continue;
            for (int k = 1; k <= c; k++) {
                if (c % k) continue;
                // int A = a / gcd(a, i), B = b / gcd(b, j), C = c / gcd(c, k);
                int A = a / i, B = b / j, C = c / k;
                int N = lcm(A, lcm(B, C));
                if (G % N) continue;
                // cout << i << ' ' << j << ' ' << k << ' ' << N << '\n';
                // cout << a / i * b / j * c / k << '\n';
                ns[N] += phi[A] * phi[B] * phi[C];
                // ns[N]++;
            }
        }
    }
    // cout << '\n';

    // for (auto p : ns) cout << p.f << ' ' << p.s << '\n';

    int ans = 0;
    for (auto p : ns) {
        int i = p.f;
        // cout << i << ": " << ns[i] << '\n';
        int sm = 0;
        for (auto x : d) sm += x / i;
        int comb = fact[sm];
        for (auto x : d) comb = (comb * fact_inv[x / i]) % MOD;
        // cout << comb << ' ' << ns[i] << '\n';
        ans = (ans + comb * ns[i]) % MOD;
    }
    ans = (ans * binexp(cs)) % MOD;

    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;
    fact_inv[MAXN] = binexp(fact[MAXN]);
    for (int i = MAXN - 1; i >= 1; i--)
        fact_inv[i] = (fact_inv[i + 1] * (i + 1)) % MOD;

    for (int i = 2; i <= MAXN; i++) {
        if (sieve[i] != 1) continue;
        for (int j = i; j <= MAXN; j += i) sieve[j] = i;
    }
    // for (int i = 0; i < 100; i++) cout << sieve[i] << ' ';
    // cout << '\n';
    for (int i = 1; i <= MAXN; i++) {
        int x = i, ans = i;
        while (x > 1) {
            int p = sieve[x];
            ans /= p, ans *= p - 1;
            while (x % p == 0) x /= p;
        }
        phi[i] = ans;
    }
    // for (int i = 0; i < 100; i++) cout << phi[i] << ' ';
    // cout << '\n';

    int t = 1;
    cin >> t;
    while (t--) solve();
}