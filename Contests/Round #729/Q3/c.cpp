// ––– CodeForces Round #729: Problem C –––

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
using str = string;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

const ll MOD = 1e9 + 7;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    /* n = t; */

    if (n == 1) {
      cout << 2 << '\n';
      continue;
    }

    ll ans = 2 * n, l = 1;
    for (ll i = 2; l <= n; i++) {
      l = lcm(l, i);
      ans += n / l;
      ans %= MOD;
    }

    /* cout << t << ' ' << ans << '\n'; */
    cout << ans << '\n';
  }
}
