// CodeForces Round #925: Problem G

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 998244353
#define MAXN 3'000'000

vector<int> inv(MAXN);
vector<int> fact(MAXN);
vector<int> fact_inv(MAXN);

int comb(int n, int k) {
  if (n < 0 || k < 0) return 0ll;
  if (n < k) return 0ll;
  return fact[n] * fact_inv[n - k] % MOD * fact_inv[k] % MOD;
};

void solve() {
  int c1, c2, c3, c4;
  cin >> c1 >> c2 >> c3 >> c4;

  if (abs(c1 - c2) > 1) {
    cout << 0 << '\n';
    return;
  }

  int ans = 0;

  if (c1 == c2) {
    if (c1 == 0) {
      if (c3 > 0 && c4 > 0) {
        cout << 0 << '\n';
        return;
      }
      cout << 1 << '\n';
      return;
    }
    // c1+1 places for c4, c2 places for c3
    ans += comb(c4 + c1, c1) * comb(c3 + c2 - 1, c2 - 1);
    ans %= MOD;
    // c1 places for c4, c2+1 places for c3
    ans += comb(c4 + c1 - 1, c1 - 1) * comb(c3 + c2, c2);
    ans %= MOD;
  }

  if (c1 + 1 == c2) {
    // c2 places for c4, c2 places for c3
    ans += comb(c4 + c2 - 1, c2 - 1) * comb(c3 + c2 - 1, c2 - 1);
    ans %= MOD;
  }

  if (c1 == c2 + 1) {
    // c1 places for c4, c1 places for c3
    ans += comb(c4 + c1 - 1, c1 - 1) * comb(c3 + c1 - 1, c1 - 1);
    ans %= MOD;
  }

  cout << ans << '\n';
}

int32_t main() {
  inv[1] = 1;
  for (int i = 2; i < MAXN; i++) {
    inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
  }
  fact[0] = 1;
  fact_inv[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
  }

  int t;
  cin >> t;
  while (t--) solve();
}
